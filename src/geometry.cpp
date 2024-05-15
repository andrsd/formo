// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/geometry.h"

namespace formo {

Axis1 Geometry::OX = Axis1(Point(0, 0, 0), Direction(1, 0, 0));

Axis1 Geometry::OY = Axis1(Point(0, 0, 0), Direction(0, 1, 0));

Axis1 Geometry::OZ = Axis1(Point(0, 0, 0), Direction(0, 0, 1));

Direction Geometry::DX = Direction(1, 0, 0);

Direction Geometry::DY = Direction(0, 1, 0);

Direction Geometry::DZ = Direction(0, 0, 1);

} // namespace formo
