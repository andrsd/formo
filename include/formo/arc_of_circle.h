// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/edge.h"
#include "formo/point.h"
#include "formo/vector.h"
#include "formo/circle.h"
#include "Geom_TrimmedCurve.hxx"

namespace formo {

/// Describes an arc of a circle in 3D space.
class ArcOfCircle : public Edge {
public:
    /// Construct an arc of a circle from trhee points
    ///
    /// @param pt1 First point
    /// @param pt2 Second point
    /// @param pt3 Third point
    ArcOfCircle(const Point & pt1, const Point & pt2, const Point & pt3);

    /// Construct an arc of a circle from a circle and 2 points on the circle.
    ///
    /// @param circ Circle
    /// @param pt1 First point
    /// @param pt2 Second point
    /// @param sense Sense of the circle
    ArcOfCircle(const Circle & circ, const Point & pt1, const Point & pt2, bool sense = true);

    /// Construct an arc of a circle from a point, tangent at the point, and another point.
    ///
    /// @param pt1 First point
    /// @param tangent Tangent at point `pt1`
    /// @param pt2 Second point
    ArcOfCircle(const Point & pt1, const Vector & tangent, const Point & pt2);

    /// Get the start point of the curve
    Point start_point() const;

    /// Get the end point of the curve
    Point end_point() const;

private:
    Handle(Geom_TrimmedCurve) arc;
};

} // namespace formo
