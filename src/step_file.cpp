// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/step_file.h"
#include "formo/exception.h"
#include "STEPControl_Reader.hxx"
#include "STEPCAFControl_Writer.hxx"
#include "TDocStd_Document.hxx"

namespace formo {

STEPFile::STEPFile(const std::string & file_name) : DocumentFile(file_name) {}

void
STEPFile::write(const std::vector<Shape> & shapes)
{
    Handle(TDocStd_Document) doc = create_doc(shapes);

    STEPCAFControl_Writer writer;
    writer.SetNameMode(true);
    writer.SetColorMode(true);
    if (writer.Transfer(doc, STEPControl_AsIs)) {
        writer.Write(file_name().c_str());
    }
}

XSControl_Reader *
STEPFile::create_reader()
{
    return new STEPControl_Reader();
}

} // namespace formo
