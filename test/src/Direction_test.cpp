#include "gmock/gmock.h"
#include "formo/direction.h"
#include "formo/vector.h"

using namespace formo;

TEST(DirectionTest, ctor1)
{
    Direction pt(3, 4, 5);
    EXPECT_DOUBLE_EQ(pt.x(), 3. / std::sqrt(50));
    EXPECT_DOUBLE_EQ(pt.y(), 4. / std::sqrt(50));
    EXPECT_DOUBLE_EQ(pt.z(), 5. / std::sqrt(50));
}

TEST(DirectionTest, ctor2)
{
    Vector vec(3, 4, 5);
    Direction dir(vec);
    EXPECT_DOUBLE_EQ(dir.x(), 3. / std::sqrt(50));
    EXPECT_DOUBLE_EQ(dir.y(), 4. / std::sqrt(50));
    EXPECT_DOUBLE_EQ(dir.z(), 5. / std::sqrt(50));
}
