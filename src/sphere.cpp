// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/sphere.h"
#include "formo/exception.h"

namespace formo {

Sphere::Sphere(const Point & center, double radius) : Solid()
{
    BRepPrimAPI_MakeSphere sphere(center, radius);
    sphere.Build();
    if (!sphere.IsDone())
        throw Exception("Sphere was not created");
    set_shape(sphere.Shape());
    set_solid(sphere.Solid());
    assign_color();
}

} // namespace formo
