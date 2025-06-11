// SPDX-FileCopyrightText: 2025 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/document_file.h"
#include "formo/exception.h"
#include "Standard_Handle.hxx"
#include "TDocStd_Document.hxx"
#include "XSControl_Reader.hxx"
#include "XCAFDoc_DocumentTool.hxx"
#include "XCAFDoc_ShapeTool.hxx"
#include "XCAFDoc_ColorTool.hxx"
#include "XCAFDoc_MaterialTool.hxx"
#include "XCAFDoc_ColorType.hxx"
#include "TDataStd_Name.hxx"
#include "Quantity_Color.hxx"
#include "Quantity_TypeOfColor.hxx"
#include "TCollection_HAsciiString.hxx"

namespace formo {

DocumentFile::DocumentFile(const std::string & file_name) : fname_(file_name) {}

const std::string
DocumentFile::file_name() const
{
    return this->fname_;
}

TDocStd_Document *
DocumentFile::create_doc(const std::vector<Shape> & shapes)
{
    auto doc = new TDocStd_Document(TCollection_ExtendedString("formo-doc"));
    auto shape_tool = XCAFDoc_DocumentTool::ShapeTool(doc->Main());
    auto color_tool = XCAFDoc_DocumentTool::ColorTool(doc->Main());
    auto material_tool = XCAFDoc_DocumentTool::MaterialTool(doc->Main());
    for (auto & shp : shapes) {
        auto shape_label = shape_tool->AddShape(shp, false);
        if (!shp.name().empty())
            TDataStd_Name::Set(shape_label, TCollection_ExtendedString(shp.name().c_str()));

        auto clr = shp.color();
        Quantity_Color color(clr.redF(),
                             clr.greenF(),
                             clr.blueF(),
                             Quantity_TypeOfColor::Quantity_TOC_RGB);
        color_tool->SetColor(shape_label, color, XCAFDoc_ColorGen);

        if (shp.has_material()) {
            Handle(TCollection_HAsciiString) mat_name =
                new TCollection_HAsciiString(shp.material().c_str());
            Handle(TCollection_HAsciiString) mat_descr =
                new TCollection_HAsciiString(shp.material_description().c_str());
            Handle(TCollection_HAsciiString) density_name =
                new TCollection_HAsciiString("Mass density");
            Handle(TCollection_HAsciiString) density_value_type =
                new TCollection_HAsciiString("g/cm^3");
            auto mat_label = material_tool->AddMaterial(mat_name,
                                                        mat_descr,
                                                        shp.density(),
                                                        density_name,
                                                        density_value_type);
            material_tool->SetMaterial(shape_label, mat_label);
        }
    }
    return doc;
}

} // namespace formo
