// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/circle.h"
#include "formo/axis2.h"
#include "formo/exception.h"
#include "GC_MakeCircle.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "gp_Circ.hxx"

namespace formo {

Circle::Circle(const Axis2 & origin, double radius) : Edge()
{
    GC_MakeCircle make_circ(origin, radius);
    if (!make_circ.IsDone())
        throw Exception("Circle was not created");
    BRepBuilderAPI_MakeEdge maker(make_circ.Value());
    maker.Build();
    if (!maker.IsDone())
        throw Exception("Circle was not created");
    set_shape(maker.Shape());
    set_edge(maker.Edge());
    this->circ = make_circ.Value()->Circ();
}

Circle::Circle(const Point & center, double radius, const Direction & normal) : Edge()
{
    GC_MakeCircle make_circ(center, normal, radius);
    if (!make_circ.IsDone())
        throw Exception("Circle was not created");
    BRepBuilderAPI_MakeEdge maker(make_circ.Value());
    maker.Build();
    if (!maker.IsDone())
        throw Exception("Circle was not created");
    set_shape(maker.Shape());
    set_edge(maker.Edge());
    this->circ = make_circ.Value()->Circ();
}

Circle::Circle(const Point & center, const Point & pt, const Direction & norm)
{
    auto radius = center.distance(pt);
    GC_MakeCircle make_circ(center, norm, radius);
    if (!make_circ.IsDone())
        throw Exception("Circle was not created");
    BRepBuilderAPI_MakeEdge maker(make_circ.Value());
    maker.Build();
    if (!maker.IsDone())
        throw Exception("Circle was not created");
    set_shape(maker.Shape());
    set_edge(maker.Edge());
    this->circ = make_circ.Value()->Circ();
}

Circle::Circle(const Point & pt1, const Point & pt2, const Point & pt3)
{
    GC_MakeCircle make_circ(pt1, pt2, pt3);
    if (!make_circ.IsDone())
        throw Exception("Circle was not created");
    BRepBuilderAPI_MakeEdge maker(make_circ.Value());
    maker.Build();
    if (!maker.IsDone())
        throw Exception("Circle was not created");
    set_shape(maker.Shape());
    set_edge(maker.Edge());
    this->circ = make_circ.Value()->Circ();
}

double
Circle::area() const
{
    return this->circ.Area();
}

double
Circle::radius() const
{
    return this->circ.Radius();
}

Point
Circle::location() const
{
    auto pnt = this->circ.Location();
    return Point(pnt.X(), pnt.Y(), pnt.Z());
}

Circle::operator gp_Circ() const
{
    return this->circ;
}

} // namespace formo
