#include "gmock/gmock.h"
#include "formo/helix.h"
#include "formo/point.h"
#include "formo/vector.h"
#include "formo/axis2.h"

using namespace formo;

TEST(HelixTest, ctor1)
{
    Axis2 ctr(Point(0, 0, 0), Direction(1, 0, 0));
    Helix helix(ctr, 2., 8., 4);
}
