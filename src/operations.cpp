// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/operations.h"
#include "formo/exception.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
#include "formo/plane.h"
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
#include "BRepOffsetAPI_DraftAngle.hxx"
#include "BRepFeat_MakeCylindricalHole.hxx"
#include "BRepOffsetAPI_MakePipe.hxx"
#include "BRepBuilderAPI_Sewing.hxx"
#include "TopoDS_Shape.hxx"

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

Vector
mirror(const Vector & vector, const Axis1 & axis)
{
    gp_Vec vec(vector.x(), vector.y(), vector.z());
    auto res = vec.Mirrored(axis);
    return Vector(res.X(), res.Y(), res.Z());
}

Vector
mirror(const Vector & vector, const Axis2 & axis)
{
    gp_Vec vec(vector.x(), vector.y(), vector.z());
    auto res = vec.Mirrored(axis);
    return Vector(res.X(), res.Y(), res.Z());
}

Point
mirror(const Point & point, const Axis1 & axis)
{
    gp_Pnt pnt(point.x(), point.y(), point.z());
    auto res = pnt.Mirrored(axis);
    return Point(res);
}

Point
mirror(const Point & point, const Axis2 & axis)
{
    gp_Pnt pnt(point.x(), point.y(), point.z());
    auto res = pnt.Mirrored(axis);
    return Point(res);
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
fuse(const std::vector<Shape> & shapes)
{
    if (shapes.empty())
        throw Exception("No shapes to fuse");

    if (shapes.size() == 1)
        throw Exception("Only one shape provided");

    TopoDS_Shape sh = shapes[0];
    for (std::size_t i = 1; i < shapes.size(); ++i) {
        BRepAlgoAPI_Fuse alg(sh, shapes[i]);
        alg.Build();
        alg.SimplifyResult();
        if (!alg.IsDone())
            throw Exception("Objects were not fused");
        sh = alg.Shape();
    }

    return Shape(sh);
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

Point
rotate(const Point & point, const Axis1 & axis, double angle)
{
    gp_Pnt pnt(point.x(), point.y(), point.z());
    auto res = pnt.Rotated(axis, angle);
    return Point(res);
}

Vector
rotate(const Vector & vector, const Axis1 & axis, double angle)
{
    gp_Vec vec(vector.x(), vector.y(), vector.z());
    auto res = vec.Rotated(axis, angle);
    return Vector(res.X(), res.Y(), res.Z());
}

Shape
rotate(const Shape & shape, const Axis1 & axis, double angle)
{
    gp_Trsf trsf;
    trsf.SetRotation(axis, angle);
    BRepBuilderAPI_Transform brep_trsf(shape, trsf);
    return Shape(brep_trsf.Shape());
}

Wire
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

Shape
draft(const Shape & shape, const Plane & pln, const std::vector<Face> & faces, double angle)
{
    auto dir = pln.axis().direction();
    BRepOffsetAPI_DraftAngle drft(shape);
    for (auto & f : faces) {
        drft.Add(f, dir, angle, pln);
        if (!drft.AddDone())
            throw Exception("Faulty face was given");
    }
    drft.Build();
    if (drft.IsDone())
        return Shape(drft.Shape());
    else
        throw Exception("Draft was not constructed");
}

Shape
hole(const Shape & shape, const Axis1 & axis, double radius)
{
    BRepFeat_MakeCylindricalHole h;
    h.Init(shape, axis);
    h.Perform(radius);
    h.Build();
    if (h.Status() == BRepFeat_NoError)
        return Shape(h.Shape());
    else
        throw Exception("Hole did not generate");
}

Shape
hole(const Shape & shape, const Axis1 & axis, double radius, double length)
{
    BRepFeat_MakeCylindricalHole h;
    h.Init(shape, axis);
    h.PerformBlind(radius, length);
    h.Build();
    if (h.Status() == BRepFeat_NoError)
        return Shape(h.Shape());
    else
        throw Exception("Hole did not generate");
}

Shape
sweep(const Shape & profile, const Wire & spine)
{
    BRepOffsetAPI_MakePipe mk(spine, profile);
    mk.Build();
    if (mk.IsDone())
        return Shape(mk.Shape());
    else
        throw Exception("Sweep was not constructed");
}

Shape
sew(const std::vector<Shape> & faces, double tol)
{
    BRepBuilderAPI_Sewing sewing_tool(tol);
    for (auto & face : faces)
        sewing_tool.Add(face);
    sewing_tool.Perform();
    return Shape(sewing_tool.SewedShape());
}

} // namespace formo
