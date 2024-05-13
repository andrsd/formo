// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/plane.h"

namespace formo {

Plane::Plane(const Point & pt, const Direction & normal) : pln(pt, normal) {}

Plane::Plane(const gp_Pln & pln)
{
    this->pln = pln;
}

Point
Plane::location() const
{
    return Point(this->pln.Location());
}

Plane::operator gp_Pln() const
{
    return this->pln;
}

} // namespace formo
