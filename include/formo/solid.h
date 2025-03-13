// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "TopoDS_Solid.hxx"

namespace formo {

class Shell;

class Solid : public Shape {
public:
    Solid() = default;

    explicit Solid(const TopoDS_Solid & solid);

    /// Create a solid from a shell
    ///
    /// @param shell Shell to create the solid from
    explicit Solid(const Shell & shell);

    /// Compute the volume of the shape
    ///
    /// @return Volume of the shape
    double volume() const;

    operator TopoDS_Solid() const;

protected:
    void set_solid(const TopoDS_Solid & solid);

private:
    TopoDS_Solid solid;
};

} // namespace formo
