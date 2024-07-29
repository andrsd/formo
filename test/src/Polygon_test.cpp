#include "gmock/gmock.h"
#include "formo/polygon.h"
#include "formo/exception.h"

using namespace formo;

TEST(PolygonTest, ctor1)
{
    std::vector<Point> pts = { Point(0, 0, 0), Point(1, 0, 0), Point(1, 1, 0) };
    Polygon plgn(pts);
}

TEST(PolygonTest, ctor_not_enough_points)
{
    std::vector<Point> pts = { Point(0, 0, 0), Point(1, 0, 0) };
    EXPECT_THROW({ Polygon plgn(pts); }, Exception);
}
