// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/step_file.h"
#include "formo/exception.h"
#include "STEPControl_Reader.hxx"
#include "Standard_Handle.hxx"
#include "TDocStd_Document.hxx"
#include "XCAFDoc_DocumentTool.hxx"
#include "XCAFDoc_ShapeTool.hxx"
#include "XCAFDoc_ColorTool.hxx"
#include "XCAFDoc_ColorType.hxx"
#include "TDataStd_Name.hxx"
#include "Quantity_Color.hxx"
#include "Quantity_TypeOfColor.hxx"
#include "STEPCAFControl_Writer.hxx"

namespace formo {

STEPFile::STEPFile(const std::string & file_name) : fname(file_name) {}

Shape
STEPFile::read()
{
    STEPControl_Reader reader;
    if (reader.ReadFile(this->fname.c_str()) != IFSelect_RetDone)
        throw Exception("Unable to load '{}'", this->fname);
    reader.NbRootsForTransfer();
    reader.TransferRoot();
    return Shape(reader.OneShape());
}

void
STEPFile::write(const std::vector<Shape> & shapes)
{
    Handle(TDocStd_Document) doc = new TDocStd_Document(TCollection_ExtendedString("formo-doc"));
    auto shape_tool = XCAFDoc_DocumentTool::ShapeTool(doc->Main());
    auto color_tool = XCAFDoc_DocumentTool::ColorTool(doc->Main());
    for (auto & shp : shapes) {
        auto label = shape_tool->AddShape(shp, false);
        if (!shp.name().empty())
            TDataStd_Name::Set(label, TCollection_ExtendedString(shp.name().c_str()));

        auto clr = shp.color();
        Quantity_Color color(clr.redF(),
                             clr.greenF(),
                             clr.blueF(),
                             Quantity_TypeOfColor::Quantity_TOC_RGB);
        color_tool->SetColor(label, color, XCAFDoc_ColorGen);
    }

    STEPCAFControl_Writer writer;
    writer.SetNameMode(true);
    writer.SetColorMode(true);
    if (writer.Transfer(doc, STEPControl_AsIs)) {
        writer.Write(this->fname.c_str());
    }
}

} // namespace formo
