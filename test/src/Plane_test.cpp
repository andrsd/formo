#include "gmock/gmock.h"
#include "formo/plane.h"

using namespace formo;

TEST(PlaneTest, ctor)
{
    Plane plane(Point(1, 2, 3), Direction(0, 0, 1));
    EXPECT_DOUBLE_EQ(plane.location().x(), 1);
    EXPECT_DOUBLE_EQ(plane.location().y(), 2);
    EXPECT_DOUBLE_EQ(plane.location().z(), 3);
}

TEST(PlaneTest, ctor2)
{
    gp_Pnt pt(1, 2, 3);
    gp_Dir dir(0, 0, 1);
    gp_Pln pln(pt, dir);
    Plane plane(pln);
    EXPECT_DOUBLE_EQ(plane.location().x(), 1);
    EXPECT_DOUBLE_EQ(plane.location().y(), 2);
    EXPECT_DOUBLE_EQ(plane.location().z(), 3);
}
