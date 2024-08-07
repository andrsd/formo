// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/point.h"
#include "formo/wire.h"
#include "BRepBuilderAPI_MakePolygon.hxx"
#include <vector>

namespace formo {

class Axis2;
class Point;
class Vector;

class Polygon : public Wire {
public:
    Polygon() = default;
    Polygon(const std::vector<Point> & points, bool closed = true);

protected:
    std::vector<Point> build_points(const Axis2 & ax2, const Vector & vec, int n_sides);
    BRepBuilderAPI_MakePolygon build_polygon(const std::vector<Point> & points, bool closed);
};

} // namespace formo
