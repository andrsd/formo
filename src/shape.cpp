// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/shape.h"
#include "formo/color_map.h"
#include "formo/point.h"
#include "TopExp_Explorer.hxx"
#include "TopTools_DataMapOfShapeInteger.hxx"
#include "TopoDS.hxx"
#include "TopoDS_Vertex.hxx"
#include "BRep_Tool.hxx"
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
    color_index = (color_index + 1) % shape_color.size();
    return clr;
}

} // namespace

Shape::Shape() : clr(ColorMap::light_blue) {}

Shape::Shape(const TopoDS_Shape & shape) : clr(ColorMap::light_blue), shp(shape) {}

std::string
Shape::name() const
{
    return this->nm;
}

void
Shape::set_name(const std::string & name)
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
    this->clr = color;
}

void
Shape::set_shape(const TopoDS_Shape & shape)
{
    this->shp = shape;
}

void
Shape::assign_color()
{
    this->clr = get_next_color();
}

std::vector<Point>
Shape::vertices() const
{
    std::vector<Point> vertices;
    TopExp_Explorer exp0;
    TopTools_DataMapOfShapeInteger id_map;
    for (exp0.Init(this->shp, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
        auto vertex = TopoDS::Vertex(exp0.Current());
        if (!id_map.IsBound(vertex)) {
            auto id = vertices.size() + 1;
            id_map.Bind(vertex, id);
            vertices.emplace_back(Point(BRep_Tool::Pnt(vertex)));
        }
    }
    return vertices;
}

Shape::operator TopoDS_Shape() const
{
    return this->shp;
}

} // namespace formo
