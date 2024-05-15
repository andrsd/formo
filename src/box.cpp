// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/box.h"
#include "formo/exception.h"
#include "BRepPrimAPI_MakeBox.hxx"

namespace formo {

Box::Box(const Point & pt1, const Point & pt2) : Solid()
{
    BRepPrimAPI_MakeBox box(pt1, pt2);
    box.Build();
    if (!box.IsDone())
        throw Exception("Box was not created");
    set_shape(box.Shape());
    set_solid(box.Solid());
    assign_color();
}

} // namespace formo
