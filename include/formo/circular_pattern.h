// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/pattern.h"
#include "formo/axis2.h"

namespace formo {

/// Circular pattern
class CircularPattern : public Pattern {
public:
    /// Create circular pattern over full circle
    ///
    /// @param center Center of the pattern
    /// @param radius Radius of the pattern
    /// @param divisions Number of segments around the circle
    CircularPattern(const Axis2 & center, double radius, int divisions, double start_angle = 0.);

private:
    /// Center of the pattern
    Axis2 center_;
    /// Radius
    double radius_;
    /// number of divisions
    int divs_;
};

} // namespace formo
