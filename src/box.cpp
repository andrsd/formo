// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/box.h"
#include "formo/exception.h"
#include "BRepPrimAPI_MakeBox.hxx"

namespace formo {

Box::Box(const Point & pt1, const Point & pt2) : Solid(), box(pt1, pt2)
{
    this->box.Build();
    if (!this->box.IsDone())
        throw Exception("Box was not created");
}

Shell
Box::shell()
{
    return Shell(this->box.Shell());
}

} // namespace formo
