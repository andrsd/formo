// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/circumscribed_polygon.h"
#include "formo/axis2.h"
#include "formo/point.h"
#include "formo/polygon.h"
#include "formo/vector.h"
#include "formo/exception.h"
#include "BRepBuilderAPI_MakePolygon.hxx"

namespace formo {

CircumscribedPolygon::CircumscribedPolygon(const Axis2 & ax2, double radius, int sides) :
    Polygon(),
    radius_(radius),
    n_sides_(sides)
{
    if (sides < 3)
        throw Exception("InscribedPolygon needs at least 3 sides");

    auto r_out = radius / (0.5 * std::sqrt(3));
    auto points = build_points(ax2, r_out * ax2.x_direction(), this->n_sides_);
    auto polygon = build_polygon(points, true);
    set_wire(polygon);
    set_shape(polygon.Shape());
}

CircumscribedPolygon::CircumscribedPolygon(const Axis2 & ax2, const Point & pt1, int sides) :
    Polygon(),
    radius_(0.),
    n_sides_(sides)
{
    if (sides < 3)
        throw Exception("InscribedPolygon needs at least 3 sides");

    auto vec = Vector(ax2.location(), pt1);
    this->radius_ = vec.magnitude();
    auto r_out = this->radius_ / (0.5 * std::sqrt(3));
    auto points = build_points(ax2, r_out * vec, this->n_sides_);
    auto polygon = build_polygon(points, true);
    set_wire(polygon);
    set_shape(polygon.Shape());
}

} // namespace formo
