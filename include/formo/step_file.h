// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "formo/document_file.h"
#include <vector>
#include <string>

namespace formo {

class STEPFile : public DocumentFile {
public:
    /// New STEP file
    ///
    /// @param file_name Name of the file to read
    explicit STEPFile(const std::string & file_name);

    /// Write shapes into a file
    ///
    /// @param shapes Shapes to write
    void write(const std::vector<Shape> & shapes);

private:
    XSControl_Reader * create_reader() override;
};

} // namespace formo
