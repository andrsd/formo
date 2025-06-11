// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/solid.h"
#include "formo/shell.h"
#include "formo/axis2.h"
#include "BRepPrimAPI_MakeCylinder.hxx"

namespace formo {

class Cylinder : public Solid {
public:
    /// Create a cylinder
    ///
    /// @param location Location in space
    /// @param radius Radius
    /// @param height Height
    Cylinder(const Axis2 & location, double radius, double height);
};

} // namespace formo
