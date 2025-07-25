// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/inscribed_polygon.h"
#include "formo/axis2.h"
#include "formo/point.h"
#include "formo/vector.h"
#include "formo/exception.h"
#include "BRepBuilderAPI_MakePolygon.hxx"

namespace formo {

InscribedPolygon::InscribedPolygon(const Axis2 & ax2, double radius, int sides) :
    Polygon(),
    radius_(radius),
    n_sides_(sides)
{
    if (sides < 3)
        throw Exception("CircumscribedPolygon needs at least 3 sides");

    auto points = build_points(ax2, radius * ax2.x_direction(), this->n_sides_);
    auto polygon = build_polygon(points, true);
    set_wire(polygon.Wire());
    set_shape(polygon.Shape());
}

InscribedPolygon::InscribedPolygon(const Axis2 & ax2, const Point & pt1, int sides) :
    Polygon(),
    radius_(0.),
    n_sides_(sides)
{
    if (sides < 3)
        throw Exception("CircumscribedPolygon needs at least 3 sides");

    auto vec = Vector(ax2.location(), pt1);
    this->radius_ = vec.magnitude();
    auto points = build_points(ax2, vec, this->n_sides_);
    auto polygon = build_polygon(points, true);
    set_wire(polygon.Wire());
    set_shape(polygon.Shape());
}

} // namespace formo
