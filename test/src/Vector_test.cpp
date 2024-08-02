#include "gmock/gmock.h"
#include "formo/axis1.h"
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

TEST(VectorTest, is_equal)
{
    Vector vec(1, 2, 3);
    EXPECT_TRUE(vec.is_equal(Vector(1, 2, 3), 1e-14, 1e-14));
    EXPECT_FALSE(vec.is_equal(Vector(-1, -2, -3), 1e-14, 1e-14));
}

TEST(VectorTest, op_mult_scalar)
{
    Vector a(1, 2, 3);
    auto b = 2. * a;
    EXPECT_NEAR(b.x(), 2., 1e-15);
    EXPECT_NEAR(b.y(), 4., 1e-15);
    EXPECT_NEAR(b.z(), 6., 1e-15);
}

TEST(VectorTest, magnitude)
{
    Vector a(3, 0, 4);
    EXPECT_NEAR(a.magnitude(), 5., 1e-15);
}

TEST(VectorTest, rotate)
{
    Vector vec(1, 0, 0);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 0, 1));
    vec.rotate(ax1, 0.5 * M_PI);
    EXPECT_NEAR(vec.x(), 0., 1e-15);
    EXPECT_NEAR(vec.y(), 1., 1e-15);
    EXPECT_NEAR(vec.z(), 0., 1e-15);
}

TEST(VectorTest, rotated)
{
    Vector vec(1, 0, 0);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 0, 1));
    auto r = vec.rotated(ax1, 0.5 * M_PI);
    EXPECT_NEAR(r.x(), 0., 1e-15);
    EXPECT_NEAR(r.y(), 1., 1e-15);
    EXPECT_NEAR(r.z(), 0., 1e-15);
}

TEST(VectorTest, scale)
{
    Vector vec(1, 2, 3);
    vec.scale(2.5);
    EXPECT_NEAR(vec.x(), 2.5, 1e-15);
    EXPECT_NEAR(vec.y(), 5.0, 1e-15);
    EXPECT_NEAR(vec.z(), 7.5, 1e-15);
}

TEST(VectorTest, scaled)
{
    Vector vec(1, 2, 3);
    auto nvec = vec.scaled(2.5);
    EXPECT_NEAR(nvec.x(), 2.5, 1e-15);
    EXPECT_NEAR(nvec.y(), 5.0, 1e-15);
    EXPECT_NEAR(nvec.z(), 7.5, 1e-15);
}
