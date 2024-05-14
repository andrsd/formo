#include "gmock/gmock.h"
#include "formo/arc_of_circle.h"

using namespace formo;

TEST(ArcofCircleTest, ctor1)
{
    ArcOfCircle arc(Point(-1, 0, 0), Point(0, 1, 0), Point(1, 0, 0));
    EXPECT_TRUE(arc.start_point().is_equal(Point(-1, 0, 0)));
    EXPECT_TRUE(arc.end_point().is_equal(Point(1, 0, 0)));
}

TEST(ArcofCircleTest, ctor2)
{
    ArcOfCircle arc(Point(-1, 0, 0), Vector(0, 1, 0), Point(1, 0, 0));
    EXPECT_TRUE(arc.start_point().is_equal(Point(-1, 0, 0)));
    EXPECT_TRUE(arc.end_point().is_equal(Point(1, 0, 0)));
}

TEST(ArcofCircleTest, ctor3)
{
    Circle circ(Point(0, 0, 0), 2.);

    ArcOfCircle arc(circ, Point(-2, 0, 0), Point(0, 2, 0));
    EXPECT_TRUE(arc.start_point().is_equal(Point(-2, 0, 0)));
    EXPECT_TRUE(arc.end_point().is_equal(Point(0, 2, 0)));
}
