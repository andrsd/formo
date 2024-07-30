// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/point.h"
#include "formo/exception.h"
#include "formo/vector.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
#include "BRepBuilderAPI_MakeVertex.hxx"

namespace formo {

Point::Point(double x, double y, double z) : Shape(), pnt(x, y, z)
{
    BRepBuilderAPI_MakeVertex maker(this->pnt);
    maker.Build();
    if (!maker.IsDone())
        throw Exception("Point was not created");
    set_shape(maker.Shape());
    this->vtx = maker.Vertex();
}

Point::Point(const gp_Pnt & pt) : Shape(), pnt(pt)
{
    BRepBuilderAPI_MakeVertex maker(this->pnt);
    maker.Build();
    if (!maker.IsDone())
        throw Exception("Point was not created");
    set_shape(maker.Shape());
    this->vtx = maker.Vertex();
}

double
Point::x() const
{
    return this->pnt.X();
}

double
Point::y() const
{
    return this->pnt.Y();
}

double
Point::z() const
{
    return this->pnt.Z();
}

bool
Point::is_equal(const Point & other, double tol) const
{
    return this->pnt.IsEqual(other, tol);
}

double
Point::distance(const Point & pt) const
{
    return this->pnt.Distance(pt);
}

void
Point::mirror(const Point & pt)
{
    this->pnt.Mirror(pt);
}

void
Point::mirror(const Axis1 & ax1)
{
    this->pnt.Mirror(ax1);
}

void
Point::mirror(const Axis2 & ax2)
{
    this->pnt.Mirror(ax2);
}

Point
Point::mirrored(const Point & pt) const
{
    return Point(this->pnt.Mirrored(pt));
}

Point
Point::mirrored(const Axis1 & ax1) const
{
    return Point(this->pnt.Mirrored(ax1));
}

Point
Point::mirrored(const Axis2 & ax2) const
{
    return Point(this->pnt.Mirrored(ax2));
}

void
Point::rotate(const Axis1 & ax1, double angle)
{
    this->pnt.Rotate(ax1, angle);
}

Point
Point::rotated(const Axis1 & ax1, double angle) const
{
    return Point(this->pnt.Rotated(ax1, angle));
}

void
Point::translate(const Vector & vec)
{
    this->pnt.Translate(vec);
}

Point
Point::translated(const Vector & vec) const
{
    return Point(this->pnt.Translated(vec));
}

Point::operator gp_Pnt() const
{
    return this->pnt;
}

Point
operator+(const Point & pt, const Vector & v)
{
    return Point(pt.x() + v.x(), pt.y() + v.y(), pt.z() + v.z());
}

} // namespace formo
