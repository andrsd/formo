// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/pattern.h"
#include "formo/axis2.h"

namespace formo {

/// Hexagonal pattern
class HexagonalPattern : public Pattern {
public:
    HexagonalPattern(const Axis2 & center, double flat_to_flat, int side_segs);

private:
    /// Center of the pattern
    Axis2 center;
    /// Flat to flat distance
    double flat_to_flat;
    /// Number of segments per side
    int num_side_segs;
};

} // namespace formo
