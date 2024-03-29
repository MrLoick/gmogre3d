/***********************************************************************
    filename:   CEGUIFont.cpp
    created:    21/2/2004
    author:     Paul D Turner

    purpose:    Implements FreeTypeFont class
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2006 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#include "CEGUIFreeTypeFont.h"
#include "CEGUIExceptions.h"
#include "CEGUITexture.h"
#include "CEGUIImageset.h"
#include "CEGUIImagesetManager.h"
#include "CEGUILogger.h"
#include "CEGUIPropertyHelper.h"
#include "CEGUIFont_xmlHandler.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

namespace CEGUI
{
//----------------------------------------------------------------------------//
// Pixels to put between glyphs
#define INTER_GLYPH_PAD_SPACE 2
// A multiplication coefficient to convert FT_Pos values into normal floats
#define FT_POS_COEF  (1.0/64.0)

//----------------------------------------------------------------------------//
// Font objects usage count
static int ft_usage_count = 0;
// A handle to the FreeType library
static FT_Library ft_lib;

//----------------------------------------------------------------------------//
#undef __FTERRORS_H__
#define FT_ERRORDEF( e, v, s ) s,
#define FT_ERROR_START_LIST static const char* ft_errors[] = {
#define FT_ERROR_END_LIST 0};
#include FT_ERRORS_H

//----------------------------------------------------------------------------//
FreeTypeFont::FreeTypeFont(const String& font_name, const float point_size,
                           const bool anti_aliased, const String& font_filename,
                           const String& resource_group, const bool auto_scaled,
                           const float native_horz_res,
                           const float native_vert_res) :
    Font(font_name, Font_xmlHandler::FontTypeFreeType, font_filename,
         resource_group, auto_scaled, native_horz_res, native_vert_res),
    d_ptSize(point_size),
    d_antiAliased(anti_aliased),
    d_fontFace(0)
{
    if (!ft_usage_count++)
        FT_Init_FreeType(&ft_lib);

    addFreeTypeFontProperties();

    updateFont();

    char tmp[50];
    snprintf(tmp, sizeof(tmp), "Succsessfully loaded %d glyphs",
             static_cast<int>(d_cp_map.size()));
    Logger::getSingleton().logEvent(tmp, Informative);
}

//----------------------------------------------------------------------------//
FreeTypeFont::~FreeTypeFont()
{
    free();

    if (!--ft_usage_count)
        FT_Done_FreeType(ft_lib);
}

//----------------------------------------------------------------------------//
uint FreeTypeFont::getTextureSize(CodepointMap::const_iterator s,
                                  CodepointMap::const_iterator e) const
{
    uint texsize = 32; // start with 32x32
    uint max_texsize = System::getSingleton().getRenderer()->getMaxTextureSize();
    uint glyph_count = 0;

    // Compute approximatively the optimal texture size for font
    while (texsize < max_texsize)
    {
        uint x = INTER_GLYPH_PAD_SPACE, y = INTER_GLYPH_PAD_SPACE;
        uint yb = INTER_GLYPH_PAD_SPACE;
        for (CodepointMap::const_iterator c = s; c != e; ++c)
        {
            // skip glyphs that are already rendered
            if (c->second.getImage())
                continue;

            // load glyph metrics (don't render)
            if (FT_Load_Char(d_fontFace, c->first,
                             FT_LOAD_DEFAULT | FT_LOAD_FORCE_AUTOHINT))
                continue;

            uint glyph_w = int (ceil(d_fontFace->glyph->metrics.width * FT_POS_COEF)) +
                           INTER_GLYPH_PAD_SPACE;
            uint glyph_h = int (ceil(d_fontFace->glyph->metrics.height * FT_POS_COEF)) +
                           INTER_GLYPH_PAD_SPACE;

            x += glyph_w;
            if (x > texsize)
            {
                x = INTER_GLYPH_PAD_SPACE;
                y = yb;
            }
            uint yy = y + glyph_h;
            if (yy > texsize)
                goto too_small;

            if (yy > yb)
                yb = yy;

            ++glyph_count;
        }
        // Okay, the texture size is enough for holding our glyphs
        break;

    too_small:
        texsize *= 2;
    }

    return glyph_count ? texsize : 0;
}

//----------------------------------------------------------------------------//
void FreeTypeFont::rasterise(utf32 start_codepoint, utf32 end_codepoint) const
{
    CodepointMap::const_iterator s = d_cp_map.lower_bound(start_codepoint);
    if (s == d_cp_map.end())
        return;

    CodepointMap::const_iterator orig_s = s;
    CodepointMap::const_iterator e = d_cp_map.upper_bound(end_codepoint);
    while (true)
    {
        // Create a new Imageset for glyphs
        uint texsize = getTextureSize(s, e);
        // If all glyphs were already rendered, do nothing
        if (!texsize)
            break;

        Imageset& is = ImagesetManager::getSingleton().create(
                           d_name + "_auto_glyph_images_" + int (s->first),
                           System::getSingleton().getRenderer()->createTexture());
        d_glyphImages.push_back(&is);

        // Create a memory buffer where we will render our glyphs
        argb_t *mem_buffer = new argb_t [texsize * texsize];
        memset(mem_buffer, 0, texsize * texsize * sizeof(argb_t));

        // Go ahead, line by line, top-left to bottom-right
        uint x = INTER_GLYPH_PAD_SPACE, y = INTER_GLYPH_PAD_SPACE;
        uint yb = INTER_GLYPH_PAD_SPACE;

        // Set to true when we finish rendering all glyphs we were asked to
        bool finished = false;
        // Set to false when we reach d_cp_map.end() and we start going backward
        bool forward = true;

        /* To conserve texture space we will render more glyphs than asked,
         * but never less than asked. First we render all glyphs from s to e
         * and after that we render glyphs until we reach d_cp_map.end(),
         * and if there's still free texture space we will go backward
         * from s until we hit d_cp_map.begin().
         */
        while (s != d_cp_map.end())
        {
            // Check if we finished rendering all the required glyphs
            finished |= (s == e);

            // Check if glyph already rendered
            if (!s->second.getImage())
            {
                // Render the glyph
                if (FT_Load_Char(d_fontFace, s->first, FT_LOAD_RENDER | FT_LOAD_FORCE_AUTOHINT |
                                 (d_antiAliased ? FT_LOAD_TARGET_NORMAL : FT_LOAD_TARGET_MONO)))
                {
                    std::stringstream err;
                    err << "Font::loadFreetypeGlyph - Failed to load glyph for codepoint: ";
                    err << static_cast<unsigned int>(s->first);
                    err << ".  Will use an empty image for this glyph!";
                    Logger::getSingleton().logEvent(err.str(), Errors);

                    // Create a 'null' image for this glyph so we do not seg later
                    Rect area(0, 0, 0, 0);
                    Point offset(0, 0);
                    String name;
                    name += s->first;
                    is.defineImage(name, area, offset);
                    ((FontGlyph &)s->second).setImage(&is.getImage(name));
                }
                else
                {
                    uint glyph_w = d_fontFace->glyph->bitmap.width + INTER_GLYPH_PAD_SPACE;
                    uint glyph_h = d_fontFace->glyph->bitmap.rows + INTER_GLYPH_PAD_SPACE;

                    // Check if glyph right margin does not exceed texture size
                    uint x_next = x + glyph_w;
                    if (x_next > texsize)
                    {
                        x = INTER_GLYPH_PAD_SPACE;
                        x_next = x + glyph_w;
                        y = yb;
                    }

                    // Check if glyph bottom margine does not exceed texture size
                    uint y_bot = y + glyph_h;
                    if (y_bot > texsize)
                        break;

                    // Copy rendered glyph to memory buffer in RGBA format
                    drawGlyphToBuffer(mem_buffer + (y * texsize) + x, texsize);

                    // Create a new image in the imageset
                    Rect area(static_cast<float>(x),
                              static_cast<float>(y),
                              static_cast<float>(x + glyph_w - INTER_GLYPH_PAD_SPACE),
                              static_cast<float>(y + glyph_h - INTER_GLYPH_PAD_SPACE));

                    Point offset(d_fontFace->glyph->metrics.horiBearingX * static_cast<float>(FT_POS_COEF),
                                 -d_fontFace->glyph->metrics.horiBearingY * static_cast<float>(FT_POS_COEF));

                    String name;
                    name += s->first;
                    is.defineImage(name, area, offset);
                    ((FontGlyph &)s->second).setImage(&is.getImage(name));

                    // Advance to next position
                    x = x_next;
                    if (y_bot > yb)
                    {
                        yb = y_bot;
                    }
                }
            }

            // Go to next glyph, if we are going forward
            if (forward)
                if (++s == d_cp_map.end())
                {
                    finished = true;
                    forward = false;
                    s = orig_s;
                }
            // Go to previous glyph, if we are going backward
            if (!forward)
                if ((s == d_cp_map.begin()) || (--s == d_cp_map.begin()))
                    break;
        }

        // Copy our memory buffer into the texture and free it
        is.getTexture()->loadFromMemory(mem_buffer, Size(texsize, texsize), Texture::PF_RGBA);
        delete [] mem_buffer;

        if (finished)
            break;
    }
}

