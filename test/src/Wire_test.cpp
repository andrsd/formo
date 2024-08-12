#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include "formo/wire.h"
#include "formo/point.h"
#include "formo/line.h"
#include "formo/exception.h"
#include "formo/polygon.h"
#include "formo/shell.h"
#include "formo/direction.h"
#include "BRepOffsetAPI_MakeDraft.hxx"

using namespace formo;

namespace {

double
radians(double deg)
{
    return deg * M_PI / 180.;
}

} // namespace

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

TEST(WireTest, length)
{
    Point pt1(0, 0, 0);
    Point pt2(1, 0, 0);
    Point pt3(1, 1, 0);
    Line ln1(pt1, pt2);
    Line ln2(pt2, pt3);
    Wire wire({ ln1, ln2 });
    EXPECT_DOUBLE_EQ(wire.length(), 2.);
}

TEST(WireTest, draft_wire)
{
    Polygon poly({ Point(0, 0, 0), Point(1, 0, 0), Point(1, 1, 0) });
    auto shell = poly.draft(Direction(0, 0, 1), radians(3), 1.0);
}
