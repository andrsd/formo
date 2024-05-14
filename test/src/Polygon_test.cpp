#include "gmock/gmock.h"
#include "formo/polygon.h"

using namespace formo;

TEST(PolygonTest, ctor1)
{
    std::vector<Point> pts = { Point(0, 0, 0), Point(1, 0, 0), Point(1, 1, 0) };
    Polygon plgn(pts);

    auto edge = plgn.as_edge();
    auto wire = plgn.as_wire();
}
