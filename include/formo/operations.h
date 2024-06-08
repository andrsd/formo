// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "formo/edge.h"
#include "formo/face.h"
#include "formo/vector.h"

namespace formo {

class Axis1;
class Axis2;

/// Translate a shape
///
/// @param shape Shape to translate
/// @param v Translation vector
/// @return Translated shape
Shape translate(const Shape & shape, const Vector & v);

/// Translate a shape
///
/// @param shape Shape to translate
/// @param p1 Point one of the translation vector
/// @param p2 Point two of the translation vector
/// @return Translated shape
Shape translate(const Shape & shape, const Point & p1, const Point & p2);

/// Scale a shape
///
/// @param shape Shape to scale
/// @param s Scale factor
/// @return Scaled shape
Shape scale(const Shape & shape, double s);

/// Scale a vector
///
/// @param vec Vector to scale
/// @param s Scale factor
/// @return Scaled vector
Vector scale(const Vector & vec, double s);

/// Mirror a shape about an axis
///
/// @param shape Shape to mirror
/// @param axis Axis to mirror about
/// @return Resulting shape
Shape mirror(const Shape & shape, const Axis1 & axis);

/// Mirror a vector about an axis
///
/// @param shape Vector to mirror
/// @param axis Axis to mirror about
/// @return Resulting vector
Vector mirror(const Vector & vector, const Axis1 & axis);

/// Mirror a vector about an axis
///
/// @param shape Vector to mirror
/// @param axis Axis to mirror about
/// @return Resulting vector
Vector mirror(const Vector & vector, const Axis2 & axis);

/// Mirror a point about an axis
///
/// @param point Point to mirror
/// @param axis Axis to mirror about
/// @return Resulting point
Point mirror(const Point & point, const Axis1 & axis);

/// Mirror a point about an axis
///
/// @param point Point to mirror
/// @param axis Axis to mirror about
/// @return Resulting point
Point mirror(const Point & point, const Axis2 & axis);

/// Fuse 2 shapes
///
/// @param shape Shape
/// @param tool Tool
/// @return Resulting fused shape
Shape fuse(const Shape & shape, const Shape & tool);

/// Cut a shape with a tool
///
/// @param shape Shape to cut
/// @param tool Cutting tool
/// @return Resulting shape
Shape cut(const Shape & shape, const Shape & tool);

/// Intersect 2 shapes
///
/// @param shape Shape
/// @param tool Tool
/// @return Resulting shape
Shape intersect(const Shape & shape, const Shape & tool);

/// Fillet
///
/// @param shape Shape to fillet
/// @param edges List of edges to fillet
/// @param radius Radius of the fillet
/// @return Resulting shape
Shape fillet(const Shape & shape, const std::vector<Edge> & edges, double radius);

/// Hollow the shape
///
/// @param shape Shape to hollow
/// @param faces_to_remove Faces to open
/// @param thickness Desired wall thickness
/// @param tolerance Tolerance
/// @return Hollowed out shape
Shape hollow(const Shape & shape,
             const std::vector<Face> & faces_to_remove,
             double thickness,
             double tolerance);

/// Extrude a shape
///
/// @param shape Shape to extrude
/// @param vec Vector of extrusion
/// @return Resulting shape
Shape extrude(const Shape & shape, const Vector & vec);

/// Revolve shape about an axis
///
/// @param shape Shape to revolve
/// @param axis Axis to revolve about
/// @param angle Angle to revolve
/// @return Resulting shape
Shape revolve(const Shape & shape, const Axis1 & axis, double angle = 2. * M_PI);

/// Rotate point about an axis
///
/// @param point Point to rotate
/// @param axis Axis to rotate about
/// @param angle Rotation angle (in radians)
/// @return Resulting Point
Point rotate(const Point & point, const Axis1 & axis, double angle);

/// Rotate vector about an axis
///
/// @param vector Vector to rotate
/// @param axis Axis to rotate about
/// @param angle Rotation angle (in radians)
/// @return Resulting vector
Vector rotate(const Vector & vector, const Axis1 & axis, double angle);

/// Compute section between a shape and a plane
///
/// @param shape Shape
/// @param plane Plane
/// @return Wire that forms the computed section
Wire section(const Shape & shape, const Plane & plane);

} // namespace formo
