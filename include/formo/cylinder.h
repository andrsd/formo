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
    Cylinder(const Axis2 & axis, double radius, double height);
};

} // namespace formo
