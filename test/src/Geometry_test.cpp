#include "gmock/gmock.h"
#include "formo/geometry.h"

using namespace formo;

TEST(GeometryTest, ox)
{
    auto ox = Geometry::OX;
    EXPECT_DOUBLE_EQ(ox.location().x(), 0.);
    EXPECT_DOUBLE_EQ(ox.location().y(), 0.);
    EXPECT_DOUBLE_EQ(ox.location().z(), 0.);
    EXPECT_DOUBLE_EQ(ox.direction().x(), 1.);
    EXPECT_DOUBLE_EQ(ox.direction().y(), 0.);
    EXPECT_DOUBLE_EQ(ox.direction().z(), 0.);
}

TEST(GeometryTest, oy)
{
    auto oy = Geometry::OY;
    EXPECT_DOUBLE_EQ(oy.location().x(), 0.);
    EXPECT_DOUBLE_EQ(oy.location().y(), 0.);
    EXPECT_DOUBLE_EQ(oy.location().z(), 0.);
    EXPECT_DOUBLE_EQ(oy.direction().x(), 0.);
    EXPECT_DOUBLE_EQ(oy.direction().y(), 1.);
    EXPECT_DOUBLE_EQ(oy.direction().z(), 0.);
}

TEST(GeometryTest, oz)
{
    auto oz = Geometry::OZ;
    EXPECT_DOUBLE_EQ(oz.location().x(), 0.);
    EXPECT_DOUBLE_EQ(oz.location().y(), 0.);
    EXPECT_DOUBLE_EQ(oz.location().z(), 0.);
    EXPECT_DOUBLE_EQ(oz.direction().x(), 0.);
    EXPECT_DOUBLE_EQ(oz.direction().y(), 0.);
    EXPECT_DOUBLE_EQ(oz.direction().z(), 1.);
}

TEST(GeometryTest, dx)
{
    auto dx = Geometry::DX;
    EXPECT_DOUBLE_EQ(dx.x(), 1.);
    EXPECT_DOUBLE_EQ(dx.y(), 0.);
    EXPECT_DOUBLE_EQ(dx.z(), 0.);
}

TEST(GeometryTest, dy)
{
    auto dy = Geometry::DY;
    EXPECT_DOUBLE_EQ(dy.x(), 0.);
    EXPECT_DOUBLE_EQ(dy.y(), 1.);
    EXPECT_DOUBLE_EQ(dy.z(), 0.);
}

TEST(GeometryTest, dz)
{
    auto dz = Geometry::DZ;
    EXPECT_DOUBLE_EQ(dz.x(), 0.);
    EXPECT_DOUBLE_EQ(dz.y(), 0.);
    EXPECT_DOUBLE_EQ(dz.z(), 1.);
}
