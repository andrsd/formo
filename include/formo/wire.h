// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/edge.h"
#include "formo/shape.h"
#include "TopoDS_Wire.hxx"
#include <vector>

namespace formo {

class Direction;
class Shell;

class Wire : public Shape {
public:
    Wire() = default;
    explicit Wire(const TopoDS_Wire & wire);
    Wire(const std::vector<Edge> & edges);

    /// Constructs the draft surface object defined by the wire, the direction, and the angle.
    ///
    /// @param dir Direction
    /// @param angle Angle [radians]
    /// @param length Length of the draft
    Shell draft(const Direction & dir, double angle, double length) const;

    operator TopoDS_Wire() const;

protected:
    void set_wire(const TopoDS_Wire & wire);

private:
    TopoDS_Wire wire_;
};

} // namespace formo
