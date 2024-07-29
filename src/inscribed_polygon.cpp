// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/inscribed_polygon.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
#include "formo/point.h"
#include "formo/vector.h"
#include "formo/exception.h"
#include "BRepBuilderAPI_MakePolygon.hxx"

namespace formo {

InscribedPolygon::InscribedPolygon(const Axis2 & ax2, double radius, int sides) :
    Wire(),
    radius(radius),
    n_sides(sides)
{
    if (sides < 3)
        throw Exception("InscribedPolygon needs at least 3 sides");

    auto r_out = radius / (0.5 * std::sqrt(3));
    auto points = build_points(ax2, r_out * ax2.x_direction());
    auto polygon = build_polygon(points);
    set_wire(polygon);
}

InscribedPolygon::InscribedPolygon(const Axis2 & ax2, const Point & pt1, int sides) :
    Wire(),
    radius(0.),
    n_sides(sides)
{
    if (sides < 3)
        throw Exception("InscribedPolygon needs at least 3 sides");

    auto vec = Vector(ax2.location(), pt1);
    this->radius = vec.magnitude();
    auto r_out = this->radius / (0.5 * std::sqrt(3));
    auto points = build_points(ax2, r_out * vec);
    auto polygon = build_polygon(points);
    set_wire(polygon);
}

std::vector<Point>
InscribedPolygon::build_points(const Axis2 & ax2, const Vector & start_vec)
{
    std::vector<Point> points;
    auto ctr_pt = ax2.location();
    Axis1 ctr_ax1(ctr_pt, ax2.direction());
    auto dangle = 2 * M_PI / n_sides;
    for (int i = 0; i < n_sides; i++) {
        auto vec = start_vec.rotated(ctr_ax1, i * dangle);
        auto pt1 = ctr_pt + vec;
        points.emplace_back(pt1);
    }
    return points;
}

TopoDS_Wire
InscribedPolygon::build_polygon(const std::vector<Point> & points)
{
    BRepBuilderAPI_MakePolygon polygon;
    for (auto & pt : points)
        polygon.Add(pt);
    polygon.Close();
    polygon.Build();
    if (!polygon.IsDone())
        throw Exception("Polygon was not created");
    return polygon.Wire();
}

} // namespace formo
