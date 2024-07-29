#include "gmock/gmock.h"
#include "formo/inscribed_polygon.h"
#include "formo/axis2.h"
#include "formo/direction.h"
#include "formo/exception.h"

using namespace formo;

TEST(InscribedPolygonTest, ctor1)
{
    Axis2 ax2(Point(1, 1, 0), Direction(0, 0, 1));
    InscribedPolygon plgn(ax2, 2, 3);

    EXPECT_THROW({ InscribedPolygon(ax2, 2, 1); }, Exception);
}

TEST(InscribedPolygonTest, ctor2)
{
    Axis2 ax2(Point(1, 1, 0), Direction(0, 0, 1));
    InscribedPolygon plgn(ax2, Point(0, 1, 0), 3);

    EXPECT_THROW({ InscribedPolygon(ax2, Point(0, 1, 0), 1); }, Exception);
}
