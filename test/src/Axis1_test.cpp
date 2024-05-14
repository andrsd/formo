#include "gmock/gmock.h"
#include "formo/axis1.h"

using namespace formo;

TEST(Axis1Test, test)
{
    Axis1 ax1(Point(1, 2, 3), Direction(1, 0, 0));
    EXPECT_DOUBLE_EQ(ax1.location().x(), 1);
    EXPECT_DOUBLE_EQ(ax1.location().y(), 2);
    EXPECT_DOUBLE_EQ(ax1.location().z(), 3);

    EXPECT_DOUBLE_EQ(ax1.direction().x(), 1);
    EXPECT_DOUBLE_EQ(ax1.direction().y(), 0);
    EXPECT_DOUBLE_EQ(ax1.direction().z(), 0);
}
