#include "gmock/gmock.h"
#include "formo/direction.h"
#include "formo/vector.h"
#include "formo/axis1.h"
#include "formo/axis2.h"

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

TEST(DirectionTest, mirror_vec)
{
    Direction dir(1, 0, -2);
    Direction symm(0, 0, 1);
    dir.mirror(symm);
    auto sqrt5 = std::sqrt(5);
    EXPECT_NEAR(dir.x(), -1 / sqrt5, 1e-15);
    EXPECT_NEAR(dir.y(), 0, 1e-15);
    EXPECT_NEAR(dir.z(), -2 / sqrt5, 1e-15);
}

TEST(DirectionTest, mirror_ax1)
{
    Direction dir(1, 0, 0);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 1, 0));
    dir.mirror(ax1);
    EXPECT_NEAR(dir.x(), -1, 1e-15);
    EXPECT_NEAR(dir.y(), 0, 1e-15);
    EXPECT_NEAR(dir.z(), 0, 1e-15);
}

TEST(DirectionTest, mirror_ax2)
{
    Direction dir(1, 0, -2);
    Axis2 ax2(Point(0, 0, 0), Direction(1, 0, 0));
    dir.mirror(ax2);
    auto sqrt5 = std::sqrt(5);
    EXPECT_NEAR(dir.x(), -1 / sqrt5, 1e-15);
    EXPECT_NEAR(dir.y(), 0, 1e-15);
    EXPECT_NEAR(dir.z(), -2 / sqrt5, 1e-15);
}

TEST(DirectionTest, mirrored_pt)
{
    Direction dir(1, 0, -2);
    Direction symm(0, 0, 1);
    auto sqrt5 = std::sqrt(5);
    auto npt = dir.mirrored(symm);
    EXPECT_NEAR(npt.x(), -1 / sqrt(5), 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), -2 / sqrt(5), 1e-15);
}

TEST(DirectionTest, mirrored_ax1)
{
    Direction dir(1, 0, 0);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 1, 0));
    auto npt = dir.mirrored(ax1);
    EXPECT_NEAR(npt.x(), -1, 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), 0, 1e-15);
}

TEST(DirectionTest, mirrored_ax2)
{
    Direction dir(1, 0, -2);
    Axis2 ax2(Point(0, 0, 0), Direction(1, 0, 0));
    auto npt = dir.mirrored(ax2);
    auto sqrt5 = std::sqrt(5);
    EXPECT_NEAR(npt.x(), -1 / sqrt5, 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), -2 / sqrt5, 1e-15);
}
