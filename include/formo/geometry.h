// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/axis1.h"

namespace formo {

class Geometry {
public:
    static Axis1 OX;
    static Axis1 OY;
    static Axis1 OZ;

    static Direction DX;
    static Direction DY;
    static Direction DZ;
};

} // namespace formo
