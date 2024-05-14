// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/operations.h"
#include "formo/exception.h"
#include "formo/axis1.h"
#include "BRepBuilderAPI_Transform.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepAlgoAPI_Fuse.hxx"
#include "BRepAlgoAPI_Cut.hxx"
#include "BRepAlgoAPI_Common.hxx"
#include "BRepFilletAPI_MakeFillet.hxx"
#include "BRepOffsetAPI_MakeThickSolid.hxx"
#include "BRepPrimAPI_MakePrism.hxx"
#include "BRepPrimAPI_MakeRevol.hxx"
#include "BRepAlgoAPI_Section.hxx"

namespace formo {

Shape
translate(const Shape & shape, const Vector & v)
{
    gp_Trsf trsf;
    trsf.SetTranslation(v);
    BRepBuilderAPI_Transform brep_trsf(shape, trsf);
    return Shape(brep_trsf.Shape());
}

Shape
translate(const Shape & shape, const Point & p1, const Point & p2)
{
    gp_Trsf trsf;
    trsf.SetTranslation(p1, p2);
    BRepBuilderAPI_Transform brep_trsf(shape, trsf);
    return Shape(brep_trsf.Shape());
}

Shape
scale(const Shape & shape, double s)
{
    gp_Trsf trsf;
    trsf.SetScaleFactor(s);
    BRepBuilderAPI_Transform brep_trsf(shape, trsf);
    return Shape(brep_trsf.Shape());
}

Vector
scale(const Vector & vec, double s)
{
    gp_Vec v(vec);
    auto scaled = v.Scaled(s);
    return Vector(scaled.X(), scaled.Y(), scaled.Z());
}

Shape
mirror(const Shape & shape, const Axis1 & axis)
{
    gp_Trsf trsf;
    trsf.SetMirror(axis);
    BRepBuilderAPI_Transform brep_trsf(shape, trsf);
    return Shape(brep_trsf.Shape());
}

Shape
fuse(const Shape & shape, const Shape & tool)
{
    BRepAlgoAPI_Fuse alg(shape, tool);
    alg.Build();
    alg.SimplifyResult();
    if (!alg.IsDone())
        throw Exception("Objects were not fused");
    return Shape(alg.Shape());
}

Shape
cut(const Shape & shape, const Shape & tool)
{
    BRepAlgoAPI_Cut alg(shape, tool);
    alg.Build();
    if (!alg.IsDone())
        throw Exception("Object was not cut");
    return Shape(alg.Shape());
}

Shape
intersect(const Shape & shape, const Shape & tool)
{
    BRepAlgoAPI_Common alg(shape, tool);
    alg.Build();
    if (!alg.IsDone())
        throw Exception("Object was not intersected");
    return Shape(alg.Shape());
}

Shape
fillet(const Shape & shape, const std::vector<Edge> & edges, double radius)
{
    BRepFilletAPI_MakeFillet flt(shape);
    for (auto & e : edges)
        flt.Add(radius, e);
    return Shape(flt.Shape());
}

Shape
hollow(const Shape & shape,
       const std::vector<Face> & faces_to_remove,
       double thickness,
       double tolerance)
{
    TopTools_ListOfShape rem_faces;
    for (auto & face : faces_to_remove)
        rem_faces.Append(face);

    BRepOffsetAPI_MakeThickSolid result;
    result.MakeThickSolidByJoin(shape, rem_faces, thickness, tolerance);
    result.Build();
    if (!result.IsDone())
        throw Exception("hollow failed");
    return Shape(result.Shape());
}

Shape
extrude(const Shape & shape, const Vector & vec)
{
    BRepPrimAPI_MakePrism result(shape, vec);
    result.Build();
    if (!result.IsDone())
        throw Exception("extrude failed");
    return Shape(result.Shape());
}

Shape
revolve(const Shape & shape, const Axis1 & axis, double angle)
{
    BRepPrimAPI_MakeRevol result(shape, axis, angle);
    result.Build();
    if (!result.IsDone())
        throw Exception("revolve failed");
    return Shape(result.Shape());
}

Shape
section(const Shape & shape, const Plane & plane)
{
    BRepAlgoAPI_Section result(shape, plane);
    result.Build();
    if (!result.IsDone())
        throw Exception("Section operation failed");
    auto & section_edges = result.SectionEdges();
    BRepBuilderAPI_MakeWire wire;
    wire.Add(section_edges);
    wire.Build();
    if (!wire.IsDone())
        throw Exception("Wire was not created");
    return Wire(wire.Wire());
}

} // namespace formo
