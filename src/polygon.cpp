// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/polygon.h"
#include "formo/exception.h"
#include "BRepBuilderAPI_MakePolygon.hxx"

namespace formo {

Polygon::Polygon(const std::vector<Point> & points, bool closed) : Shape()
{
    if (points.size() < 3)
        throw Exception("Polygon needs at least 3 points");
    BRepBuilderAPI_MakePolygon polygon;
    for (auto & pt : points)
        polygon.Add((gp_Pnt) pt);
    if (closed)
        polygon.Close();
    polygon.Build();
    if (!polygon.IsDone())
        throw Exception("Polygon was not created");
    set_shape(polygon.Shape());
    this->edge = polygon.Edge();
    this->wire = polygon.Wire();
}

Edge
Polygon::as_edge() const
{
    return Edge(this->edge);
}

Wire
Polygon::as_wire() const
{
    return Wire(this->wire);
}

} // namespace formo
