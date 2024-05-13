// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "gp_Vec.hxx"

namespace formo {

/// Non-persistent vector in 3D space
class Vector {
public:
    Vector(double x, double y, double z);

    /// Get the x-component of the vector
    double x() const;
    /// Get the y-component of the vector
    double y() const;
    /// Get the z-component of the vector
    double z() const;

    operator gp_Vec() const;

private:
    gp_Vec vec;
};

} // namespace formo
