// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/edge.h"
#include "GProp_GProps.hxx"
#include "BRepGProp.hxx"

namespace formo {

Edge::Edge() {}

Edge::Edge(const TopoDS_Edge & edge) : Shape(), edge(edge) {}

double
Edge::length() const
{
    GProp_GProps props;
    BRepGProp::LinearProperties(this->edge, props);
    return props.Mass();
}

void
Edge::set_edge(const TopoDS_Edge & edge)
{
    this->edge = edge;
}

Edge::operator TopoDS_Edge() const
{
    return this->edge;
}

} // namespace formo
