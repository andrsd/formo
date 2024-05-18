#include "gmock/gmock.h"
#include "formo/io.h"
#include "formo/box.h"
#include "formo/point.h"
#include "formo/exception.h"
#include <filesystem>

using namespace formo;
namespace fs = std::filesystem;

TEST(IO, read_step)
{
    fs::path file = fs::path(FORMO_UNIT_TESTS_ROOT) / "assets" / "box.step";
    EXPECT_NO_THROW({ IO::read(file.string()); });
}

TEST(IO, read_iges)
{
    fs::path file = fs::path(FORMO_UNIT_TESTS_ROOT) / "assets" / "box.iges";
    EXPECT_NO_THROW({ IO::read(file.string()); });
}

TEST(IO, read_unknown)
{
    fs::path file = fs::path(FORMO_UNIT_TESTS_ROOT) / "assets" / "box.asdf";
    EXPECT_THROW({ IO::read(file.string()); }, Exception);
}

TEST(IO, write_step)
{
    fs::path file = fs::path(fs::temp_directory_path()) / "formo-write.step";
    auto box = Box(Point(0, 0, 0), Point(1, 1, 1));
    EXPECT_NO_THROW({ IO::write(file.string(), { box }, "step"); });
}

TEST(IO, write_iges)
{
    fs::path file = fs::path(fs::temp_directory_path()) / "formo-write.iges";
    auto box = Box(Point(0, 0, 0), Point(1, 1, 1));
    EXPECT_NO_THROW({ IO::write(file.string(), { box }, "iges"); });
}

TEST(IO, write_unknown)
{
    fs::path file = fs::path(fs::temp_directory_path()) / "formo-write";
    auto box = Box(Point(0, 0, 0), Point(1, 1, 1));
    EXPECT_THROW({ IO::write(file.string(), { box }, "unknown"); }, Exception);
}
