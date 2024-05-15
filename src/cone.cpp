// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/cone.h"
#include "formo/exception.h"
#include "BRepPrimAPI_MakeCone.hxx"

namespace formo {

Cone::Cone(const Axis2 & axis, double radius1, double radius2, double height)
{
    BRepPrimAPI_MakeCone cone(axis, radius1, radius2, height);
    cone.Build();
    if (!cone.IsDone())
        throw Exception("Cone was not created");
    set_shape(cone.Shape());
    set_solid(cone.Solid());
    assign_color();
}

} // namespace formo
