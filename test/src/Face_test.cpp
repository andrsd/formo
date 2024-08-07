#include "gmock/gmock.h"
#include "formo/wire.h"
#include "formo/point.h"
#include "formo/polygon.h"
#include "formo/face.h"
#include "formo/exception.h"
#include <vector>

using namespace formo;

TEST(FaceTest, wire)
{
    Point pt1(0, 0, 0);
    Point pt2(1, 0, 0);
    Point pt3(1, 1, 0);
    Polygon pl({ pt1, pt2, pt3 });
    Face face(pl);

    EXPECT_TRUE(face.is_plane());
    auto pln = face.plane();

    EXPECT_DOUBLE_EQ(face.area(), 0.5);
}
