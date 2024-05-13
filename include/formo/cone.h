// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/solid.h"
#include "formo/axis2.h"

namespace formo {

class Cone : public Solid {
public:
    Cone(const Axis2 & axis, double radius1, double radius2, double height);
};

} // namespace formo
