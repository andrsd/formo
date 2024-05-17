#include "gmock/gmock.h"
#include "formo/vector.h"
#include "formo/direction.h"
#include "formo/point.h"

using namespace formo;

TEST(VectorTest, ctor1)
{
    Vector pt(1, 2, 3);
    EXPECT_DOUBLE_EQ(pt.x(), 1);
    EXPECT_DOUBLE_EQ(pt.y(), 2);
    EXPECT_DOUBLE_EQ(pt.z(), 3);
}

TEST(VectorTest, ctor2)
{
    Direction dir(1, 0, 0);
    Vector vec(dir);
    EXPECT_DOUBLE_EQ(vec.x(), 1);
    EXPECT_DOUBLE_EQ(vec.y(), 0);
    EXPECT_DOUBLE_EQ(vec.z(), 0);
}

TEST(VectorTest, ctor3)
{
    Point pt1(1, 2, 3);
    Point pt2(2, -1, 3);
    Vector vec(pt1, pt2);
    EXPECT_DOUBLE_EQ(vec.x(), 1);
    EXPECT_DOUBLE_EQ(vec.y(), -3);
    EXPECT_DOUBLE_EQ(vec.z(), 0);
}
