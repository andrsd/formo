#include "gmock/gmock.h"
#include "formo/direction.h"

using namespace formo;

TEST(DirectionTest, ctor1)
{
    Direction pt(3, 4, 5);
    EXPECT_DOUBLE_EQ(pt.x(), 3. / std::sqrt(50));
    EXPECT_DOUBLE_EQ(pt.y(), 4. / std::sqrt(50));
    EXPECT_DOUBLE_EQ(pt.z(), 5. / std::sqrt(50));
}
