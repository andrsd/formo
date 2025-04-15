// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/point.h"
#include "formo/direction.h"
#include "gp_Pln.hxx"

namespace formo {

class Axis1;

/// Describes a plane.
///
/// A plane is positioned in space with a coordinate system (a `gp_Ax3` object), such that the plane
/// is defined by the origin, "X Direction" and "Y Direction" of this coordinate system, which is
/// the "local coordinate system" of the plane. The "main Direction" of the coordinate system is a
/// vector normal to the plane. It gives the plane an implicit orientation such that the plane is
/// said to be "direct", if the coordinate system is right-handed, or "indirect" in the other case.
/// Note: when a `gp_Pln` plane is converted into a `Geom_Plane` plane, some implicit properties of
/// its local coordinate system are used explicitly:
///
/// - its origin defines the origin of the two parameters of the planar surface,
/// - its implicit orientation is also that of the `Geom_Plane`. See Also `gce_MakePln` which
///   provides functions for more  complex plane constructions, `Geom_Plane` which provides
///   additional functions for constructing planes and works, in particular, with the parametric
///   equations of planes
class Plane {
public:
    /// Construct a plane with location `pt` and normal direction `normal`
    ///
    /// @param pt Location of the plane
    /// @param normal Normal direction
    Plane(const Point & pt, const Direction & normal);

    explicit Plane(const gp_Pln & pln);

    /// Location of this plane
    Point location() const;

    /// Returns the plane's normal axis
    Axis1 axis() const;

    /// Returns the X axis of the plane
    Axis1 x_axis() const;

    /// Returns the Y axis of the plane
    Axis1 y_axis() const;

    operator gp_Pln() const;

private:
    gp_Pln pln_;
};

} // namespace formo
