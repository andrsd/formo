// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/axis2.h"
#include "formo/axis1.h"

namespace formo {

Axis2::Axis2(const Point & pt, const Direction & direction) : ax2(pt, direction) {}

Axis2::Axis2(const Point & pt, const Direction & n, const Direction & v_x) : ax2(pt, n, v_x) {}

Point
Axis2::location() const
{
    return Point(this->ax2.Location());
}

Axis1
Axis2::axis() const
{
    return Axis1(this->ax2.Axis());
}

Direction
Axis2::direction() const
{
    return this->ax2.Direction();
}

Direction
Axis2::x_direction() const
{
    return this->ax2.XDirection();
}

Direction
Axis2::y_direction() const
{
    return this->ax2.YDirection();
}

Axis2::operator gp_Ax2() const
{
    return this->ax2;
}

} // namespace formo
