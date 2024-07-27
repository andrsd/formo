#include "gmock/gmock.h"
#include "formo/axis2.h"

using namespace formo;

TEST(Axis2Test, test)
{
    Axis2 ax2(Point(1, 2, 3), Direction(1, 0, 0));
    EXPECT_DOUBLE_EQ(ax2.location().x(), 1);
    EXPECT_DOUBLE_EQ(ax2.location().y(), 2);
    EXPECT_DOUBLE_EQ(ax2.location().z(), 3);

    EXPECT_DOUBLE_EQ(ax2.direction().x(), 1);
    EXPECT_DOUBLE_EQ(ax2.direction().y(), 0);
    EXPECT_DOUBLE_EQ(ax2.direction().z(), 0);
}

TEST(Axis2Test, ctor_n_dir)
{
    Axis2 ax2(Point(0, 0, 0), Direction(0, 0, 1), Direction(0, 1, 0));
    EXPECT_DOUBLE_EQ(ax2.direction().x(), 0);
    EXPECT_DOUBLE_EQ(ax2.direction().y(), 0);
    EXPECT_DOUBLE_EQ(ax2.direction().z(), 1);

    EXPECT_DOUBLE_EQ(ax2.x_direction().x(), 0);
    EXPECT_DOUBLE_EQ(ax2.x_direction().y(), 1);
    EXPECT_DOUBLE_EQ(ax2.x_direction().z(), 0);

    EXPECT_DOUBLE_EQ(ax2.y_direction().x(), -1);
    EXPECT_DOUBLE_EQ(ax2.y_direction().y(), 0);
    EXPECT_DOUBLE_EQ(ax2.y_direction().z(), 0);
}
