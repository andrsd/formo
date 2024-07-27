// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/pattern.h"

namespace formo {

Pattern::Pattern() {}

const std::vector<Point> &
Pattern::points() const
{
    return this->pts;
}

void
Pattern::set_points(const std::vector<Point> & points)
{
    this->pts = points;
}

} // namespace formo
