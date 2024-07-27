// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "gp_Vec.hxx"

namespace formo {

class Direction;
class Point;

/// Non-persistent vector in 3D space
class Vector {
public:
    Vector(double x, double y, double z);

    /// Construct a `Vector` from a `Direction`
    ///
    /// @param dir Direction
    Vector(const Direction & dir);

    /// Construct a `Vector` from two `Points`
    ///
    /// @param pt1 First point
    /// @param pt2 Second point
    Vector(const Point & pt1, const Point & pt2);

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

/// Multiply vector by a scalar
///
/// @param alpha Scalar to multiply the vector with
/// @return Resulting vector
Vector operator*(double alpha, const Vector & vec);

} // namespace formo
