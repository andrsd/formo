// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "gp_Pnt.hxx"
#include "TopoDS_Vertex.hxx"

namespace formo {

class Vector;
class Axis1;
class Axis2;

/// Defines a 3D cartesian point
class Point : public Shape {
public:
    Point() = default;

    /// Creates a point with its 3 cartesian coordinates
    ///
    /// @param x x-coordinate
    /// @param y y-coordinate
    /// @param z z-coordinate
    Point(double x, double y, double z);

    explicit Point(const gp_Pnt & pt);

    /// X-coordinate of this point
    double x() const;
    /// Y-coordinate of this point
    double y() const;
    /// Z-coordinate of this point
    double z() const;

    operator gp_Pnt() const;

    bool is_equal(const Point & other, double tol = 1e-15) const;

    /// Computes the distance between two points.
    ///
    /// @param pt Point to measure distance to
    /// @return Distance between this point and `pt`
    double distance(const Point & pt) const;

    /// Performs the symmetrical transformation of a point with respect to the point `pt` which is
    /// the center of the symmetry.
    ///
    /// @param pt Point of symmetry
    void mirror(const Point & pt);

    /// Performs the symmetrical transformation of a point with respect to an axis placement which
    /// is the axis of the symmetry
    ///
    /// @param ax1 Axis placement
    void mirror(const Axis1 & ax1);

    /// Performs the symmetrical transformation of a point with respect to a plane.
    ///
    /// @param ax2 The axis placement ax2 locates the plane of the symmetry
    void mirror(const Axis2 & ax2);

    /// Performs the symmetrical transformation of a point with respect to the point `pt` which is
    /// the center of the symmetry.
    ///
    /// @param pt Point of symmetry
    /// @return Mirrored point
    Point mirrored(const Point & pt) const;

    /// Performs the symmetrical transformation of a point with respect to an axis placement which
    /// is the axis of the symmetry
    ///
    /// @param ax1 Axis placement
    /// @return Mirrored point
    Point mirrored(const Axis1 & ax1) const;

    /// Performs the symmetrical transformation of a point with respect to a plane.
    ///
    /// @param ax2 The axis placement ax2 locates the plane of the symmetry
    /// @return Mirrored point
    Point mirrored(const Axis2 & ax2) const;

    /// Rotate the point
    ///
    /// @param ax1 The axis of the rotation.
    /// @param angle The angular value of the rotation in radians.
    void rotate(const Axis1 & ax1, double angle);

    /// Rotate the point
    ///
    /// @param ax1 The axis of the rotation.
    /// @param angle The angular value of the rotation in radians.
    /// @return Rotate point
    Point rotated(const Axis1 & ax1, double angle) const;

    /// Scales a point
    ///
    /// @param pt Point that the scaling is relative to
    /// @param s The scaling value.
    void scale(const Point & pt, double s);

    /// Scales a point
    ///
    /// @param pt Point that the scaling is relative to
    /// @param s The scaling value.
    /// @return Scaled point
    Point scaled(const Point & pt, double s) const;

    /// Translates a point in the direction of the vector `vec`. The magnitude of the translation is
    /// the vector's magnitude.
    ///
    /// @param vec The vector of translation
    void translate(const Vector & vec);

    /// Translates a point from point `p1` to point `p2`
    ///
    /// @param p1 First point
    /// @param p2 Second point
    void translate(const Point & p1, const Point & p2);

    /// Translates a point in the direction of the vector `vec`. The magnitude of the translation is
    /// the vector's magnitude.
    ///
    /// @param vec The vector of translation
    /// @return Translated point
    Point translated(const Vector & vec) const;

    /// Translates a point from point `p1` to point `p2`
    ///
    /// @param p1 First point
    /// @param p2 Second point
    /// @return Translated point
    Point translated(const Point & p1, const Point & p2) const;

private:
    gp_Pnt pnt;
    TopoDS_Vertex vtx;
};

/// Operator for `Point` + `Point`
Point operator+(const Point & a, const Point & b);

/// Operator for `Point` + `Vector`
Point operator+(const Point & pt, const Vector & v);

} // namespace formo
