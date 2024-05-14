#include "gmock/gmock.h"
#include "formo/sphere.h"

using namespace formo;

TEST(SphereTest, test)
{
    Sphere sp(Point(0, 0, 0), 2);
    EXPECT_DOUBLE_EQ(sp.volume(), 4. / 3. * M_PI * 8.);
}
