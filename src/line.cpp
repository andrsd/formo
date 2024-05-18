// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/line.h"
#include "formo/exception.h"
#include "BRepBuilderAPI_MakeEdge.hxx"

namespace formo {

Line::Line(const Point & pt1, const Point & pt2)
{
    BRepBuilderAPI_MakeEdge maker(pt1, pt2);
    maker.Build();
    if (!maker.IsDone())
        throw Exception("Edge was not created");
    set_shape(maker.Shape());
    set_edge(maker.Edge());
}

} // namespace formo
