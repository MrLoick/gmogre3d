/***********************************************************************
    filename:   CEGUIDirect3D9Renderer.cpp
    created:    Mon Feb 9 2009
    author:     Paul D Turner
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2009 Paul D Turner & The CEGUI Development Team
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
#define NOMINMAX
#include "CEGUIDirect3D9Renderer.h"
#include "CEGUIDirect3D9Texture.h"
#include "CEGUIDirect3D9GeometryBuffer.h"
#include "CEGUIDirect3D9RenderTarget.h"
#include "CEGUIRenderingRoot.h"
#include "CEGUIExceptions.h"
#include "CEGUIDirect3D9ViewportTarget.h"
#include "CEGUIDirect3D9TextureTarget.h"
#include "CEGUISystem.h"

#include <algorithm>

// Start of CEGUI namespace section
namespace CEGUI
{
//----------------------------------------------------------------------------//
String Direct3D9Renderer::d_rendererID(
"CEGUI::Direct3D9Renderer - Official Direct3D 9 based 2nd generation renderer "
"module.");

//----------------------------------------------------------------------------//
static const D3DMATRIX s_identityMatrix =
{
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0
};

//----------------------------------------------------------------------------//
Direct3D9Renderer& Direct3D9Renderer::create(LPDIRECT3DDEVICE9 device)
{
    return *new Direct3D9Renderer(device);
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::destroy(Direct3D9Renderer& renderer)
{
    delete &renderer;
}

//----------------------------------------------------------------------------//
RenderingRoot& Direct3D9Renderer::getDefaultRenderingRoot()
{
    return *d_defaultRoot;
}

//----------------------------------------------------------------------------//
GeometryBuffer& Direct3D9Renderer::createGeometryBuffer()
{
    Direct3D9GeometryBuffer* b = new Direct3D9GeometryBuffer(d_device);
    d_geometryBuffers.push_back(b);
    return *b;
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::destroyGeometryBuffer(const GeometryBuffer& buffer)
{
    GeometryBufferList::iterator i = std::find(d_geometryBuffers.begin(),
                                     d_geometryBuffers.end(),
                                     &buffer);

    if (d_geometryBuffers.end() != i)
    {
        d_geometryBuffers.erase(i);
        delete &buffer;
    }
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::destroyAllGeometryBuffers()
{
    while (!d_geometryBuffers.empty())
        destroyGeometryBuffer(**d_geometryBuffers.begin());
}

//----------------------------------------------------------------------------//
TextureTarget* Direct3D9Renderer::createTextureTarget()
{
    TextureTarget* t = new Direct3D9TextureTarget(*this);
    d_textureTargets.push_back(t);
    return t;
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::destroyTextureTarget(TextureTarget* target)
{
    TextureTargetList::iterator i = std::find(d_textureTargets.begin(),
                                    d_textureTargets.end(),
                                    target);

    if (d_textureTargets.end() != i)
    {
        d_textureTargets.erase(i);
        delete target;
    }
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::destroyAllTextureTargets()
{
    while (!d_textureTargets.empty())
        destroyTextureTarget(*d_textureTargets.begin());
}

//----------------------------------------------------------------------------//
Texture& Direct3D9Renderer::createTexture()
{
    Direct3D9Texture* tex = new Direct3D9Texture(*this);
    d_textures.push_back(tex);
    return *tex;
}

//----------------------------------------------------------------------------//
Texture& Direct3D9Renderer::createTexture(const String& filename,
        const String& resourceGroup)
{
    Direct3D9Texture* tex = new Direct3D9Texture(*this, filename,
            resourceGroup);
    d_textures.push_back(tex);
    return *tex;
}

//----------------------------------------------------------------------------//
Texture& Direct3D9Renderer::createTexture(const Size& size)
{
    Direct3D9Texture* tex = new Direct3D9Texture(*this, size);
    d_textures.push_back(tex);
    return *tex;
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::destroyTexture(Texture& texture)
{
    TextureList::iterator i = std::find(d_textures.begin(),
                                        d_textures.end(),
                                        &texture);

    if (d_textures.end() != i)
    {
        d_textures.erase(i);
        delete &static_cast<Direct3D9Texture&>(texture);
    }
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::destroyAllTextures()
{
    while (!d_textures.empty())
        destroyTexture(**d_textures.begin());
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::beginRendering()
{
    d_device->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

    // no shaders initially
    d_device->SetVertexShader(0);
    d_device->SetPixelShader(0);

    // set device states
    d_device->SetRenderState(D3DRS_LIGHTING, FALSE);
    d_device->SetRenderState(D3DRS_FOGENABLE, FALSE);
    d_device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
    d_device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
    d_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    d_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
    d_device->SetRenderState(D3DRS_SCISSORTESTENABLE, TRUE);
    d_device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

    // setup texture addressing settings
    d_device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
    d_device->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);

    // setup colour calculations
    d_device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
    d_device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
    d_device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

    // setup alpha calculations
    d_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
    d_device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
    d_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

    // setup filtering
    d_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
    d_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

    // disable texture stages we do not need.
    d_device->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);

    // setup scene alpha blending
    d_device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    d_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    d_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

    // set view matrix back to identity.
    d_device->SetTransform(D3DTS_VIEW, &s_identityMatrix);
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::endRendering()
{
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::setDisplaySize(const Size& sz)
{
    if (sz != d_displaySize)
    {
        d_displaySize = sz;

        // FIXME: This is probably not the right thing to do in all cases.
        Rect area(d_defaultTarget->getArea());
        area.setSize(sz);
        d_defaultTarget->setArea(area);
    }
}

//----------------------------------------------------------------------------//
const Size& Direct3D9Renderer::getDisplaySize() const
{
    return d_displaySize;
}

//----------------------------------------------------------------------------//
const Vector2& Direct3D9Renderer::getDisplayDPI() const
{
    return d_displayDPI;
}

//----------------------------------------------------------------------------//
uint Direct3D9Renderer::getMaxTextureSize() const
{
    return d_maxTextureSize;
}

//----------------------------------------------------------------------------//
const String& Direct3D9Renderer::getIdentifierString() const
{
    return d_rendererID;
}

//----------------------------------------------------------------------------//
Direct3D9Renderer::Direct3D9Renderer(LPDIRECT3DDEVICE9 device) :
    d_device(device),
    d_displaySize(getViewportSize()),
    d_displayDPI(96, 96),
    d_defaultRoot(0),
    d_defaultTarget(0)
{
    D3DCAPS9 caps;
    device->GetDeviceCaps(&caps);

    if (!caps.RasterCaps && D3DPRASTERCAPS_SCISSORTEST)
        throw RendererException("Direct3D9Renderer: Hardware does not support "
                                "D3DPRASTERCAPS_SCISSORTEST.  Unable to proceed.");

    d_maxTextureSize = ceguimin(caps.MaxTextureHeight, caps.MaxTextureWidth);

    d_supportNonSquareTex = !(caps.TextureCaps & D3DPTEXTURECAPS_SQUAREONLY);

    d_supportNPOTTex = !(caps.TextureCaps & D3DPTEXTURECAPS_POW2) ||
                       (caps.TextureCaps & D3DPTEXTURECAPS_NONPOW2CONDITIONAL);

    d_defaultTarget = new Direct3D9ViewportTarget(*this);
    d_defaultRoot = new RenderingRoot(*d_defaultTarget);
}

//----------------------------------------------------------------------------//
Direct3D9Renderer::~Direct3D9Renderer()
{
    destroyAllGeometryBuffers();
    destroyAllTextureTargets();
    destroyAllTextures();

    delete d_defaultRoot;
    delete d_defaultTarget;
}

//----------------------------------------------------------------------------//
Size Direct3D9Renderer::getViewportSize()
{
    D3DVIEWPORT9 vp;

    if (FAILED(d_device->GetViewport(&vp)))
        throw RendererException("Direct3D9Renderer::getViewportSize - Unable "
                                "to access required view port information from "
                                "Direct3DDevice9.");
    else
        return Size(static_cast<float>(vp.Width),
                    static_cast<float>(vp.Height));
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::preD3DReset()
{
    // perform pre-reset on texture targets
    TextureTargetList::iterator target_iterator = d_textureTargets.begin();
    for (; target_iterator != d_textureTargets.end(); ++target_iterator)
        static_cast<Direct3D9TextureTarget*>(*target_iterator)->preD3DReset();

    // perform pre-reset on textures
    TextureList::iterator texture_iterator = d_textures.begin();
    for (; texture_iterator != d_textures.end(); ++texture_iterator)
        (*texture_iterator)->preD3DReset();
}

//----------------------------------------------------------------------------//
void Direct3D9Renderer::postD3DReset()
{
    // perform post-reset on textures
    TextureList::iterator texture_iterator = d_textures.begin();
    for (; texture_iterator != d_textures.end(); ++texture_iterator)
        (*texture_iterator)->postD3DReset();

    // perform post-reset on texture targets
    TextureTargetList::iterator target_iterator = d_textureTargets.begin();
    for (; target_iterator != d_textureTargets.end(); ++target_iterator)
        static_cast<Direct3D9TextureTarget*>(*target_iterator)->postD3DReset();

    // notify system about the (possibly) new viewport size.
    System::getSingleton().notifyDisplaySizeChanged(getViewportSize());
}

//----------------------------------------------------------------------------//
LPDIRECT3DDEVICE9 Direct3D9Renderer::getDevice() const
{
    return d_device;
}

//----------------------------------------------------------------------------//
Texture& Direct3D9Renderer::createTexture(LPDIRECT3DTEXTURE9 texture)
{
    Direct3D9Texture* tex = new Direct3D9Texture(*this, texture);
    d_textures.push_back(tex);
    return *tex;
}

//----------------------------------------------------------------------------//
bool Direct3D9Renderer::supportsNonSquareTexture()
{
    return d_supportNonSquareTex;
}

//----------------------------------------------------------------------------//
bool Direct3D9Renderer::supportsNPOTTextures()
{
    return d_supportNPOTTex;
}

//----------------------------------------------------------------------------//
Size Direct3D9Renderer::getAdjustedSize(const Size& sz)
{
    Size s(sz);

    if (!d_supportNPOTTex)
    {
        s.d_width  = getSizeNextPOT(sz.d_width);
        s.d_height = getSizeNextPOT(sz.d_height);
    }
    if (!d_supportNonSquareTex)
        s.d_width = s.d_height =
                        ceguimax(s.d_width, s.d_height);

    return s;
}

//----------------------------------------------------------------------------//
float Direct3D9Renderer::getSizeNextPOT(float sz) const
{
    uint size = static_cast<uint>(sz);

    // if not power of 2
    if ((size & (size - 1)) || !size)
    {
        int log = 0;

        // get integer log of 'size' to base 2
        while (size >>= 1)
            ++log;

        // use log to calculate value to use as size.
        size = (2 << log);
    }

    return static_cast<float>(size);
}

//----------------------------------------------------------------------------//

} // End of  CEGUI namespace section
