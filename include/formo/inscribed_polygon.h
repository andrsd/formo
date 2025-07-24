// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/polygon.h"

namespace formo {

class Axis2;
class Point;
class Vector;

/// A class representing a regular polygon inscribed in a circle.  That is, the polygon is
/// constructed such that all of its vertices lie on the circle's circumference.
class InscribedPolygon : public Polygon {
public:
    /// Create inscribed polygon from radius and number of sides
    ///
    /// @param radius Radius if the circle
    /// @param sides Number of sides (must be 3 or more)
    InscribedPolygon(const Axis2 & ax2, double radius, int sides);

    /// Create inscribed polygon from a point and number of sides
    ///
    /// @param pt1 Point defining the circle and the first point of the polygon
    /// @param sides Number of sides (must be 3 or more)
    InscribedPolygon(const Axis2 & ax2, const Point & pt1, int sides);

private:
    /// Radius of the circle
    double radius_;
    /// Number of sides
    int n_sides_;
};

} // namespace formo
