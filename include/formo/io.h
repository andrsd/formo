// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include <string>
#include <vector>

namespace formo {

class IO {
public:
    /// Write shapes into a file
    ///
    /// @param file_name Name of the file
    /// @param shapes List of shapes
    /// @param file_format File format ['step', 'iges']
    static void write(const std::string & file_name,
                      const std::vector<Shape> & shapes,
                      const std::string & file_format = "step");

    /// Read shapes from a file
    ///
    /// @param file_name Name of the file
    /// @return
    static std::vector<Shape> read(const std::string & file_name);
};

} // namespace formo
