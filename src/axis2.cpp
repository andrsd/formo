// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/axis2.h"
#include "formo/axis1.h"

namespace formo {

Axis2::Axis2(const Point & pt, const Direction & direction) : ax2_(pt, direction) {}

Axis2::Axis2(const Point & pt, const Direction & n, const Direction & v_x) : ax2_(pt, n, v_x) {}

Point
Axis2::location() const
{
    return Point(this->ax2_.Location());
}

Axis1
Axis2::axis() const
{
    return Axis1(this->ax2_.Axis());
}

Direction
Axis2::direction() const
{
    return this->ax2_.Direction();
}

Direction
Axis2::x_direction() const
{
    return this->ax2_.XDirection();
}

Direction
Axis2::y_direction() const
{
    return this->ax2_.YDirection();
}

Axis2::operator gp_Ax2() const
{
    return this->ax2_;
}

} // namespace formo
