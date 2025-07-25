// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "formo/document_file.h"
#include <vector>
#include <string>

namespace formo {

class IGESFile : public DocumentFile {
public:
    /// IGES file
    ///
    /// @param file_name Name of the file to work with
    explicit IGESFile(const std::string & file_name);

    /// Write shapes into a file
    ///
    /// @param shapes Shapes to write
    void write(const std::vector<Shape> & shapes);

    /// Read the file
    ///
    /// @return Shapes that were contained in the IGES file
    std::vector<Shape> read() const;
};

} // namespace formo
