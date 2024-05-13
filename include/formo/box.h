// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/solid.h"
#include "formo/shell.h"
#include "formo/point.h"
#include "BRepPrimAPI_MakeBox.hxx"

namespace formo {

/// Box
class Box : public Solid {
public:
    Box(const Point & pt1, const Point & pt2);

    Shell shell();

private:
    BRepPrimAPI_MakeBox box;
};

} // namespace formo
