// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/point.h"
#include "formo/direction.h"
#include "gp_Ax2.hxx"

namespace formo {

/// Describes a right-handed coordinate system in 3D space. A coordinate system is defined by:
///
/// - its origin (also referred to as its "Location point"), and
/// - three orthogonal unit vectors, termed respectively the "X Direction", the "Y Direction" and
///   the "Direction" (also referred to as the "main Direction"). The "Direction" of the coordinate
///   system is called its "main Direction" because whenever this unit vector is modified, the
///   "X Direction" and the "Y Direction" are recomputed. However, when we modify either the
///   "X Direction" or the "Y Direction", "Direction" is not modified. The "main Direction" is also
///   the "Z Direction". Since an Ax2 coordinate system is right-handed, its "main Direction" is
///   always equal to the cross product of its "X Direction" and "Y Direction". To define a
///   left-handed coordinate system, use `Axis3`.
///
/// A coordinate system is used:
///
/// - to describe geometric entities, in particular to position them. The local coordinate system of
///   a geometric entity serves the same purpose as the STEP function "axis placement two axes", or
/// - to define geometric transformations.
///
/// Note: we refer to the "X Axis", "Y Axis" and "Z Axis", respectively, as to axes having:
///
/// - the origin of the coordinate system as their origin, and
/// - the unit vectors "X Direction", "Y Direction" and "main Direction", respectively, as their
///   unit vectors. The "Z Axis" is also the "main Axis".
class Axis2 {
public:
    Axis2(const Point & pt, const Direction & direction);

    /// Creates an axis placement with an origin `pt` such that:
    /// - `n` is the Direction, and
    /// - the "X direction" is normal to `n`, in the plane defined by the vectors (`n`, `v_x`):
    ///   "X Direction" = (n ^ v_x) ^ n,
    ///
    /// Raises `Exception` if N and Vx are parallel (same or opposite orientation).
    Axis2(const Point & pt, const Direction & n, const Direction & v_x);

    /// Get location
    ///
    /// @return Location
    Point location() const;

    /// Returns the main axis
    ///
    /// @return The main location point and the main direction
    Axis1 axis() const;

    /// Get direction
    ///
    /// @return Direction
    Direction direction() const;

    /// Get x-direction
    ///
    /// @return x-direction
    Direction x_direction() const;

    /// Get y-direction
    ///
    /// @return x-direction
    Direction y_direction() const;

    operator gp_Ax2() const;

private:
    gp_Ax2 ax2_;
};

} // namespace formo
