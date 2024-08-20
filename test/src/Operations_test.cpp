#include "gmock/gmock.h"
#include "formo/arc_of_circle.h"
#include "formo/exception.h"
#include "formo/operations.h"
#include "formo/box.h"
#include "formo/circle.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
#include "formo/plane.h"
#include "formo/line.h"
#include "formo/step_file.h"
#include <vector>

using namespace formo;

namespace {

double
radians(double deg)
{
    return deg * M_PI / 180.;
}

} // namespace

TEST(OperationsTest, translate_vec)
{
    Box box(Point(0, 0, 0), Point(1, 2, 3));
    auto res = translate(box, Vector(1, 0, 0));
}

TEST(OperationsTest, translate_pt)
{
    Box box(Point(0, 0, 0), Point(1, 2, 3));
    auto res = translate(box, Point(1, 0, 0), Point(2, 0, 0));
}

TEST(OperationsTest, scale)
{
    Box box(Point(0, 0, 0), Point(1, 2, 3));
    auto res = scale(box, 0.1);
}

TEST(OperationsTest, scale_vec)
{
    Vector a(1, 2, 3);
    auto b = scale(a, 1.1);
    EXPECT_DOUBLE_EQ(b.x(), 1.1);
    EXPECT_DOUBLE_EQ(b.y(), 2.2);
    EXPECT_DOUBLE_EQ(b.z(), 3.3);
}

TEST(OperationsTest, mirror)
{
    Axis1 ax(Point(5, 0, 0), Direction(1, 0, 0));
    Box box(Point(0, 0, 0), Point(1, 2, 3));
    auto res = mirror(box, ax);
}

TEST(OperationsTest, mirror_vec1)
{
    Axis1 ax(Point(0, 0, 0), Direction(0, 1, 0));
    Vector a(1, 2, 0);
    auto b = mirror(a, ax);
    EXPECT_DOUBLE_EQ(b.x(), -1);
    EXPECT_DOUBLE_EQ(b.y(), 2);
    EXPECT_DOUBLE_EQ(b.z(), 0);
}

TEST(OperationsTest, mirror_vec2)
{
    Axis2 ax(Point(0, 0, 0), Direction(0, 1, 0));
    Vector a(1, 2, 0);
    auto b = mirror(a, ax);
    EXPECT_DOUBLE_EQ(b.x(), 1);
    EXPECT_DOUBLE_EQ(b.y(), -2);
    EXPECT_DOUBLE_EQ(b.z(), 0);
}

TEST(OperationsTest, mirror_pnt1)
{
    Axis1 ax(Point(0, 0, 0), Direction(0, 1, 0));
    Point a(1, 2, 0);
    auto b = mirror(a, ax);
    EXPECT_DOUBLE_EQ(b.x(), -1);
    EXPECT_DOUBLE_EQ(b.y(), 2);
    EXPECT_DOUBLE_EQ(b.z(), 0);
}

TEST(OperationsTest, mirror_pnt2)
{
    Axis2 ax(Point(0, 0, 0), Direction(0, 1, 0));
    Point a(1, 2, 0);
    auto b = mirror(a, ax);
    EXPECT_DOUBLE_EQ(b.x(), 1);
    EXPECT_DOUBLE_EQ(b.y(), -2);
    EXPECT_DOUBLE_EQ(b.z(), 0);
}

TEST(OperationsTest, fuse)
{
    Box box1(Point(0, 0, 0), Point(1, 2, 3));
    Box box2(Point(0.5, 0.5, 0.5), Point(2, 3, 4));
    auto res = fuse(box1, box2);
}

TEST(OperationsTest, cut)
{
    Box box1(Point(0, 0, 0), Point(1, 2, 3));
    Box box2(Point(0.5, 0.5, 0.5), Point(2, 3, 4));
    auto res = cut(box1, box2);
}

TEST(OperationsTest, intersect)
{
    Box box1(Point(0, 0, 0), Point(1, 2, 3));
    Box box2(Point(0.5, 0.5, 0.5), Point(2, 3, 4));
    auto res = intersect(box1, box2);
}

TEST(OperationsTest, extrude)
{
    Circle circ(Point(0, 0, 0), 2);
    auto res = extrude(circ, Vector(1, 1, 0));
}

TEST(OperationsTest, revolve)
{
    Circle circ(Point(0, 0, 0), 2);
    Axis1 ax(Point(5, 0, 0), Direction(0, 1, 0));
    auto res = revolve(circ, ax);
}

TEST(OperationsTest, rotate_vec)
{
    Vector a(2, 0, 0);
    auto b = rotate(a, Axis1(Point(0, 0, 0), Direction(0, 0, 1)), radians(45));
    EXPECT_DOUBLE_EQ(b.x(), 2. / std::sqrt(2));
    EXPECT_DOUBLE_EQ(b.y(), 2. / std::sqrt(2));
    EXPECT_DOUBLE_EQ(b.z(), 0.);
}

TEST(OperationsTest, rotate_pnt)
{
    Point a(2, 0, 0);
    auto b = rotate(a, Axis1(Point(0, 0, 0), Direction(0, 0, 1)), radians(45));
    EXPECT_DOUBLE_EQ(b.x(), 2. / std::sqrt(2));
    EXPECT_DOUBLE_EQ(b.y(), 2. / std::sqrt(2));
    EXPECT_DOUBLE_EQ(b.z(), 0.);
}

TEST(OperationsTest, rotate_shape)
{
    Box a(Point(2, 0, 0), Point(3, 2, 3));
    auto b = rotate(a, Axis1(Point(0, 0, 0), Direction(0, 0, 1)), radians(45));
}

TEST(OperationsTest, section)
{
    Box box1(Point(0, 0, 0), Point(1, 2, 3));
    Plane pln(Point(0.5, 0, 0), Direction(1, 0, 0));
    auto res = section(box1, pln);
}

TEST(OperationsTest, draft)
{
    Box box(Point(0, 0, 0), Point(1, 2, 3));
    std::vector<Face> faces;
    for (auto & f : box.faces()) {
        auto pln = f.plane();
        auto n = pln.axis().direction();
        if (std::abs(n.z()) < 1e-14)
            faces.emplace_back(f);
    }

    Plane neutral_plane(Point(0, 0, 0), Direction(0, 0, 1));
    auto shape = draft(box, neutral_plane, faces, radians(3));
}

TEST(OperationsTest, hole)
{
    Box box(Point(0, 0, 0), Point(1, 1, 1));
    Axis1 ax1(Point(1.5, 0.5, 0.25), Direction(-1, 0, 0));
    auto shape = hole(box, ax1, 0.1);
}

TEST(OperationsTest, hole_blind)
{
    Box box(Point(0, 0, 0), Point(1, 1, 1));
    Axis1 ax1(Point(0, 0.5, 0.25), Direction(1, 0, 0));
    auto shape = hole(box, ax1, 0.1, 0.5);
}

TEST(OperationsTest, sweep)
{
    Line l1(Point(0, 0, 0), Point(0, 1, 0));
    ArcOfCircle arc(Point(0, 1, 0), Vector(0, 1, 0), Point(1, 2, 0));
    Line l2(Point(1, 2, 0), Point(2, 2, 0));
    Wire path({ l1, arc, l2 });

    Circle circ(Axis2(Point(0, 0, 0), Direction(0, 1, 0)), 0.1);
    Face profile(Wire({ circ }));

    auto shape = sweep(profile, path);
}
