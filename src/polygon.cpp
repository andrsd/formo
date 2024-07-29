// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/polygon.h"
#include "formo/exception.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
#include "formo/vector.h"

namespace formo {

Polygon::Polygon(const std::vector<Point> & points, bool closed) : Wire()
{
    if (points.size() < 3)
        throw Exception("Polygon needs at least 3 points");
    auto polygon = build_polygon(points, closed);
    set_wire(polygon.Wire());
    set_shape(polygon.Shape());
}

std::vector<Point>
Polygon::build_points(const Axis2 & ax2, const Vector & start_vec, int n_sides)
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

BRepBuilderAPI_MakePolygon
Polygon::build_polygon(const std::vector<Point> & points, bool closed)
{
    BRepBuilderAPI_MakePolygon polygon;
    for (auto & pt : points)
        polygon.Add(pt);
    if (closed)
        polygon.Close();
    polygon.Build();
    if (!polygon.IsDone())
        throw Exception("Polygon was not created");
    return polygon;
}

} // namespace formo
