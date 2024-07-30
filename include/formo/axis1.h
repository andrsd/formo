// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/point.h"
#include "formo/direction.h"
#include "gp_Ax1.hxx"

namespace formo {

///  Describes an axis in 3D space. An axis is defined by:
///
/// - its origin (also referred to as its "Location point"), and
/// - its unit vector (referred to as its "Direction" or "main Direction").
///
/// An axis is used:
///
/// - to describe 3D geometric entities (for example, the axis of a revolution entity). It serves
///   the same purpose as the STEP function "axis placement one axis", or
/// - to define geometric transformations (axis of symmetry, axis of rotation, and so on).
/// For example, this entity can be used to locate a geometric entity or to define a symmetry axis.
class Axis1 {
public:
    Axis1(const gp_Ax1 & ax1);

    /// @param pt `Point` the location point
    /// @param direction `Direction` the direction of the axis
    Axis1(const Point & pt, const Direction & dir);

    /// Get location
    ///
    /// @return Location
    Point location() const;

    /// Get direction
    ///
    /// @return Direction
    Direction direction() const;

    operator gp_Ax1() const;

private:
    gp_Ax1 ax1;
};

} // namespace formo
