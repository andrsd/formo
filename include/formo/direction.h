// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "gp_Dir.hxx"

namespace formo {

class Vector;
class Axis1;
class Axis2;

class Direction {
public:
    Direction(double x, double y, double z);

    /// Construct a `Direction` from a `Vector`
    Direction(const Vector & vec);

    /// Construct a `Direction` from a `gp_Dir`
    Direction(const gp_Dir & dir);

    /// Get the x-component of the direction
    double x() const;
    /// Get the y-component of the direction
    double y() const;
    /// Get the z-component of the direction
    double z() const;

    /// Check if 2 directions are equal.
    ///
    /// @param other Other direction to compare
    /// @param ang_tol Precision value for the direction
    /// @return `true` if the angle between the two directions is lower or equal to `ang_tol`
    bool is_equal(const Direction & other, double ang_tol) const;

    /// Check if another direction is normal to this direction
    ///
    /// @param other Other direction
    /// @param ang_tol Angular tolerance
    /// @return `true` if the angle between this unit vector and the unit vector `other` is equal to
    /// `PI/2`
    bool is_normal(const Direction & other, double ang_tol) const;

    /// Check if another direction is opposite to this direction
    ///
    /// @param other Other direction
    /// @param Angular tolerance
    /// @return `true` if the directions have opposite orientations, `false` otherwise
    bool is_opposite(const Direction & other, double ang_tol) const;

    /// Check if another direction is parallel to this direction
    ///
    /// @param other Other direction
    /// @param Angular tolerance
    /// @return `true` if the directions are parallel, `false` otherwise
    bool is_parallel(const Direction & other, double ang_tol) const;

    /// Performs the symmetrical transformation of a vector with respect to the vector `vec` which
    /// is the center of the symmetry.
    ///
    /// @param v Center of symmetry
    void mirror(const Direction & v);

    /// Performs the symmetrical transformation of a vector with respect to an axis placement which
    /// is the axis of the symmetry
    ///
    /// @param ax1 Axis placement
    void mirror(const Axis1 & ax1);

    /// Performs the symmetrical transformation of a vector with respect to a plane.
    ///
    /// @param ax2 The axis placement `ax2` locates the plane of the symmetry
    void mirror(const Axis2 & ax2);

    /// Performs the symmetrical transformation of a vector with respect to the vector `v` which is
    /// the center of the symmetry.
    ///
    /// @param v Center of symmetry
    /// @return Mirrored point
    Direction mirrored(const Direction & v) const;

    /// Performs the symmetrical transformation of a vector with respect to an axis placement which
    /// is the axis of the symmetry
    ///
    /// @param ax1 Axis placement
    /// @return Mirrored point
    Direction mirrored(const Axis1 & ax1) const;

    /// Performs the symmetrical transformation of a vector with respect to a plane.
    ///
    /// @param ax2 The axis placement ax2 locates the plane of the symmetry
    /// @return Mirrored point
    Direction mirrored(const Axis2 & ax2) const;

    /// Rotate the vector
    ///
    /// @param ax1 The axis of the rotation.
    /// @param angle The angular value of the rotation in radians.
    void rotate(const Axis1 & ax1, const double angle);

    /// Rotates a vector.
    ///
    /// @param ax1 The axis of the rotation.
    /// @param angle The angular value of the rotation in radians.
    Direction rotated(const Axis1 & ax1, const double angle) const;

    /// Reverses the orientation of the direction
    void reverse();

    /// Reverses the orientation of the direction
    ///
    /// @return Direction with inverted orientation
    Direction reversed() const;

    operator gp_Dir() const;

    /// Invert the orientation of the direction
    ///
    /// @return Direction with opposite orientation
    Direction operator-() const;

private:
    gp_Dir dir;
};

/// Computes the scalar product between v1 and v2
///
/// @param v1 First direction
/// @param v2 Second direction
/// @return Dot product
double dot_product(const Direction & v1, const Direction & v2);

} // namespace formo
