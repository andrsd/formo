#include "gmock/gmock.h"
#include "formo/point.h"

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
