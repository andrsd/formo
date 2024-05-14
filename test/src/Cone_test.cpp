#include "gmock/gmock.h"
#include "formo/cone.h"

using namespace formo;

TEST(ConeTest, test)
{
    Axis2 ax2(Point(0, 0, 0), Direction(1, 0, 0));
    Cone cone(ax2, 1, 2, 3);
    EXPECT_DOUBLE_EQ(cone.volume(), 21.991148575128555);
}
