// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/color.h"
#include "TopoDS_Shape.hxx"
#include <string>
#include <vector>

namespace formo {

class Point;
class Edge;
class Face;

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
    void set_name(const std::string & name);

    /// Get color
    Color color() const;

    /// Set color
    void set_color(const Color & color);

    /// Get all vertices of this shape
    ///
    /// @return All vertices of this shape
    std::vector<Point> vertices() const;

    /// Get all edges of this shape
    ///
    /// @return All edges of this shape
    std::vector<Edge> edges() const;

    /// Get all faces of this shape
    ///
    /// @return All faces of this shape
    std::vector<Face> faces() const;

    ///
    operator TopoDS_Shape() const;

protected:
    void set_shape(const TopoDS_Shape & shape);

    void assign_color();

private:
    /// Shape name
    std::string nm;
    /// Color of this shape
    Color clr;
    /// Open CASCADE shape
    TopoDS_Shape shp;
};

} // namespace formo
