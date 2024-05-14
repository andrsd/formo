#include "gmock/gmock.h"
#include "formo/prism.h"
#include "formo/polygon.h"

using namespace formo;

TEST(PrismTest, test)
{
    std::vector<Point> pts = { Point(0, 0, 0), Point(1, 0, 0), Point(1, 1, 0) };
    Polygon plgn(pts);

    Prism prm(plgn, Vector(0, 0, 2));
}
