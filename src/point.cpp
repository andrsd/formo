// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/point.h"
#include "formo/exception.h"
#include "formo/vector.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
#include "BRepBuilderAPI_MakeVertex.hxx"

namespace formo {

Point::Point(double x, double y, double z) : Shape(), pnt_(x, y, z)
{
    BRepBuilderAPI_MakeVertex maker(this->pnt_);
    maker.Build();
    if (!maker.IsDone())
        throw Exception("Point was not created");
    set_shape(maker.Shape());
    this->vtx_ = maker.Vertex();
}

Point::Point(const gp_Pnt & pt) : Shape(), pnt_(pt)
{
    BRepBuilderAPI_MakeVertex maker(this->pnt_);
    maker.Build();
    if (!maker.IsDone())
        throw Exception("Point was not created");
    set_shape(maker.Shape());
    this->vtx_ = maker.Vertex();
}

double
Point::x() const
{
    return this->pnt_.X();
}

double
Point::y() const
{
    return this->pnt_.Y();
}

double
Point::z() const
{
    return this->pnt_.Z();
}

bool
Point::is_equal(const Point & other, double tol) const
{
    return this->pnt_.IsEqual(other, tol);
}

double
Point::distance(const Point & pt) const
{
    return this->pnt_.Distance(pt);
}

void
Point::mirror(const Point & pt)
{
    this->pnt_.Mirror(pt);
}

void
Point::mirror(const Axis1 & ax1)
{
    this->pnt_.Mirror(ax1);
}

void
Point::mirror(const Axis2 & ax2)
{
    this->pnt_.Mirror(ax2);
}

Point
Point::mirrored(const Point & pt) const
{
    return Point(this->pnt_.Mirrored(pt));
}

Point
Point::mirrored(const Axis1 & ax1) const
{
    return Point(this->pnt_.Mirrored(ax1));
}

Point
Point::mirrored(const Axis2 & ax2) const
{
    return Point(this->pnt_.Mirrored(ax2));
}

void
Point::rotate(const Axis1 & ax1, double angle)
{
    this->pnt_.Rotate(ax1, angle);
}

Point
Point::rotated(const Axis1 & ax1, double angle) const
{
    return Point(this->pnt_.Rotated(ax1, angle));
}

void
Point::scale(const Point & pt, double s)
{
    this->pnt_.Scale(pt, s);
}

Point
Point::scaled(const Point & pt, double s) const
{
    return Point(this->pnt_.Scaled(pt, s));
}

void
Point::translate(const Vector & vec)
{
    this->pnt_.Translate(vec);
}

void
Point::translate(const Point & p1, const Point & p2)
{
    this->pnt_.Translate(p1, p2);
}

Point
Point::translated(const Vector & vec) const
{
    return Point(this->pnt_.Translated(vec));
}

Point
Point::translated(const Point & p1, const Point & p2) const
{
    return Point(this->pnt_.Translated(p1, p2));
}

Point::operator gp_Pnt() const
{
    return this->pnt_;
}

Point
operator+(const Point & a, const Point & b)
{
    return Point(a.x() + b.x(), a.y() + b.y(), a.z() + b.z());
}

Point
operator+(const Point & pt, const Vector & v)
{
    return Point(pt.x() + v.x(), pt.y() + v.y(), pt.z() + v.z());
}

} // namespace formo