//----------------------------------------------------------------------------//
void FreeTypeFont::drawGlyphToBuffer(argb_t *buffer, uint buf_width) const
{
    FT_Bitmap *glyph_bitmap = &d_fontFace->glyph->bitmap;

    for (int i = 0; i < glyph_bitmap->rows; ++i)
    {
        uchar *src = glyph_bitmap->buffer + (i * glyph_bitmap->pitch);
        switch (glyph_bitmap->pixel_mode)
        {
        case FT_PIXEL_MODE_GRAY:
        {
            uchar *dst = reinterpret_cast<uchar*>(buffer);
            for (int j = 0; j < glyph_bitmap->width; ++j)
            {
                // RGBA
                *dst++ = 0xFF;
                *dst++ = 0xFF;
                *dst++ = 0xFF;
                *dst++ = *src++;
            }
        }
        break;

        case FT_PIXEL_MODE_MONO:
            for (int j = 0; j < glyph_bitmap->width; ++j)
                buffer [j] = (src [j / 8] & (0x80 >> (j & 7))) ? 0xFFFFFFFF : 0x00000000;
            break;

        default:
            throw InvalidRequestException("Font::drawGlyphToBuffer: "
                "The glyph could not be drawn because the pixel mode is "
                "unsupported.");
            break;
        }

        buffer += buf_width;
    }
}

