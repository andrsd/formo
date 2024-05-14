#include "gmock/gmock.h"
#include "formo/spline.h"

using namespace formo;

TEST(SplineTest, ctor1)
{
    std::vector<Point> pts = { Point(0, 0, 0), Point(1, 0, 0), Point(1, 1, 0) };
    Spline spline(pts);
}

TEST(SplineTest, ctor2)
{
    std::vector<Point> pts = { Point(0, 0, 0), Point(1, 0, 0), Point(1, 1, 0) };
    Vector tg1(1, 0, 0);
    Vector tg2(0, 1, 0);
    Spline spline(pts, tg1, tg2);
}
