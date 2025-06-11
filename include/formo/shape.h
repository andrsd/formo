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
class Solid;
class Shell;

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

    /// Get material
    ///
    /// @return Material name
    const std::string & material() const;

    /// Get material description
    ///
    /// @return Material description
    const std::string & material_description() const;

    /// Set material
    ///
    /// @param name Material name
    /// @param description Material description
    /// @param density Density [g/cm^3]
    void set_material(const std::string & name,
                      const std::string & description = "",
                      double density = 0.);

    /// Query if this shape has material assigned to it
    ///
    /// @return `true` if material is assigned, `false` otherwise
    bool has_material() const;

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

    /// Get all solids of this shape
    ///
    /// @return All solid of this shape
    std::vector<Solid> solids() const;

    /// Compute the length of the edge
    ///
    /// @return Length of the edge
    double length() const;

    /// Compute the area of the face
    ///
    /// @return Area of the face
    double area() const;

    /// Compute the volume of the shape
    ///
    /// @return Volume of the shape
    double volume() const;

    /// Return density
    ///
    /// @return Density [kg/m^3]
    double density() const;

    ///
    operator TopoDS_Shape() const;

protected:
    void set_shape(const TopoDS_Shape & shape);

    void assign_color();

private:
    /// Shape name
    std::string name_;
    /// Color of this shape
    Color clr_;
    /// Material name
    std::string material_name_;
    /// Material description
    std::string material_description_;
    /// Density
    double density_;
    /// Open CASCADE shape
    TopoDS_Shape shape_;

public:
    static Shell make_shell(const Shape & shape);
    static Solid make_solid(const Shape & shape);
};

} // namespace formo
