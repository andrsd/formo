#include "gmock/gmock.h"
#include "formo/circular_pattern.h"

using namespace formo;

TEST(CircularPatternTest, points)
{
    Point org(1, 0, 0);
    Direction n(0, 0, 1);
    Direction v_x(1, 0, 0);
    Axis2 ax2(org, n, v_x);

    auto radius = 2.;
    CircularPattern cp(ax2, radius, 6);
    auto points = cp.points();
    ASSERT_EQ(points.size(), 6);
    auto h = 0.5 * sqrt(3.) * radius;
    EXPECT_TRUE(points[0].is_equal(Point(3, 0, 0)));
    EXPECT_TRUE(points[1].is_equal(Point(2, h, 0)));
    EXPECT_TRUE(points[2].is_equal(Point(0, h, 0)));
    EXPECT_TRUE(points[3].is_equal(Point(-1, 0, 0)));
    EXPECT_TRUE(points[4].is_equal(Point(0, -h, 0)));
    EXPECT_TRUE(points[5].is_equal(Point(2, -h, 0), 2e-15));
}
