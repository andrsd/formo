// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "gp_Pnt.hxx"
#include "TopoDS_Vertex.hxx"

namespace formo {

class Vector;

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

private:
    gp_Pnt pnt;
    TopoDS_Vertex vtx;
};

/// Operator for `Point` + `Vector`
Point operator+(const Point & pt, const Vector & v);

} // namespace formo
