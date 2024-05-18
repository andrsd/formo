#include "gmock/gmock.h"
#include "formo/utils.h"

using namespace formo;

TEST(Utils, to_lower)
{
    EXPECT_EQ(utils::to_lower("AsDf"), "asdf");
}

TEST(Utils, ends_with)
{
    EXPECT_TRUE(utils::ends_with("file.ext", ".ext"));
    EXPECT_FALSE(utils::ends_with("file.ext", "asdf"));
}
