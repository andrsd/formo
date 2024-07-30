#include "gmock/gmock.h"
#include "formo/point.h"
#include "formo/vector.h"
#include "formo/axis1.h"
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
