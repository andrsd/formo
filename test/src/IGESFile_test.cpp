#include "gmock/gmock.h"
#include "formo/iges_file.h"
#include "formo/exception.h"
#include "formo/box.h"
#include <filesystem>

using namespace formo;
namespace fs = std::filesystem;

TEST(IGESFileTest, read_nonexistent_file)
{
    fs::path file = fs::path(FORMO_UNIT_TESTS_ROOT) / "no-such-file.iges";
    IGESFile step(file.string());
    EXPECT_THROW({ step.read(); }, Exception);
}

TEST(IGESFileTest, read)
{
    fs::path file = fs::path(FORMO_UNIT_TESTS_ROOT) / "assets" / "box.iges";
    IGESFile step(file.string());
    EXPECT_NO_THROW({ auto shape = step.read(); });
}

TEST(IGESFileTest, write)
{
    fs::path file = fs::path(fs::temp_directory_path()) / "formo-write.iges";
    IGESFile step(file.string());
    auto box = Box(Point(0, 0, 0), Point(1, 1, 1));
    box.set_name("box");
    EXPECT_NO_THROW({ step.write({ box }); });
}
