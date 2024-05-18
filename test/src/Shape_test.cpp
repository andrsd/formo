#include "gmock/gmock.h"
#include "formo/shape.h"
#include "formo/color.h"

using namespace formo;

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
