#include "gmock/gmock.h"
#include "formo/step_file.h"
#include "formo/exception.h"
#include "formo/box.h"
#include <filesystem>

using namespace formo;
namespace fs = std::filesystem;

TEST(STEPFileTest, read_nonexistent_file)
{
    fs::path file = fs::path(FORMO_UNIT_TESTS_ROOT) / "no-such-file.step";
    STEPFile step(file.string());
    EXPECT_THROW({ step.read(); }, Exception);
}

TEST(STEPFileTest, read)
{
    fs::path file = fs::path(FORMO_UNIT_TESTS_ROOT) / "assets" / "box.step";
    STEPFile step(file.string());
    EXPECT_NO_THROW({ auto shape = step.read(); });
}

TEST(STEPFileTest, write)
{
    fs::path file = fs::path(fs::temp_directory_path()) / "formo-write.step";
    STEPFile step(file.string());
    auto box = Box(Point(0, 0, 0), Point(1, 1, 1));
    box.set_name("box");
    EXPECT_NO_THROW({ step.write({ box }); });
}
