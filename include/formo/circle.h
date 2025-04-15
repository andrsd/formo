// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/edge.h"
#include "formo/point.h"
#include "formo/direction.h"
#include "gp_Circ.hxx"

namespace formo {

class Axis2;

/// Describes a circle in 3D space. A circle is defined by its radius and positioned in space with a
/// coordinate system.
class Circle : public Edge {
public:
    /// Construct a circle from an origin and a radius.
    ///
    /// @param origin Center point
    /// @param radius Radius
    Circle(const Axis2 & origin, double radius);

    /// Construct a circle from a center point and a radius.
    ///
    /// @param center Center point
    /// @param radius Radius
    /// @param norm Normal of the plane
    Circle(const Point & center, double radius, const Direction & normal = Direction(0., 0., 1.));

    /// Construct a circle from a center point and another point
    ///
    /// @param center Center point
    /// @param pt Point that is part of the circle
    /// @param norm Normal of the plane
    Circle(const Point & center, const Point & pt, const Direction & norm = Direction(0., 0., 1.));

    /// Construct a circle from three points
    ///
    /// @param pt1 First point
    /// @param pt2 Second point
    /// @param pt3 Third point
    Circle(const Point & pt1, const Point & pt2, const Point & pt3);

    /// Get circle area
    ///
    /// @return Area of the circle
    double area() const;

    /// Get radius
    ///
    /// @return Radius
    double radius() const;

    /// Get circle location
    Point location() const;

    operator gp_Circ() const;

private:
    gp_Circ circ_;
};

} // namespace formo
