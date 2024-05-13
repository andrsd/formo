// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "TopoDS_Edge.hxx"

namespace formo {

class Edge : public Shape {
public:
    Edge();
    explicit Edge(const TopoDS_Edge & edge);

    /// Compute the length of the edge
    ///
    /// @return Length of the edge
    double length() const;

    operator TopoDS_Edge() const;

protected:
    void set_edge(const TopoDS_Edge & edge);

private:
    TopoDS_Edge edge;
};

} // namespace formo
