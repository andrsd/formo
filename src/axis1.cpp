// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/axis1.h"

namespace formo {

Axis1::Axis1(const gp_Ax1 & ax1) : ax1_(ax1) {}

Axis1::Axis1(const Point & pt, const Direction & dir) : ax1_(pt, dir) {}

Point
Axis1::location() const
{
    return Point(this->ax1_.Location());
}

Direction
Axis1::direction() const
{
    return Direction(this->ax1_.Direction());
}

Axis1::operator gp_Ax1() const
{
    return this->ax1_;
}

} // namespace formo
