// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/solid.h"
#include "formo/point.h"
#include "BRepPrimAPI_MakeSphere.hxx"

namespace formo {

class Sphere : public Solid {
public:
    /// Create a sphere
    ///
    /// @param center Location of the sphere center
    /// @param radius Radius of the sphere
    Sphere(const Point & center, double radius);
};

} // namespace formo
