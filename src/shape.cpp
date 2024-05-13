// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/shape.h"

namespace formo {

Shape::Shape() {}

Shape::Shape(const TopoDS_Shape & shape) {}

std::string
Shape::name() const
{
    return this->nm;
}

void
Shape::name(const std::string & name)
{
    this->nm = name;
}

Shape::operator TopoDS_Shape() const
{
    return this->shp;
}

} // namespace formo
