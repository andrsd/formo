#include "gmock/gmock.h"
#include "formo/direction.h"
#include "formo/linear_pattern.h"
#include "formo/point.h"
#include "formo/direction.h"
#include "formo/axis2.h"

using namespace formo;

const double sqrt2 = std::sqrt(2.);

TEST(LinearPatternTest, points_1d)
{
    Point org(1, 0, 0);
    Direction n(0, 0, 1);
    Direction v_x(1, 1, 0);
    Axis2 ax2(org, n, v_x);

    LinearPattern lp(ax2, 3, 1);
    auto points = lp.points();
    EXPECT_TRUE(points[0].is_equal(Point(1, 0, 0)));
    EXPECT_TRUE(points[1].is_equal(Point(1 + sqrt2 / 2., sqrt2 / 2., 0)));
    EXPECT_TRUE(points[2].is_equal(Point(1 + sqrt2, sqrt2, 0)));
}

TEST(LinearPatternTest, points_2d)
{
    Point org(1, 0, 0);
    Direction n(0, 0, 1);
    Direction v_x(1, 1, 0);
    Axis2 ax2(org, n, v_x);

    LinearPattern lp(ax2, 3, 2, 1, 1);
    auto points = lp.points();
    EXPECT_TRUE(points[0].is_equal(Point(1, 0, 0)));
    EXPECT_TRUE(points[1].is_equal(Point(1 + sqrt2 / 2., sqrt2 / 2., 0)));
    EXPECT_TRUE(points[2].is_equal(Point(1 + sqrt2, sqrt2, 0)));
    EXPECT_TRUE(points[3].is_equal(Point(1 - sqrt2 / 2., sqrt2 / 2., 0)));
    EXPECT_TRUE(points[4].is_equal(Point(1, sqrt2, 0)));
    EXPECT_TRUE(points[5].is_equal(Point(1 + sqrt2 / 2., 1.5 * sqrt2, 0)));
}
