// SPDX-FileCopyrightText: 2025 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include <vector>
#include <string>

class TDocStd_Document;
class XSControl_Reader;

namespace formo {

/// This class houses common functionality for reading/writing CAD files
class DocumentFile {
public:
    /// Create a file object (no I/O done)
    ///
    /// @param file_name Name of the file to read
    explicit DocumentFile(const std::string & file_name);

    virtual ~DocumentFile() = default;

    /// Get file name
    const std::string file_name() const;

    /// Read the file
    ///
    /// @return Shapes that were contained in the IGES file
    std::vector<Shape> read();

protected:
    TDocStd_Document * create_doc(const std::vector<Shape> & shapes);

private:
    virtual XSControl_Reader * create_reader() = 0;

    std::string fname_;
};

} // namespace formo
