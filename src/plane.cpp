// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/plane.h"
#include "formo/axis1.h"

namespace formo {

Plane::Plane(const Point & pt, const Direction & normal) : pln(pt, normal) {}

Plane::Plane(const gp_Pln & pln) : pln(pln) {}

Point
Plane::location() const
{
    return Point(this->pln.Location());
}

Axis1
Plane::axis() const
{
    return Axis1(this->pln.Axis());
}

Axis1
Plane::x_axis() const
{
    return Axis1(this->pln.XAxis());
}

Axis1
Plane::y_axis() const
{
    return Axis1(this->pln.YAxis());
}

Plane::operator gp_Pln() const
{
    return this->pln;
}

} // namespace formo
