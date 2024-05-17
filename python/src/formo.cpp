// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "formo/config.h"
#include "formo/arc_of_circle.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
#include "formo/box.h"
#include "formo/circle.h"
#include "formo/color.h"
#include "formo/color_map.h"
#include "formo/cone.h"
#include "formo/cylinder.h"
#include "formo/direction.h"
#include "formo/edge.h"
#include "formo/exception.h"
#include "formo/face.h"
#include "formo/geometry.h"
#include "formo/iges_file.h"
#include "formo/io.h"
#include "formo/line.h"
#include "formo/operations.h"
#include "formo/plane.h"
#include "formo/point.h"
#include "formo/polygon.h"
#include "formo/prism.h"
#include "formo/shape.h"
#include "formo/shape.h"
#include "formo/shell.h"
#include "formo/solid.h"
#include "formo/sphere.h"
#include "formo/spline.h"
#include "formo/step_file.h"
#include "formo/utils.h"
#include "formo/vector.h"
#include "formo/wire.h"

namespace py = pybind11;
using namespace formo;

PYBIND11_MODULE(formo, m)
{
    m.doc() = "pybind11 plugin for formo";
    py::setattr(m, "version", py::str(FORMO_VERSION));

    // clang-format off
    py::class_<Color>(m, "Color")
        .def(py::init<>())
        .def(py::init<int, int, int>(),
            py::arg("red"), py::arg("green"), py::arg("blue"))
        .def("red", &Color::red)
        .def("redF", &Color::redF)
        .def("green", &Color::green)
        .def("greenF", &Color::greenF)
        .def("blue", &Color::blue)
        .def("blueF", &Color::blueF)
    ;

    py::class_<ColorMap>(m, "ColorMap")
        .def_readonly_static("black", &ColorMap::black)
        .def_readonly_static("blue", &ColorMap::blue)
        .def_readonly_static("red", &ColorMap::red)

        .def_readonly_static("medium_blue", &ColorMap::medium_blue)
        .def_readonly_static("medium_grey", &ColorMap::medium_grey)
        .def_readonly_static("dark_blue", &ColorMap::dark_blue)
        .def_readonly_static("light_grey", &ColorMap::light_grey)
        .def_readonly_static("light_blue", &ColorMap::light_blue)
        .def_readonly_static("orange", &ColorMap::orange)
        .def_readonly_static("dark_grey", &ColorMap::dark_grey)
        .def_readonly_static("yellow", &ColorMap::yellow)

        .def_readonly_static("grey1", &ColorMap::grey1)
        .def_readonly_static("grey2", &ColorMap::grey2)
        .def_readonly_static("grey3", &ColorMap::grey3)
        .def_readonly_static("grey4", &ColorMap::grey4)
        .def_readonly_static("grey5", &ColorMap::grey5)
        .def_readonly_static("grey6", &ColorMap::grey6)
        .def_readonly_static("grey7", &ColorMap::grey7)

        .def_readonly_static("gold1", &ColorMap::gold1)
        .def_readonly_static("gold2", &ColorMap::gold2)
        .def_readonly_static("gold3", &ColorMap::gold3)
        .def_readonly_static("gold4", &ColorMap::gold4)
        .def_readonly_static("gold5", &ColorMap::gold5)
        .def_readonly_static("gold6", &ColorMap::gold6)
        .def_readonly_static("gold7", &ColorMap::gold7)

        .def_readonly_static("silver1", &ColorMap::silver1)
        .def_readonly_static("silver2", &ColorMap::silver2)
        .def_readonly_static("silver3", &ColorMap::silver3)
        .def_readonly_static("silver4", &ColorMap::silver4)
        .def_readonly_static("silver5", &ColorMap::silver5)
        .def_readonly_static("silver6", &ColorMap::silver6)
        .def_readonly_static("silver7", &ColorMap::silver7)

        .def_readonly_static("red1", &ColorMap::red1)
        .def_readonly_static("red2", &ColorMap::red2)
        .def_readonly_static("red3", &ColorMap::red3)
        .def_readonly_static("red4", &ColorMap::red4)
        .def_readonly_static("red5", &ColorMap::red5)
        .def_readonly_static("red6", &ColorMap::red6)
        .def_readonly_static("red7", &ColorMap::red7)

        .def_readonly_static("orange1", &ColorMap::orange1)
        .def_readonly_static("orange2", &ColorMap::orange2)
        .def_readonly_static("orange3", &ColorMap::orange3)
        .def_readonly_static("orange4", &ColorMap::orange4)
        .def_readonly_static("orange5", &ColorMap::orange5)
        .def_readonly_static("orange6", &ColorMap::orange6)
        .def_readonly_static("orange7", &ColorMap::orange7)

        .def_readonly_static("yellow1", &ColorMap::yellow1)
        .def_readonly_static("yellow2", &ColorMap::yellow2)
        .def_readonly_static("yellow3", &ColorMap::yellow3)
        .def_readonly_static("yellow4", &ColorMap::yellow4)
        .def_readonly_static("yellow5", &ColorMap::yellow5)
        .def_readonly_static("yellow6", &ColorMap::yellow6)
        .def_readonly_static("yellow7", &ColorMap::yellow7)

        .def_readonly_static("green1", &ColorMap::green1)
        .def_readonly_static("green2", &ColorMap::green2)
        .def_readonly_static("green3", &ColorMap::green3)
        .def_readonly_static("green4", &ColorMap::green4)
        .def_readonly_static("green5", &ColorMap::green5)
        .def_readonly_static("green6", &ColorMap::green6)
        .def_readonly_static("green7", &ColorMap::green7)

        .def_readonly_static("teal1", &ColorMap::teal1)
        .def_readonly_static("teal2", &ColorMap::teal2)
        .def_readonly_static("teal3", &ColorMap::teal3)
        .def_readonly_static("teal4", &ColorMap::teal4)
        .def_readonly_static("teal5", &ColorMap::teal5)
        .def_readonly_static("teal6", &ColorMap::teal6)
        .def_readonly_static("teal7", &ColorMap::teal7)

        .def_readonly_static("blue1", &ColorMap::blue1)
        .def_readonly_static("blue2", &ColorMap::blue2)
        .def_readonly_static("blue3", &ColorMap::blue3)
        .def_readonly_static("blue4", &ColorMap::blue4)
        .def_readonly_static("blue5", &ColorMap::blue5)
        .def_readonly_static("blue6", &ColorMap::blue6)
        .def_readonly_static("blue7", &ColorMap::blue7)
    ;

    //

    py::class_<Point>(m, "Point")
        .def(py::init<double, double, double>(),
            py::arg("x"), py::arg("y"), py::arg("z"))
        .def("x", &Point::x)
        .def("y", &Point::y)
        .def("z", &Point::z)
        .def("is_equal", &Point::is_equal,
            py::arg("other"), py::arg("tol"))
        .def("distance", &Point::distance,
            py::arg("pt"))
    ;

    py::class_<Direction>(m, "Direction")
        .def(py::init<double, double, double>(),
            py::arg("x"), py::arg("y"), py::arg("z"))
        .def(py::init<const Vector &>())
        .def("x", &Direction::x)
        .def("y", &Direction::y)
        .def("z", &Direction::z)
    ;

    py::class_<Vector>(m, "Vector")
        .def(py::init<double, double, double>(),
            py::arg("x"), py::arg("y"), py::arg("z"))
        .def(py::init<const Direction &>(),
            py::arg("direction"))
        .def(py::init<const Point &, const Point &>(),
            py::arg("pt1"), py::arg("pt2"))
        .def("x", &Vector::x)
        .def("y", &Vector::y)
        .def("z", &Vector::z)
    ;

    py::class_<Geometry>(m, "Geometry")
        .def_readonly_static("OX", &Geometry::OX)
        .def_readonly_static("OY", &Geometry::OY)
        .def_readonly_static("OZ", &Geometry::OZ)

        .def_readonly_static("DX", &Geometry::DX)
        .def_readonly_static("DY", &Geometry::DY)
        .def_readonly_static("DZ", &Geometry::DZ)
    ;

    py::class_<Plane>(m, "Plane")
        .def(py::init<const Point &, const Direction &>(),
            py::arg("point"), py::arg("normal"))
        .def("location", &Plane::location)
    ;

    py::class_<Axis1>(m, "Axis1")
        .def(py::init<const Point &, const Direction &>(),
            py::arg("point"), py::arg("direction"))
        .def("location", &Axis1::location)
        .def("direction", &Axis1::direction)
    ;

    py::class_<Axis2>(m, "Axis2")
        .def(py::init<const Point &, const Direction &>(),
            py::arg("point"), py::arg("direction"))
        .def("location", &Axis2::location)
        .def("direction", &Axis2::direction)
    ;

    //

    py::class_<Shape>(m, "Shape")
        .def(py::init<>())
        .def(py::init<const TopoDS_Shape &>(),
            py::arg("shape"))
        .def("name", &Shape::name)
        .def("set_name", &Shape::set_name,
            py::arg("name"))
        .def("color", &Shape::color)
        .def("set_color", &Shape::set_color,
            py::arg("color"))
    ;

    py::class_<Edge, Shape>(m, "Edge")
        .def(py::init<>())
        .def(py::init<const TopoDS_Edge &>(),
            py::arg("edge"))
        .def("length", &Edge::length)
    ;

    py::class_<Face, Shape>(m, "Face")
        .def(py::init<const Wire &>(),
            py::arg("wire"))
        .def("is_plane", &Face::is_plane)
        .def("plane", &Face::plane)
    ;

    py::class_<Wire, Shape>(m, "Wire")
        .def(py::init<const TopoDS_Wire &>(),
            py::arg("wire"))
        .def(py::init<const std::vector<Edge> &>(),
            py::arg("edges"))
    ;

    py::class_<Shell, Shape>(m, "Shell")
        .def(py::init<const TopoDS_Shell &>(),
            py::arg("shell"))
    ;

    py::class_<Solid, Shape>(m, "Solid")
        .def(py::init<>())
        .def(py::init<const TopoDS_Solid &>(),
            py::arg("solid"))
        .def("volume", &Solid::volume)
    ;

    //

    py::class_<ArcOfCircle, Edge>(m, "ArcOfCircle")
        .def(py::init<const Point &, const Point &, const Point &>(),
            py::arg("pt1"), py::arg("pt2"), py::arg("pt3"))
        .def(py::init<const Circle &, const Point &, const Point &, bool>(),
            py::arg("circ"), py::arg("pt1"), py::arg("pt2"), py::arg("sense") = true)
        .def(py::init<const Point &, const Vector &, const Point &>(),
            py::arg("pt1"), py::arg("tangent"), py::arg("pt2"))
        .def("start_point", &ArcOfCircle::start_point)
        .def("end_point", &ArcOfCircle::end_point)
    ;

    py::class_<Line, Edge>(m, "Line")
        .def(py::init<const Point &, const Point &>(),
            py::arg("pt1"), py::arg("pt2"))
    ;

    py::class_<Circle, Edge>(m, "Circle")
        .def(py::init<const Point &, double, const Direction &>(),
            py::arg("center"), py::arg("radius"), py::arg("normal") = Direction(0., 0., 1.))
        .def(py::init<const Point &, const Point &, const Direction &>(),
            py::arg("center"), py::arg("point"), py::arg("normal") = Direction(0., 0., 1.))
        .def(py::init<const Point &, const Point &, const Point &>(),
            py::arg("pt1"), py::arg("pt2"), py::arg("pt3"))
        .def("area", &Circle::area)
        .def("radius", &Circle::radius)
        .def("location", &Circle::location)
    ;

    py::class_<Spline, Edge>(m, "Spline")
        .def(py::init<const std::vector<Point> &>(),
            py::arg("points"))
        .def(py::init<const std::vector<Point> &, const Vector &, const Vector &>(),
            py::arg("points"), py::arg("initial_tangent"), py::arg("final_tangent"))
    ;

    py::class_<Polygon, Shape>(m, "Polygon")
        .def(py::init<const std::vector<Point> &, bool>(),
            py::arg("points"), py::arg("closed") = true)
        .def("as_edge", &Polygon::as_edge)
        .def("as_wire", &Polygon::as_wire)
    ;

    //

    py::class_<Box, Solid>(m, "Box")
        .def(py::init<const Point &, const Point &>(),
            py::arg("pt1"), py::arg("pt2"))
    ;

    py::class_<Sphere, Solid>(m, "Sphere")
        .def(py::init<const Point &, double>(),
            py::arg("center"), py::arg("radius"))
    ;

    py::class_<Cone, Solid>(m, "Cone")
        .def(py::init<const Axis2 &, double, double, double>(),
            py::arg("axis"), py::arg("radius1"), py::arg("radius2"), py::arg("height"))
    ;

    py::class_<Cylinder, Solid>(m, "Cylinder")
        .def(py::init<const Axis2 &, double, double>(),
            py::arg("axis"), py::arg("radius"), py::arg("height"))
    ;

    py::class_<Prism, Shape>(m, "Prism")
        .def(py::init<const Shape &, const Vector &>(),
            py::arg("shape"), py::arg("vector"))
    ;

    //

    py::class_<IO>(m, "IO")
        .def_static("write", &IO::write,
            py::arg("file_name"), py::arg("shapes"), py::arg("file_format") = "step")
        .def_static("read", &IO::read,
            py::arg("file_name"))
    ;

    py::class_<IGESFile>(m, "IGESFile")
        .def(py::init<const std::string &>(),
            py::arg("file_name"))
        .def("read", &IGESFile::read)
        .def("write", &IGESFile::write,
            py::arg("shapes"))
    ;

    py::class_<STEPFile>(m, "STEPFile")
        .def(py::init<const std::string &>(),
            py::arg("file_name"))
        .def("read", &STEPFile::read)
        .def("write", &STEPFile::write,
            py::arg("shapes"))
    ;

    m.def("translate", py::overload_cast<const Shape &, const Vector &>(&translate),
        py::arg("shape"), py::arg("vector"));
    m.def("translate", py::overload_cast<const Shape &, const Point &, const Point &>(&translate),
        py::arg("shape"), py::arg("pt1"), py::arg("pt2"));

    m.def("scale", py::overload_cast<const Shape &, double>(&scale),
        py::arg("shape"), py::arg("scale_factor"));
    m.def("scale", py::overload_cast<const Vector &, double>(&scale),
        py::arg("vector"), py::arg("scale_factor"));

    m.def("mirror", py::overload_cast<const Shape &, const Axis1 &>(&mirror),
        py::arg("shape"), py::arg("axis1"));
    m.def("mirror", py::overload_cast<const Vector &, const Axis1 &>(&mirror),
        py::arg("vector"), py::arg("axis1"));
    m.def("mirror", py::overload_cast<const Vector &, const Axis2 &>(&mirror),
        py::arg("vector"), py::arg("axis2"));
    m.def("mirror", py::overload_cast<const Point &, const Axis1 &>(&mirror),
        py::arg("point"), py::arg("axis1"));
    m.def("mirror", py::overload_cast<const Point &, const Axis2 &>(&mirror),
        py::arg("point"), py::arg("axis2"));

    m.def("fuse", py::overload_cast<const Shape &, const Shape &>(&fuse),
        py::arg("shape"), py::arg("tool"));

    m.def("cut", py::overload_cast<const Shape &, const Shape &>(&cut),
        py::arg("shape"), py::arg("tool"));

    m.def("intersect", py::overload_cast<const Shape &, const Shape &>(&intersect),
        py::arg("shape"), py::arg("tool"));

    m.def("fillet", py::overload_cast<const Shape &, const std::vector<Edge> &, double>(&fillet),
        py::arg("shape"), py::arg("edges"), py::arg("radius"));

    m.def("hollow", py::overload_cast<const Shape &, const std::vector<Face> &, double, double>(&hollow),
        py::arg("shape"), py::arg("faces_to_remove"), py::arg("thickness"), py::arg("tolerance"));

    m.def("extrude", py::overload_cast<const Shape &, const Vector &>(&extrude),
        py::arg("shape"), py::arg("vector"));

    m.def("revolve", py::overload_cast<const Shape &, const Axis1 &, double>(&revolve),
        py::arg("shape"), py::arg("axis1"), py::arg("angle") = 2. * M_PI);

    m.def("rotate", py::overload_cast<const Point &, const Axis1 &, double>(&rotate),
        py::arg("point"), py::arg("axis"), py::arg("angle"));
    m.def("rotate", py::overload_cast<const Vector &, const Axis1 &, double>(&rotate),
        py::arg("point"), py::arg("axis1"), py::arg("angle"));

    m.def("section", py::overload_cast<const Shape &, const Plane &>(&section),
        py::arg("shape"), py::arg("plane"));

    m.def("write", &IO::write,
        py::arg("file_name"), py::arg("shapes"), py::arg("file_format") = "step");
    m.def("read", &IO::read,
        py::arg("file_name"));
    // clang-format on
}
