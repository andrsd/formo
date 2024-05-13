// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/edge.h"
#include "formo/shape.h"
#include "TopoDS_Wire.hxx"
#include <vector>

namespace formo {

class Wire : public Shape {
public:
    explicit Wire(const TopoDS_Wire & wire);
    Wire(const std::vector<Edge *> & edges);

    operator TopoDS_Wire() const;

private:
    TopoDS_Wire wire;
};

} // namespace formo
