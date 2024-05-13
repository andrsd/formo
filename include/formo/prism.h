// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "formo/vector.h"

namespace formo {

class Prism : public Shape {
public:
    Prism(const Shape & shape, const Vector & vec);
};

} // namespace formo
