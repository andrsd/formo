#include "gmock/gmock.h"
#include "formo/exception.h"

using namespace formo;

TEST(ExceptionTest, test)
{
    try {
        throw Exception("asdf");
        FAIL();
    }
    catch (Exception & e) {
        EXPECT_STREQ(e.what(), "asdf");
    }
}
