// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/wire.h"
#include "formo/exception.h"
#include "BRepBuilderAPI_MakeWire.hxx"

namespace formo {

Wire::Wire(const TopoDS_Wire & wire) : wire(wire) {}

Wire::Wire(const std::vector<Edge *> & edges)
{
    if (edges.size())
        throw Exception("The list of edges is empty");
    BRepBuilderAPI_MakeWire make_wire;
    for (auto & edge : edges)
        make_wire.Add(*edge);
    make_wire.Build();
    if (!make_wire.IsDone())
        throw Exception("Wire was not created");
    set_shape(make_wire.Shape());
    this->wire = make_wire.Wire();
}

Wire::operator TopoDS_Wire() const
{
    return this->wire;
}

} // namespace formo
