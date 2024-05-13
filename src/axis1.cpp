// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/axis1.h"

namespace formo {

Axis1::Axis1(const Point & pt, const Direction & dir) : loc(pt), dir(dir), ax1(pt, dir) {}

Point
Axis1::location() const
{
    return this->loc;
}

Direction
Axis1::direction() const
{
    return this->dir;
}

Axis1::operator gp_Ax1() const
{
    return this->ax1;
}

} // namespace formo
