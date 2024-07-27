// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/pattern.h"
#include "formo/axis2.h"

namespace formo {

/// Linear pattern
class LinearPattern : public Pattern {
public:
    LinearPattern(const Axis2 & origin, int nx, double dx);
    LinearPattern(const Axis2 & origin, int nx, int ny, double dx, double dy);

private:
    /// Origin of the pattern
    Axis2 ax2;
    /// number of points in x-direction
    int nx;
    ///
    double dx;
    /// number of points in y-direction
    int ny;
    ///
    double dy;
};

} // namespace formo
