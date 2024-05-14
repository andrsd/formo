#include "gmock/gmock.h"
#include "formo/wire.h"
#include "formo/point.h"
#include "formo/line.h"
#include "formo/exception.h"

using namespace formo;

TEST(WireTest, empty)
{
    std::vector<Edge> edges;
    EXPECT_THROW({ Wire wire(edges); }, Exception);
}

TEST(WireTest, wire)
{
    Point pt1(0, 0, 0);
    Point pt2(1, 0, 0);
    Point pt3(1, 1, 0);
    Line ln1(pt1, pt2);
    Line ln2(pt2, pt3);
    Wire wire({ ln1, ln2 });
}
