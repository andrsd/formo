// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/edge.h"
#include "formo/point.h"

namespace formo {

class Line : public Edge {
public:
    Line(const Point & pt1, const Point & pt2);
};

} // namespace formo
