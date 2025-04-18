// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/shape.h"
#include "formo/color_map.h"
#include "formo/point.h"
#include "formo/edge.h"
#include "formo/face.h"
#include "formo/solid.h"
#include "formo/shell.h"
#include "formo/exception.h"
#include "TopExp_Explorer.hxx"
#include "TopTools_DataMapOfShapeInteger.hxx"
#include "TopoDS.hxx"
#include "TopoDS_Vertex.hxx"
#include "TopoDS_Edge.hxx"
#include "TopoDS_Shell.hxx"
#include "TopoDS_Solid.hxx"
#include "BRep_Tool.hxx"
#include "GProp_GProps.hxx"
#include "BRepGProp.hxx"
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

Shape::Shape() : clr_(ColorMap::light_blue), density_(0.) {}

Shape::Shape(const TopoDS_Shape & shape) : clr_(ColorMap::light_blue), density_(0.), shape_(shape)
{
}

std::string
Shape::name() const
{
    return this->name_;
}

void
Shape::set_name(const std::string & name)
{
    this->name_ = name;
}

Color
Shape::color() const
{
    return this->clr_;
}

void
Shape::set_color(const Color & color)
{
    this->clr_ = color;
}

const std::string &
Shape::material() const
{
    return this->material_name_;
}

const std::string &
Shape::material_description() const
{
    return this->material_description_;
}

void
Shape::set_material(const std::string & name, const std::string & description, double density)
{
    this->material_name_ = name;
    this->material_description_ = description;
    this->density_ = density;
}

bool
Shape::has_material() const
{
    return !this->material_name_.empty();
}

void
Shape::set_shape(const TopoDS_Shape & shape)
{
    this->shape_ = shape;
}

void
Shape::assign_color()
{
    this->clr_ = get_next_color();
}

std::vector<Point>
Shape::vertices() const
{
    std::vector<Point> vertices;
    TopExp_Explorer exp0;
    TopTools_DataMapOfShapeInteger id_map;
    for (exp0.Init(this->shape_, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
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
    for (exp0.Init(this->shape_, TopAbs_EDGE); exp0.More(); exp0.Next()) {
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
    for (exp0.Init(this->shape_, TopAbs_FACE); exp0.More(); exp0.Next()) {
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
    for (exp0.Init(this->shape_, TopAbs_SOLID); exp0.More(); exp0.Next()) {
        auto solid = TopoDS::Solid(exp0.Current());
        if (!id_map.IsBound(solid)) {
            auto id = solids.size() + 1;
            id_map.Bind(solid, id);
            solids.emplace_back(Solid(solid));
        }
    }
    return solids;
}

double
Shape::length() const
{
    GProp_GProps props;
    BRepGProp::LinearProperties(this->shape_, props);
    return props.Mass();
}

double
Shape::area() const
{
    GProp_GProps props;
    BRepGProp::SurfaceProperties(this->shape_, props);
    return props.Mass();
}

double
Shape::volume() const
{
    GProp_GProps props;
    BRepGProp::VolumeProperties(this->shape_, props);
    return props.Mass();
}

double
Shape::density() const
{
    return this->density_;
}

Shape::operator TopoDS_Shape() const
{
    return this->shape_;
}

Shell
Shape::make_shell(const Shape & shape)
{
    auto shl = TopoDS::Shell(shape);
    if (shl.IsNull())
        throw Exception("Shape is not a shell");
    return Shell(shl);
}

Solid
Shape::make_solid(const Shape & shape)
{
    auto sld = TopoDS::Solid(shape);
    if (sld.IsNull())
        throw Exception("Shape is not a solid");
    return Solid(sld);
}

} // namespace formo
