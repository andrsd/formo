#include "gmock/gmock.h"
#include "formo/circle.h"

using namespace formo;

TEST(CircleTest, ctor1)
{
    Circle circ(Point(1, 2, 3), 2);
    EXPECT_DOUBLE_EQ(circ.location().x(), 1);
    EXPECT_DOUBLE_EQ(circ.location().y(), 2);
    EXPECT_DOUBLE_EQ(circ.location().z(), 3);
    EXPECT_DOUBLE_EQ(circ.radius(), 2.);
    EXPECT_DOUBLE_EQ(circ.area(), M_PI * 4.);
}

TEST(CircleTest, ctor2)
{
    Circle circ(Point(1, 2, 3), Point(1, 0, 3));
    EXPECT_DOUBLE_EQ(circ.location().x(), 1);
    EXPECT_DOUBLE_EQ(circ.location().y(), 2);
    EXPECT_DOUBLE_EQ(circ.location().z(), 3);
    EXPECT_DOUBLE_EQ(circ.radius(), 2.);
    EXPECT_DOUBLE_EQ(circ.area(), M_PI * 4.);
}

TEST(CircleTest, ctor3)
{
    Circle circ(Point(3, 2, 3), Point(1, 0, 3), Point(-1, 2, 3));
    EXPECT_DOUBLE_EQ(circ.location().x(), 1);
    EXPECT_DOUBLE_EQ(circ.location().y(), 2);
    EXPECT_DOUBLE_EQ(circ.location().z(), 3);
    EXPECT_DOUBLE_EQ(circ.radius(), 2.);
    EXPECT_DOUBLE_EQ(circ.area(), M_PI * 4.);
}
