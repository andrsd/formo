// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/point.h"
#include <vector>

namespace formo {

/// Base class for patterns
class Pattern {
public:
    Pattern();

    ///
    const std::vector<Point> & points() const;

protected:
    void set_points(const std::vector<Point> & point);

private:
    std::vector<Point> pts;
};

} // namespace formo
