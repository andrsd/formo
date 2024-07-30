// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "gp_Pnt.hxx"
#include "TopoDS_Vertex.hxx"

namespace formo {

class Vector;
class Axis1;

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

    double distance(const Point & pt) const;

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

    /// Translates a point in the direction of the vector `vec`. The magnitude of the translation is
    /// the vector's magnitude.
    ///
    /// @param vec The vector of translation
    void translate(const Vector & vec);

    /// Translates a point in the direction of the vector `vec`. The magnitude of the translation is
    /// the vector's magnitude.
    ///
    /// @param vec The vector of translation
    Point translated(const Vector & vec) const;

private:
    gp_Pnt pnt;
    TopoDS_Vertex vtx;
};

/// Operator for `Point` + `Vector`
Point operator+(const Point & pt, const Vector & v);

} // namespace formo
