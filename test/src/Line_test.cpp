#include "gmock/gmock.h"
#include "formo/line.h"

using namespace formo;

TEST(LineTest, test)
{
    Line ln(Point(0, 0, 0), Point(1, 2, 3));
    EXPECT_DOUBLE_EQ(ln.length(), std::sqrt(1 + 4 + 9));
}
