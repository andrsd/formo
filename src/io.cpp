// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/io.h"
#include "formo/step_file.h"
#include "formo/iges_file.h"
#include "formo/exception.h"
#include "formo/utils.h"

namespace formo {

void
IO::write(const std::string & file_name,
          const std::vector<Shape> & shapes,
          const std::string & file_format)
{
    std::string fmt = utils::to_lower(file_format);
    if (fmt == "step") {
        STEPFile step(file_name);
        step.write(shapes);
    }
    else if (fmt == "iges") {
        IGESFile iges(file_name);
        iges.write(shapes);
    }
    else
        throw Exception("Unknown format '{}'", file_format);
}

std::vector<Shape>
IO::read(const std::string & file_name)
{
    if (utils::ends_with(file_name, utils::to_lower(".step"))) {
        STEPFile step(file_name);
        return { step.read() };
    }
    else if (utils::ends_with(file_name, utils::to_lower(".iges"))) {
        IGESFile iges(file_name);
        return { iges.read() };
    }
    else
        throw Exception("Unknown file format when reading from '{}'.", file_name);
}

} // namespace formo
