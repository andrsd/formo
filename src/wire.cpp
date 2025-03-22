// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/wire.h"
#include "formo/exception.h"
#include "formo/direction.h"
#include "formo/shell.h"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepOffsetAPI_MakeDraft.hxx"
#include "TopoDS.hxx"
#include "GProp_GProps.hxx"
#include "BRepGProp.hxx"

namespace formo {

Wire::Wire(const TopoDS_Wire & wire) : wire(wire) {}

Wire::Wire(const std::vector<Edge> & edges)
{
    if (edges.size() == 0)
        throw Exception("The list of edges is empty");
    BRepBuilderAPI_MakeWire make_wire;
    for (auto & edge : edges)
        make_wire.Add(edge);
    make_wire.Build();
    if (!make_wire.IsDone())
        throw Exception("Wire was not created");
    set_shape(make_wire.Shape());
    this->wire = make_wire.Wire();
}

void
Wire::set_wire(const TopoDS_Wire & wire)
{
    this->wire = wire;
}

Shell
Wire::draft(const Direction & dir, double angle, double length) const
{
    BRepOffsetAPI_MakeDraft mk(this->wire, dir, angle);
    mk.Perform(length);
    mk.Build();
    if (mk.IsDone())
        return TopoDS::Shell(mk.Shape());
    else
        throw Exception("Draft of wire failed to create");
}

Wire::operator TopoDS_Wire() const
{
    return this->wire;
}

} // namespace formo
