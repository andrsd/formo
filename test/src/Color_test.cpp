#include "gmock/gmock.h"
#include "formo/color.h"

using namespace formo;

TEST(ColorTest, black)
{
    Color clr;
    EXPECT_EQ(clr.red(), 0);
    EXPECT_EQ(clr.green(), 0);
    EXPECT_EQ(clr.blue(), 0);
}

TEST(ColorTest, test)
{
    Color clr(51, 85, 17);
    EXPECT_EQ(clr.red(), 51);
    EXPECT_EQ(clr.green(), 85);
    EXPECT_EQ(clr.blue(), 17);

    EXPECT_DOUBLE_EQ(clr.redF(), 0.2);
    EXPECT_DOUBLE_EQ(clr.greenF(), 1./3.);
    EXPECT_DOUBLE_EQ(clr.blueF(), 1./15.);
}
