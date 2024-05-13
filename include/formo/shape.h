// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "TopoDS_Shape.hxx"
#include <string>

namespace formo {

class Shape {
public:
    Shape();
    explicit Shape(const TopoDS_Shape & shape);

    /// Get shape name
    ///
    /// @return Shape name
    std::string name() const;

    /// Set shape name
    ///
    /// @param name New shape name
    void name(const std::string & name);

    ///
    operator TopoDS_Shape() const;

private:
    /// Shape name
    std::string nm;
    /// Open CASCADE shape
    TopoDS_Shape shp;
};

} // namespace formo
