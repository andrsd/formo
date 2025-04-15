// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/arc_of_circle.h"
#include "formo/exception.h"
#include "GC_MakeArcOfCircle.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"

namespace formo {

ArcOfCircle::ArcOfCircle(const Point & pt1, const Point & pt2, const Point & pt3) : Edge()
{
    GC_MakeArcOfCircle mk(pt1, pt2, pt3);
    if (!mk.IsDone())
        throw Exception("ArcOfCircle was not created");
    this->arc_ = mk.Value();
    BRepBuilderAPI_MakeEdge make_edge(this->arc_);
    make_edge.Build();
    if (!make_edge.IsDone())
        throw Exception("Edge was not created");
    set_shape(make_edge.Shape());
    set_edge(make_edge.Edge());
}

ArcOfCircle::ArcOfCircle(const Circle & circ, const Point & pt1, const Point & pt2, bool sense) :
    Edge()
{
    GC_MakeArcOfCircle mk(circ, pt1, pt2, sense);
    if (!mk.IsDone())
        throw Exception("ArcOfCircle was not created");
    this->arc_ = mk.Value();
    BRepBuilderAPI_MakeEdge make_edge(this->arc_);
    make_edge.Build();
    if (!make_edge.IsDone())
        throw Exception("Edge was not created");
    set_shape(make_edge.Shape());
    set_edge(make_edge.Edge());
}

ArcOfCircle::ArcOfCircle(const Point & pt1, const Vector & tangent, const Point & pt2) : Edge()
{
    GC_MakeArcOfCircle mk(pt1, tangent, pt2);
    if (!mk.IsDone())
        throw Exception("ArcOfCircle was not created");
    this->arc_ = mk.Value();
    BRepBuilderAPI_MakeEdge make_edge(this->arc_);
    make_edge.Build();
    if (!make_edge.IsDone())
        throw Exception("Edge was not created");
    set_shape(make_edge.Shape());
    set_edge(make_edge.Edge());
}

Point
ArcOfCircle::start_point() const
{
    return Point(this->arc_->StartPoint());
}

Point
ArcOfCircle::end_point() const
{
    return Point(this->arc_->EndPoint());
}

} // namespace formo
