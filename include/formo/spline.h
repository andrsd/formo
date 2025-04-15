// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/edge.h"
#include "formo/point.h"
#include "formo/vector.h"
#include "Standard_Handle.hxx"
#include "Geom_BSplineCurve.hxx"
#include <vector>

namespace formo {

class Spline : public Edge {
public:
    /// Construct a B-spline that is passing through an array of points. The continuity will be C2.
    ///
    /// @param points Array of points
    Spline(const std::vector<Point> & points);

    /// Construct a B-spline that is passing through an array of points with specified tangency.
    /// The continuity will be C1.
    ///
    /// @param points Array of points
    /// @param initial_tg Initial tangent
    /// @param final_tg Final tangent
    Spline(const std::vector<Point> & points, const Vector & initial_tg, const Vector & final_tg);

private:
    Handle(Geom_BSplineCurve) spline_;
};

} // namespace formo
