// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/shape.h"
#include "formo/color_map.h"
#include <vector>

namespace formo {

namespace {

std::vector<Color> shape_color = { ColorMap::medium_blue, ColorMap::medium_grey,
                                   ColorMap::dark_blue,   ColorMap::light_grey,
                                   ColorMap::light_blue,  ColorMap::orange,
                                   ColorMap::dark_grey,   ColorMap::yellow };

Color
get_next_color()
{
    static int color_index = 0;
    Color clr = shape_color[color_index];
    color_index++;
    return clr;
}

} // namespace

Shape::Shape() : clr(get_next_color()) {}

Shape::Shape(const TopoDS_Shape & shape) : clr(get_next_color()) {}

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

Color
Shape::color() const
{
    return this->clr;
}

void
Shape::set_color(const Color & color)
{
    this->clr = clr;
}

Shape::operator TopoDS_Shape() const
{
    return this->shp;
}

} // namespace formo
