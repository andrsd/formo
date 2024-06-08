// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/face.h"
#include "formo/exception.h"
#include "BRepBuilderAPI_MakeFace.hxx"
#include "BRepAdaptor_Surface.hxx"
#include "GProp_GProps.hxx"
#include "BRepGProp.hxx"

namespace formo {

Face::Face(const Wire & wire)
{
    BRepBuilderAPI_MakeFace make_face(wire);
    make_face.Build();
    if (!make_face.IsDone())
        throw Exception("Face was not created");
    set_shape(make_face.Shape());
    this->face = make_face.Face();
}

bool
Face::is_plane() const
{
    BRepAdaptor_Surface surf(this->face, true);
    auto surf_type = surf.GetType();
    return surf_type == GeomAbs_Plane;
}

Plane
Face::plane() const
{
    BRepAdaptor_Surface pln(this->face, true);
    return Plane(pln.Plane());
}

double
Face::area() const
{
    GProp_GProps props;
    BRepGProp::SurfaceProperties(this->face, props);
    return props.Mass();
}

Face::operator TopoDS_Face() const
{
    return this->face;
}

} // namespace formo
