// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "gp_Vec.hxx"

namespace formo {

class Direction;
class Point;
class Axis1;

/// Non-persistent vector in 3D space
class Vector {
public:
    Vector(const gp_Vec & vec);

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

    /// Computes the magnitude of this vector
    ///
    /// @return Magnitude of the vector
    double magnitude() const;

    /// Rotate the vector
    ///
    /// @param ax1 The axis of the rotation.
    /// @param angle The angular value of the rotation in radians.
    void rotate(const Axis1 & ax1, const double angle);

    /// Rotates a vector.
    ///
    /// @param ax1 The axis of the rotation.
    /// @param angle The angular value of the rotation in radians.
    Vector rotated(const Axis1 & ax1, const double angle) const;

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
