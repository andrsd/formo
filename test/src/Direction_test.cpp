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

TEST(DirectionTest, rotate)
{
    Direction dir(1, 0, 0);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 0, 1));
    dir.rotate(ax1, 0.5 * M_PI);
    EXPECT_NEAR(dir.x(), 0., 1e-15);
    EXPECT_NEAR(dir.y(), 1., 1e-15);
    EXPECT_NEAR(dir.z(), 0., 1e-15);
}

TEST(DirectionTest, rotated)
{
    Direction dir(1, 0, 0);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 0, 1));
    auto r = dir.rotated(ax1, 0.5 * M_PI);
    EXPECT_NEAR(r.x(), 0., 1e-15);
    EXPECT_NEAR(r.y(), 1., 1e-15);
    EXPECT_NEAR(r.z(), 0., 1e-15);
}

TEST(DirectionTest, reverse)
{
    auto sqrt5 = std::sqrt(5);
    Direction dir(1, 0, -2);
    dir.reverse();
    EXPECT_NEAR(dir.x(), -1. / sqrt5, 1e-15);
    EXPECT_NEAR(dir.y(), 0., 1e-15);
    EXPECT_NEAR(dir.z(), 2. / sqrt5, 1e-15);
}

TEST(DirectionTest, reversed)
{
    auto sqrt5 = std::sqrt(5);
    Direction dir(1, 0, -2);
    auto rev = dir.reversed();
    EXPECT_NEAR(rev.x(), -1. / sqrt5, 1e-15);
    EXPECT_NEAR(rev.y(), 0., 1e-15);
    EXPECT_NEAR(rev.z(), 2. / sqrt5, 1e-15);
}

TEST(DirectionTest, op_minus_unary)
{
    Direction a(1, 0, 0);
    auto b = -a;
    EXPECT_NEAR(b.x(), -1., 1e-15);
    EXPECT_NEAR(b.y(), 0., 1e-15);
    EXPECT_NEAR(b.z(), 0., 1e-15);
}
