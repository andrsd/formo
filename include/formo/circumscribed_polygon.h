// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/wire.h"
#include <vector>

namespace formo {

class Axis2;
class Point;
class Vector;

class CircumscribedPolygon : public Wire {
public:
    /// Create circumscribed polygon from radius and number of sides
    ///
    /// @param radius Radius if the circle
    /// @param sides Number of sides (must be 3 or more)
    CircumscribedPolygon(const Axis2 & ax2, double radius, int sides);

    /// Create circumscribed polygon from a point and number of sides
    ///
    /// @param pt1 Point defining the circle and the first point of the polygon
    /// @param sides Number of sides (must be 3 or more)
    CircumscribedPolygon(const Axis2 & ax2, const Point & pt1, int sides);

private:
    std::vector<Point> build_points(const Axis2 & ax2, const Vector & vec);
    TopoDS_Wire build_polygon(const std::vector<Point> & points);

    /// Radius of the circle
    double radius;
    /// Number of sides
    int n_sides;
};

} // namespace formo
