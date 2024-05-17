// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/cylinder.h"
#include "formo/exception.h"

namespace formo {

Cylinder::Cylinder(const Axis2 & axis, double radius, double height) : Solid()
{
    BRepPrimAPI_MakeCylinder cyl(axis, radius, height);
    cyl.Build();
    if (!cyl.IsDone())
        throw Exception("Cylinder was not created");
    set_shape(cyl.Shape());
    set_solid(cyl.Solid());
    assign_color();
}

} // namespace formo
