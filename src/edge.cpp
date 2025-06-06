// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/edge.h"

namespace formo {

Edge::Edge() {}

Edge::Edge(const TopoDS_Edge & edge) : Shape(), edge_(edge) {}

void
Edge::set_edge(const TopoDS_Edge & edge)
{
    this->edge_ = edge;
}

Edge::operator TopoDS_Edge() const
{
    return this->edge_;
}

} // namespace formo