//----------------------------------------------------------------------------//
void FreeTypeFont::free()
{
    if (!d_fontFace)
        return;

    d_cp_map.clear();

    for (size_t i = 0; i < d_glyphImages.size(); i++)
        ImagesetManager::getSingleton().destroy(d_glyphImages [i]->getName());
    d_glyphImages.clear();

    FT_Done_Face(d_fontFace);
    d_fontFace = 0;
    System::getSingleton().getResourceProvider()->unloadRawDataContainer(d_fontData);
}

//----------------------------------------------------------------------------//
void FreeTypeFont::updateFont()
{
    free();

    System::getSingleton().getResourceProvider()->loadRawDataContainer(
        d_filename, d_fontData, d_resourceGroup.empty() ?
            getDefaultResourceGroup() : d_resourceGroup);

    FT_Error error;

    // create face using input font
    if ((error = FT_New_Memory_Face(ft_lib, d_fontData.getDataPtr(),
                           static_cast<FT_Long>(d_fontData.getSize()), 0,
                           &d_fontFace)) != 0)
        throw GenericException("FreeTypeFont::updateFont: Failed to create "
            "face from font file '" + d_filename + "' error was: " +
            ((error < FT_Err_Max) ? ft_errors[error] : "unknown error"));

    // check that default Unicode character map is available
    if (!d_fontFace->charmap)
    {
        FT_Done_Face(d_fontFace);
        d_fontFace = 0;
        throw GenericException("FreeTypeFont::updateFont: "
            "The font '" + d_name + "' does not have a Unicode charmap, and "
            "cannot be used.");
    }

    uint horzdpi = System::getSingleton().getRenderer()->getDisplayDPI().d_x;
    uint vertdpi = System::getSingleton().getRenderer()->getDisplayDPI().d_y;

    float hps = d_ptSize * 64;
    float vps = d_ptSize * 64;
    if (d_autoScale)
    {
        hps *= d_horzScaling;
        vps *= d_vertScaling;
    }

    if (FT_Set_Char_Size(d_fontFace, FT_F26Dot6(hps), FT_F26Dot6(vps), horzdpi, vertdpi))
    {
        // For bitmap fonts we can render only at specific point sizes.
        // Try to find nearest point size and use it, if that is possible
        float ptSize_72 = (d_ptSize * 72.0f) / vertdpi;
        float best_delta = 99999;
        float best_size = 0;
        for (int i = 0; i < d_fontFace->num_fixed_sizes; i++)
        {
            float size = d_fontFace->available_sizes [i].size * float(FT_POS_COEF);
            float delta = fabs(size - ptSize_72);
            if (delta < best_delta)
            {
                best_delta = delta;
                best_size = size;
            }
        }

        if ((best_size <= 0) ||
                FT_Set_Char_Size(d_fontFace, 0, FT_F26Dot6(best_size * 64), 0, 0))
        {
            char size [20];
            snprintf(size, sizeof(size), "%g", d_ptSize);
            throw GenericException("FreeTypeFont::load - The font '" + d_name + "' cannot be rasterised at a size of " + size + " points, and cannot be used.");
        }
    }

    if (d_fontFace->face_flags & FT_FACE_FLAG_SCALABLE)
    {
        //float x_scale = d_fontFace->size->metrics.x_scale * FT_POS_COEF * (1.0/65536.0);
        float y_scale = d_fontFace->size->metrics.y_scale * float(FT_POS_COEF) * (1.0f / 65536.0f);
        d_ascender = d_fontFace->ascender * y_scale;
        d_descender = d_fontFace->descender * y_scale;
        d_height = d_fontFace->height * y_scale;
    }
    else
    {
        d_ascender = d_fontFace->size->metrics.ascender * float(FT_POS_COEF);
        d_descender = d_fontFace->size->metrics.descender * float(FT_POS_COEF);
        d_height = d_fontFace->size->metrics.height * float(FT_POS_COEF);
    }

    // Create an empty FontGlyph structure for every glyph of the font
    FT_UInt gindex;
    FT_ULong codepoint = FT_Get_First_Char(d_fontFace, &gindex);
    FT_ULong max_codepoint = codepoint;
    while (gindex)
    {
        if (max_codepoint < codepoint)
            max_codepoint = codepoint;

        // load-up required glyph metrics (don't render)
        if (FT_Load_Char(d_fontFace, codepoint,
                         FT_LOAD_DEFAULT | FT_LOAD_FORCE_AUTOHINT))
            continue; // glyph error

        float adv = d_fontFace->glyph->metrics.horiAdvance * float(FT_POS_COEF);

        // create a new empty FontGlyph with given character code
        d_cp_map[codepoint] = FontGlyph(adv);

        // proceed to next glyph
        codepoint = FT_Get_Next_Char(d_fontFace, codepoint, &gindex);
    }

    setMaxCodepoint(max_codepoint);
}

//----------------------------------------------------------------------------//
void FreeTypeFont::writeXMLToStream_impl(XMLSerializer& xml_stream) const
{
    xml_stream.attribute(Font_xmlHandler::FontSizeAttribute,
                         PropertyHelper::floatToString(d_ptSize));
    if (!d_antiAliased)
        xml_stream.attribute(Font_xmlHandler::FontAntiAliasedAttribute, "False");
}

//----------------------------------------------------------------------------//
float FreeTypeFont::getPointSize() const
{
    return d_ptSize;
}

//----------------------------------------------------------------------------//
bool FreeTypeFont::isAntiAliased() const
{
    return d_antiAliased;
}

//----------------------------------------------------------------------------//
void FreeTypeFont::setPointSize(const float point_size)
{
    if (point_size == d_ptSize)
        return;

    d_ptSize = point_size;
    updateFont();
}

//----------------------------------------------------------------------------//
void FreeTypeFont::setAntiAliased(const bool anti_alaised)
{
    if (anti_alaised == d_antiAliased)
        return;

    d_antiAliased = anti_alaised;
    updateFont();
}

//----------------------------------------------------------------------------//

} // End of  CEGUI namespace section
