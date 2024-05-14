// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include <string>

namespace formo {

class IGESFile {
public:
    /// New IGES file
    ///
    /// @param file_name Name of the file to read
    explicit IGESFile(const std::string & file_name);

    /// Read the file
    ///
    /// @return The shape that is contained on the IGES file
    Shape read();

    /// Write shapes into a file
    ///
    /// @param shapes Shapes to write
    void write(const std::vector<Shape> & shapes);

private:
    std::string fname;
};

} // namespace formo
