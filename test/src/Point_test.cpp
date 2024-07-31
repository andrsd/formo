#include "gmock/gmock.h"
#include "formo/point.h"
#include "formo/vector.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
#include "formo/direction.h"

using namespace formo;

TEST(PointTest, ctor1)
{
    Point pt(1, 2, 3);
    EXPECT_DOUBLE_EQ(pt.x(), 1);
    EXPECT_DOUBLE_EQ(pt.y(), 2);
    EXPECT_DOUBLE_EQ(pt.z(), 3);
}

TEST(PointTest, ctor2)
{
    gp_Pnt gpnt(1, 2, 3);
    Point pt(gpnt);
    EXPECT_DOUBLE_EQ(pt.x(), 1);
    EXPECT_DOUBLE_EQ(pt.y(), 2);
    EXPECT_DOUBLE_EQ(pt.z(), 3);
}

TEST(PointTest, is_equal)
{
    Point pt(1, 2, 3);
    EXPECT_TRUE(pt.is_equal(Point(1, 2, 3)));
}

TEST(PointTest, distance)
{
    Point pt(0, 0, 0);
    EXPECT_DOUBLE_EQ(pt.distance(Point(2, 0, 0)), 2.);
}

TEST(PointTest, op_plus_pt_vec)
{
    Point pt(1, 1, 0);
    Vector vec(1, 2, 4);
    auto b = pt + vec;
    EXPECT_NEAR(b.distance(Point(2, 3, 4)), 0., 1e-15);
}

TEST(PointTest, rotate)
{
    Point pt(1, 0, 2);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 0, 1));
    pt.rotate(ax1, M_PI / 2.);
    EXPECT_NEAR(pt.x(), 0, 1e-15);
    EXPECT_NEAR(pt.y(), 1, 1e-15);
    EXPECT_NEAR(pt.z(), 2, 1e-15);
}

TEST(PointTest, rotated)
{
    Point pt(1, 0, 2);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 0, 1));
    auto npt = pt.rotated(ax1, M_PI / 2.);
    EXPECT_NEAR(npt.x(), 0, 1e-15);
    EXPECT_NEAR(npt.y(), 1, 1e-15);
    EXPECT_NEAR(npt.z(), 2, 1e-15);
}

TEST(PointTest, scale)
{
    Point pt(1, 0, 2);
    pt.scale(Point(0, 0, 0), 2);
    EXPECT_NEAR(pt.x(), 2, 1e-15);
    EXPECT_NEAR(pt.y(), 0, 1e-15);
    EXPECT_NEAR(pt.z(), 4, 1e-15);
}

TEST(PointTest, scaled)
{
    Point pt(1, 0, 2);
    auto npt = pt.scaled(Point(0, 0, 0), 2);
    EXPECT_NEAR(npt.x(), 2, 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), 4, 1e-15);
}

TEST(PointTest, translate)
{
    Point pt(1, 0, 2);
    pt.translate(Vector(1, -1, 2));
    EXPECT_NEAR(pt.x(), 2, 1e-15);
    EXPECT_NEAR(pt.y(), -1, 1e-15);
    EXPECT_NEAR(pt.z(), 4, 1e-15);
}

TEST(PointTest, translate_2pts)
{
    Point pt(1, 0, 2);
    pt.translate(Point(0, 0, 0), Point(1, -1, 2));
    EXPECT_NEAR(pt.x(), 2, 1e-15);
    EXPECT_NEAR(pt.y(), -1, 1e-15);
    EXPECT_NEAR(pt.z(), 4, 1e-15);
}

TEST(PointTest, translated)
{
    Point pt(1, 0, 2);
    auto npt = pt.translated(Vector(1, -1, 2));
    EXPECT_NEAR(npt.x(), 2, 1e-15);
    EXPECT_NEAR(npt.y(), -1, 1e-15);
    EXPECT_NEAR(npt.z(), 4, 1e-15);
}

TEST(PointTest, translated_2pts)
{
    Point pt(1, 0, 2);
    auto npt = pt.translated(Point(0, 0, 0), Point(1, -1, 2));
    EXPECT_NEAR(npt.x(), 2, 1e-15);
    EXPECT_NEAR(npt.y(), -1, 1e-15);
    EXPECT_NEAR(npt.z(), 4, 1e-15);
}

TEST(PointTest, mirror_pt)
{
    Point pt(1, 0, -2);
    Point symm(0, 0, 0);
    pt.mirror(symm);
    EXPECT_NEAR(pt.x(), -1, 1e-15);
    EXPECT_NEAR(pt.y(), 0, 1e-15);
    EXPECT_NEAR(pt.z(), 2, 1e-15);
}

TEST(PointTest, mirror_ax1)
{
    Point pt(1, 0, -2);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 1, 0));
    pt.mirror(ax1);
    EXPECT_NEAR(pt.x(), -1, 1e-15);
    EXPECT_NEAR(pt.y(), 0, 1e-15);
    EXPECT_NEAR(pt.z(), 2, 1e-15);
}

TEST(PointTest, mirror_ax2)
{
    Point pt(1, 0, -2);
    Axis2 ax2(Point(0, 0, 0), Direction(1, 0, 0));
    pt.mirror(ax2);
    EXPECT_NEAR(pt.x(), -1, 1e-15);
    EXPECT_NEAR(pt.y(), 0, 1e-15);
    EXPECT_NEAR(pt.z(), -2, 1e-15);
}

TEST(PointTest, mirrored_pt)
{
    Point pt(1, 0, -2);
    Point symm(0, 0, 0);
    auto npt = pt.mirrored(symm);
    EXPECT_NEAR(npt.x(), -1, 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), 2, 1e-15);
}

TEST(PointTest, mirrored_ax1)
{
    Point pt(1, 0, -2);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 1, 0));
    auto npt = pt.mirrored(ax1);
    EXPECT_NEAR(npt.x(), -1, 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), 2, 1e-15);
}

TEST(PointTest, mirrored_ax2)
{
    Point pt(1, 0, -2);
    Axis2 ax2(Point(0, 0, 0), Direction(1, 0, 0));
    auto npt = pt.mirrored(ax2);
    EXPECT_NEAR(npt.x(), -1, 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), -2, 1e-15);
}
