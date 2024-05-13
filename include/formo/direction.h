// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "gp_Dir.hxx"

namespace formo {

class Direction {
public:
    Direction(double x, double y, double z);

    /// Get the x-component of the direction
    double x() const;
    /// Get the y-component of the direction
    double y() const;
    /// Get the z-component of the direction
    double z() const;

    operator gp_Dir() const;

private:
    gp_Dir dir;
};

} // namespace formo
