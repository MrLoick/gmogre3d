/***********************************************************************
    filename:   CEGUIIrrlichtRenderTarget.cpp
    created:    Tue Mar 3 2009
    author:     Paul D Turner (parts based on original code by Thomas Suter)
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
#include "CEGUIIrrlichtRenderTarget.h"
#include "CEGUIGeometryBuffer.h"
#include "CEGUIRenderQueue.h"
#include "CEGUIIrrlichtGeometryBuffer.h"

// Start of CEGUI namespace section
namespace CEGUI
{

//----------------------------------------------------------------------------//
IrrlichtRenderTarget::IrrlichtRenderTarget(IrrlichtRenderer& owner,
                                           irr::video::IVideoDriver& driver) :
    d_owner(owner),
    d_driver(driver),
    d_area(0, 0, 0, 0),
    d_matrixValid(false),
    d_xViewDir(driver.getDriverType() != irr::video::EDT_OPENGL ? 1.0f : -1.0f)
{
}

//----------------------------------------------------------------------------//
IrrlichtRenderTarget::~IrrlichtRenderTarget()
{
}

//----------------------------------------------------------------------------//
void IrrlichtRenderTarget::draw(const GeometryBuffer& buffer)
{
    buffer.draw();
}

//----------------------------------------------------------------------------//
void IrrlichtRenderTarget::draw(const RenderQueue& queue)
{
    queue.draw();
}

//----------------------------------------------------------------------------//
void IrrlichtRenderTarget::setArea(const Rect& area)
{
    d_area = area;
    d_matrixValid = false;
}

//----------------------------------------------------------------------------//
const Rect& IrrlichtRenderTarget::getArea() const
{
    return d_area;
}

//----------------------------------------------------------------------------//
void IrrlichtRenderTarget::activate()
{
    irr::core::rect<irr::s32> vp(static_cast<irr::s32>(d_area.d_left),
                                 static_cast<irr::s32>(d_area.d_top),
                                 static_cast<irr::s32>(d_area.d_right),
                                 static_cast<irr::s32>(d_area.d_bottom));
    d_driver.setViewPort(vp);

    if (!d_matrixValid)
        updateMatrix();

    d_driver.setTransform(irr::video::ETS_PROJECTION, d_matrix);
    d_driver.setTransform(irr::video::ETS_VIEW, irr::core::matrix4());
}

//----------------------------------------------------------------------------//
void IrrlichtRenderTarget::deactivate()
{
}

//----------------------------------------------------------------------------//
void IrrlichtRenderTarget::unprojectPoint(const GeometryBuffer& buff,
                                          const Vector2& p_in,
                                          Vector2& p_out) const
{
    if (!d_matrixValid)
        updateMatrix();

    const IrrlichtGeometryBuffer& gb =
        static_cast<const IrrlichtGeometryBuffer&>(buff);

    const irr::f32 midx = d_area.getWidth() * 0.5f;
    const irr::f32 midy = d_area.getHeight() * 0.5f;

    // viewport matrix
    const irr::f32 vpmat_[] =
    {
        midx, 0, 0, 0,
        0, -midy, 0, 0,
        0, 0, 1, 0,
        d_area.d_left + midx, d_area.d_top + midy, 0, 1
    };
    irr::core::matrix4 vpmat;
    vpmat.setM(vpmat_);

    // matrices used for projecting and unprojecting points
    const irr::core::matrix4 proj(gb.getMatrix() * d_matrix * vpmat);
    irr::core::matrix4 unproj(proj);
    unproj.makeInverse();

    irr::core::vector3df in;

    // unproject the ends of the ray
    in.X = midx;
    in.Y = midy;
    in.Z = -d_viewDistance;
    irr::core::vector3df r1;
    unproj.transformVect(r1, in);
    in.X = p_in.d_x;
    in.Y = p_in.d_y;
    in.Z = 0;
    irr::core::vector3df r2;
    unproj.transformVect(r2, in);
    // calculate vector of picking ray
    const irr::core::vector3df rv(r1 - r2);

    // project points to orientate them with GeometryBuffer plane
    in.X = 0.0;
    in.Y = 0.0;
    irr::core::vector3df p1;
    proj.transformVect(p1, in);
    in.X = 1.0;
    in.Y = 0.0;
    irr::core::vector3df p2;
    proj.transformVect(p2, in);
    in.X = 0.0;
    in.Y = 1.0;
    irr::core::vector3df p3;
    proj.transformVect(p3, in);

    // calculate the plane normal
    const irr::core::vector3df pn((p2 - p1).crossProduct(p3 - p1));
    // calculate distance from origin
    const irr::f32 plen = pn.getLength();
    const irr::f32 dist = -(p1.X * (pn.X / plen) +
                            p1.Y * (pn.Y / plen) +
                            p1.Z * (pn.Z / plen));

    // calculate intersection of ray and plane
    const irr::f32 pn_dot_rv = pn.dotProduct(rv);
    const irr::f32 tmp = pn_dot_rv != 0.0 ?
                            (pn.dotProduct(r1) + dist) / pn_dot_rv :
                             0.0f;

    p_out.d_x = static_cast<float>(r1.X - rv.X * tmp) * d_viewDistance;
    p_out.d_y = static_cast<float>(r1.Y - rv.Y * tmp) * d_viewDistance;
}

//----------------------------------------------------------------------------//
void IrrlichtRenderTarget::updateMatrix() const
{
    const float w = d_area.getWidth();
    const float h = d_area.getHeight();
    const float aspect = w / h;
    const float midx = w * 0.5f;
    const float midy = h * 0.5f;
    d_viewDistance = midx / (aspect * 0.267949192431123f);

    d_matrix.buildProjectionMatrixPerspectiveFovRH(0.523598776f, aspect,
                                                   d_viewDistance * 0.5f,
                                                   d_viewDistance * 2.0f);

    irr::core::matrix4 tmp;
    tmp.buildCameraLookAtMatrixRH(
        irr::core::vector3df(d_xViewDir * midx, midy, -d_viewDistance),
        irr::core::vector3df(d_xViewDir * midx, midy, 1),
        irr::core::vector3df(0, -1, 0));

    d_matrix *= tmp;

    d_matrixValid = true;
}

//----------------------------------------------------------------------------//

} // End of  CEGUI namespace section
