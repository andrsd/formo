// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/edge.h"
#include "Standard_Handle.hxx"
#include "Geom_BSplineCurve.hxx"
#include <vector>

namespace formo {

class Axis2;

class Helix : public Edge {
public:
    /// Construct a helix approximated by B-spline
    ///
    /// @param ax2 Center of the helix
    Helix(const Axis2 & ax2, double radius, double height, double turns, double start_angle = 0.);

private:
    Handle(Geom_BSplineCurve) spline;
};

} // namespace formo
