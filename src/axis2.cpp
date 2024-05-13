// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/axis2.h"

namespace formo {

Axis2::Axis2(const Point & pt, const Direction & direction) :
    loc(pt),
    dir(direction),
    ax2(pt, direction)
{
}

Point
Axis2::location() const
{
    return this->loc;
}

Direction
Axis2::direction() const
{
    return this->dir;
}

Axis2::operator gp_Ax2() const
{
    return this->ax2;
}

} // namespace formo
