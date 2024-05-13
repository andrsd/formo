// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/geometry.h"

namespace formo {

Axis1
Geometry::OX()
{
    Point pt(0, 0, 0);
    Direction direction(1, 0, 0);
    return Axis1(pt, direction);
}

Axis1
Geometry::OY()
{
    Point pt(0, 0, 0);
    Direction direction(0, 1, 0);
    return Axis1(pt, direction);
}

Axis1
Geometry::OZ()
{
    Point pt(0, 0, 0);
    Direction direction(0, 0, 1);
    return Axis1(pt, direction);
}

Direction
Geometry::DX()
{
    return Direction(1, 0, 0);
}

Direction
Geometry::DY()
{
    return Direction(0, 1, 0);
}

Direction
Geometry::DZ()
{
    return Direction(0, 0, 1);
}

} // namespace formo
