// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "TopoDS_Solid.hxx"

namespace formo {

class Solid : public Shape {
public:
    Solid() = default;
    explicit Solid(const TopoDS_Solid & solid);

    /// Compute the volume of the shape
    ///
    /// @return Volume of the shape
    double volume() const;

    operator TopoDS_Solid() const;

private:
    TopoDS_Solid solid;
};

} // namespace formo
