#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "formo/box.h"
#include "formo/shape.h"
#include "formo/edge.h"
#include "formo/face.h"
#include "formo/color.h"

using namespace formo;
using namespace testing;

namespace formo {

bool
operator==(const Point & first, const Point & second)
{
    return first.is_equal(second);
}

} // namespace formo

TEST(ShapeTest, name)
{
    Shape shape;
    shape.set_name("my-name");
    EXPECT_EQ(shape.name(), "my-name");
}

TEST(ShapeTest, color)
{
    Shape shape;
    shape.set_color(Color(10, 20, 30));
    EXPECT_EQ(shape.color().red(), 10);
    EXPECT_EQ(shape.color().green(), 20);
    EXPECT_EQ(shape.color().blue(), 30);
}

TEST(ShapeTest, material)
{
    Shape shape;
    EXPECT_FALSE(shape.has_material());
    shape.set_material("steel", "SS316", 7850);
    EXPECT_TRUE(shape.has_material());
    EXPECT_EQ(shape.material(), "steel");
    EXPECT_EQ(shape.material_description(), "SS316");
    EXPECT_NEAR(shape.density(), 7850, 1e-10);
}

TEST(ShapeTest, vertices)
{
    Box box(Point(0, 0, 0), Point(1, 2, 3));
    auto vertices = box.vertices();
    EXPECT_EQ(vertices.size(), 8);
    EXPECT_THAT(vertices,
                UnorderedElementsAre(Eq(Point(0, 0, 3)),
                                     Eq(Point(0, 0, 0)),
                                     Eq(Point(0, 2, 3)),
                                     Eq(Point(0, 2, 0)),
                                     Eq(Point(1, 0, 3)),
                                     Eq(Point(1, 0, 0)),
                                     Eq(Point(1, 2, 3)),
                                     Eq(Point(1, 2, 0))));
}

TEST(ShapeTest, edges)
{
    Box box(Point(0, 0, 0), Point(1, 2, 3));
    auto edges = box.edges();
    EXPECT_EQ(edges.size(), 12);
}

TEST(ShapeTest, faces)
{
    Box box(Point(0, 0, 0), Point(1, 2, 3));
    auto faces = box.faces();
    EXPECT_EQ(faces.size(), 6);
}

TEST(ShapeTest, solids)
{
    Box box(Point(0, 0, 0), Point(1, 2, 3));
    auto solids = box.solids();
    EXPECT_EQ(solids.size(), 1);
}
