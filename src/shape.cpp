// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/shape.h"
#include "formo/color_map.h"
#include "formo/point.h"
#include "formo/edge.h"
#include "formo/face.h"
#include "formo/solid.h"
#include "TopExp_Explorer.hxx"
#include "TopTools_DataMapOfShapeInteger.hxx"
#include "TopoDS.hxx"
#include "TopoDS_Vertex.hxx"
#include "TopoDS_Edge.hxx"
#include "TopoDS_Solid.hxx"
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

std::vector<Edge>
Shape::edges() const
{
    std::vector<Edge> edges;
    TopExp_Explorer exp0;
    TopTools_DataMapOfShapeInteger id_map;
    for (exp0.Init(this->shp, TopAbs_EDGE); exp0.More(); exp0.Next()) {
        auto edge = TopoDS::Edge(exp0.Current());
        if (!id_map.IsBound(edge)) {
            auto id = edges.size() + 1;
            id_map.Bind(edge, id);
            edges.emplace_back(Edge(edge));
        }
    }
    return edges;
}

std::vector<Face>
Shape::faces() const
{
    std::vector<Face> faces;
    TopExp_Explorer exp0;
    TopTools_DataMapOfShapeInteger id_map;
    for (exp0.Init(this->shp, TopAbs_FACE); exp0.More(); exp0.Next()) {
        auto face = TopoDS::Face(exp0.Current());
        if (!id_map.IsBound(face)) {
            auto id = faces.size() + 1;
            id_map.Bind(face, id);
            faces.emplace_back(Face(face));
        }
    }
    return faces;
}

std::vector<Solid>
Shape::solids() const
{
    std::vector<Solid> solids;
    TopExp_Explorer exp0;
    TopTools_DataMapOfShapeInteger id_map;
    for (exp0.Init(this->shp, TopAbs_SOLID); exp0.More(); exp0.Next()) {
        auto solid = TopoDS::Solid(exp0.Current());
        if (!id_map.IsBound(solid)) {
            auto id = solids.size() + 1;
            id_map.Bind(solid, id);
            solids.emplace_back(Solid(solid));
        }
    }
    return solids;
}

Shape::operator TopoDS_Shape() const
{
    return this->shp;
}

} // namespace formo
