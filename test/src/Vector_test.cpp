#include "gmock/gmock.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
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

TEST(VectorTest, is_normal)
{
    Vector vec(1, 0, 0);
    EXPECT_TRUE(vec.is_normal(Vector(0, 1, 0), 1e-14));
    EXPECT_FALSE(vec.is_normal(Vector(-1, -2, -3), 1e-14));
}

TEST(VectorTest, is_opposite)
{
    Vector vec(1, 2, 3);
    EXPECT_TRUE(vec.is_opposite(Vector(-1, -2, -3), 1e-14));
    EXPECT_FALSE(vec.is_opposite(Vector(0, 2, -3), 1e-14));
}

TEST(VectorTest, is_parallel)
{
    Vector vec(1, 2, 3);
    EXPECT_TRUE(vec.is_parallel(Vector(-1, -2, -3), 1e-14));
    EXPECT_FALSE(vec.is_parallel(Vector(0, 2, -3), 1e-14));
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

TEST(VectorTest, mirror_vec)
{
    Vector vec(1, 0, -2);
    Vector symm(0, 0, 1);
    vec.mirror(symm);
    EXPECT_NEAR(vec.x(), -1, 1e-15);
    EXPECT_NEAR(vec.y(), 0, 1e-15);
    EXPECT_NEAR(vec.z(), -2, 1e-15);
}

TEST(VectorTest, mirror_ax1)
{
    Vector vec(1, 0, -2);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 1, 0));
    vec.mirror(ax1);
    EXPECT_NEAR(vec.x(), -1, 1e-15);
    EXPECT_NEAR(vec.y(), 0, 1e-15);
    EXPECT_NEAR(vec.z(), 2, 1e-15);
}

TEST(VectorTest, mirror_ax2)
{
    Vector vec(1, 0, -2);
    Axis2 ax2(Point(0, 0, 0), Direction(1, 0, 0));
    vec.mirror(ax2);
    EXPECT_NEAR(vec.x(), -1, 1e-15);
    EXPECT_NEAR(vec.y(), 0, 1e-15);
    EXPECT_NEAR(vec.z(), -2, 1e-15);
}

TEST(VectorTest, mirrored_pt)
{
    Vector vec(1, 0, -2);
    Vector symm(0, 0, 1);
    auto npt = vec.mirrored(symm);
    EXPECT_NEAR(npt.x(), -1, 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), -2, 1e-15);
}

TEST(VectorTest, mirrored_ax1)
{
    Vector vec(1, 0, -2);
    Axis1 ax1(Point(0, 0, 0), Direction(0, 1, 0));
    auto npt = vec.mirrored(ax1);
    EXPECT_NEAR(npt.x(), -1, 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), 2, 1e-15);
}

TEST(VectorTest, mirrored_ax2)
{
    Vector vec(1, 0, -2);
    Axis2 ax2(Point(0, 0, 0), Direction(1, 0, 0));
    auto npt = vec.mirrored(ax2);
    EXPECT_NEAR(npt.x(), -1, 1e-15);
    EXPECT_NEAR(npt.y(), 0, 1e-15);
    EXPECT_NEAR(npt.z(), -2, 1e-15);
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

TEST(VectorTest, op_add)
{
    Vector vec(1, 2, 3);
    auto res = vec + Vector(2, -3, 1);
    EXPECT_NEAR(res.x(), 3, 1e-15);
    EXPECT_NEAR(res.y(), -1, 1e-15);
    EXPECT_NEAR(res.z(), 4, 1e-15);
}

TEST(VectorTest, op_sub)
{
    Vector vec(1, 2, 3);
    auto res = vec - Vector(2, -3, 1);
    EXPECT_NEAR(res.x(), -1, 1e-15);
    EXPECT_NEAR(res.y(), 5, 1e-15);
    EXPECT_NEAR(res.z(), 2, 1e-15);
}

TEST(VectorTest, op_mult_scalar_post)
{
    auto res = Vector(1, 2, 3) * 1.5;
    EXPECT_NEAR(res.x(), 1.5, 1e-15);
    EXPECT_NEAR(res.y(), 3., 1e-15);
    EXPECT_NEAR(res.z(), 4.5, 1e-15);
}

TEST(VectorTest, dot_product)
{
    auto dot = dot_product(Vector(1, 2, 3), Vector(-2, 3, 5));
    EXPECT_NEAR(dot, 19, 1e-15);
}
