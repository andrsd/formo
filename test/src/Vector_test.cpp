#include "gmock/gmock.h"
#include "formo/vector.h"
#include "formo/direction.h"

using namespace formo;

TEST(VectorTest, ctor1)
{
    Vector pt(1, 2, 3);
    EXPECT_DOUBLE_EQ(pt.x(), 1);
    EXPECT_DOUBLE_EQ(pt.y(), 2);
    EXPECT_DOUBLE_EQ(pt.z(), 3);
}

TEST(VectorTest, ctor2) {
    Direction dir(1, 0, 0);
    Vector vec(dir);
    EXPECT_DOUBLE_EQ(vec.x(), 1);
    EXPECT_DOUBLE_EQ(vec.y(), 0);
    EXPECT_DOUBLE_EQ(vec.z(), 0);
}
