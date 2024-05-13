// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "formo/point.h"
#include "formo/edge.h"
#include "formo/wire.h"
#include <vector>

namespace formo {

class Polygon : public Shape {
public:
    Polygon(const std::vector<Point> & points, bool closed = true);

    /// Polygon as edge
    Edge as_edge() const;

    /// Polygon as wire
    Wire as_wire() const;

private:
    TopoDS_Edge edge;
    TopoDS_Wire wire;
};

} // namespace formo
