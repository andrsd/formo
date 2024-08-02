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

    /// Check if 2 vectors have the same magnitude value and the same direction.
    ///
    /// @param other Other vector to compare
    /// @param lin_tol Precision value for the magnitude
    /// @param ang_tol Precision value for the direction
    bool is_equal(const Vector & other, double lin_tol, double ang_tol) const;

    /// Check if another vector is normal to this vector
    ///
    /// @param other Other vector
    /// @param ang_tol Angular tolerance
    /// @return `true` if abs(<me>.angle(other) - PI/2.) <= ang_tol
    bool is_normal(const Vector & other, double ang_tol) const;

    /// Check if another vector is opposite to this vector
    ///
    /// @param other Other vector
    /// @param Angular tolerance
    bool is_opposite(const Vector & other, double ang_tol) const;

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

    /// Scales a vector
    ///
    /// @param s The scaling value
    void scale(double s);

    /// Scales a vector
    ///
    /// @param s The scaling value
    Vector scaled(double s) const;

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
