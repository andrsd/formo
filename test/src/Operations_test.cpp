#include "gmock/gmock.h"
#include "formo/operations.h"
#include "formo/box.h"
#include "formo/circle.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
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

TEST(OperationsTest, section)
{
    Box box1(Point(0, 0, 0), Point(1, 2, 3));
    Plane pln(Point(0.5, 0, 0), Direction(1, 0, 0));
    auto res = section(box1, pln);
}
