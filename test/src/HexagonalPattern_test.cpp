#include "gmock/gmock.h"
#include <system_error>
#include "formo/hexagonal_pattern.h"

using namespace formo;

TEST(HexagonalPatternTest, test)
{
    Point ctr(0, 0, 0);
    Direction n(0, 0, 1);
    Direction v_x(1, 0, 0);
    Axis2 ax2(ctr, n, v_x);

    double flat2flat = 4.;
    HexagonalPattern hp(ax2, flat2flat, 2);
    auto points = hp.points();
    ASSERT_EQ(points.size(), 12);

    auto h = flat2flat / 2.;
    auto r = flat2flat / std::sqrt(3.);
    EXPECT_TRUE(points[0].is_equal(Point(r, 0., 0.), 1e-14));
    EXPECT_TRUE(points[1].is_equal(Point(0.75 * r, h / 2., 0.)));
    EXPECT_TRUE(points[2].is_equal(Point(r / 2., h, 0.), 1e-14));
    EXPECT_TRUE(points[3].is_equal(Point(0., h, 0.), 1e-14));
    EXPECT_TRUE(points[4].is_equal(Point(-r / 2., h, 0.), 1e-14));
    EXPECT_TRUE(points[5].is_equal(Point(-0.75 * r, h / 2., 0.), 1e-14));
    EXPECT_TRUE(points[6].is_equal(Point(-r, 0., 0.), 1e-14));
    EXPECT_TRUE(points[7].is_equal(Point(-0.75 * r, -h / 2., 0.), 1e-14));
    EXPECT_TRUE(points[8].is_equal(Point(-r / 2., -h, 0.), 1e-14));
    EXPECT_TRUE(points[9].is_equal(Point(0, -h, 0.), 1e-14));
    EXPECT_TRUE(points[10].is_equal(Point(r / 2., -h, 0.), 1e-14));
    EXPECT_TRUE(points[11].is_equal(Point(0.75 * r, -h / 2., 0.), 1e-14));

    EXPECT_EQ(hp.flat_to_flat(), flat2flat);
}
