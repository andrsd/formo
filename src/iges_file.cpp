// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/iges_file.h"
#include "formo/exception.h"
#include "IGESControl_Reader.hxx"
#include "IGESCAFControl_Writer.hxx"
#include "TDocStd_Document.hxx"

namespace formo {

IGESFile::IGESFile(const std::string & file_name) : DocumentFile(file_name) {}

void
IGESFile::write(const std::vector<Shape> & shapes)
{
    Handle(TDocStd_Document) doc = create_doc(shapes);

    IGESCAFControl_Writer writer;
    writer.SetNameMode(true);
    if (writer.Transfer(doc)) {
        writer.Write(file_name().c_str());
    }
}

XSControl_Reader *
IGESFile::create_reader()
{
    return new IGESControl_Reader();
}

} // namespace formo
