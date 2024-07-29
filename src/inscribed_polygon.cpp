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
    radius(radius),
    n_sides(sides)
{
    if (sides < 3)
        throw Exception("InscribedPolygon needs at least 3 sides");

    auto r_out = radius / (0.5 * std::sqrt(3));
    auto points = build_points(ax2, r_out * ax2.x_direction(), n_sides);
    auto polygon = build_polygon(points, true);
    set_wire(polygon);
}

InscribedPolygon::InscribedPolygon(const Axis2 & ax2, const Point & pt1, int sides) :
    Polygon(),
    radius(0.),
    n_sides(sides)
{
    if (sides < 3)
        throw Exception("InscribedPolygon needs at least 3 sides");

    auto vec = Vector(ax2.location(), pt1);
    this->radius = vec.magnitude();
    auto r_out = this->radius / (0.5 * std::sqrt(3));
    auto points = build_points(ax2, r_out * vec, n_sides);
    auto polygon = build_polygon(points, true);
    set_wire(polygon);
}

} // namespace formo
