// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/step_file.h"
#include "formo/exception.h"
#include "STEPCAFControl_Reader.hxx"
#include "STEPCAFControl_Writer.hxx"
#include "TDataStd_Name.hxx"
#include "TDataStd_TreeNode.hxx"
#include "TDocStd_Document.hxx"
#include "XCAFDoc.hxx"
#include "XCAFDoc_Material.hxx"
#include "XCAFDoc_DocumentTool.hxx"
#include "XCAFDoc_ShapeTool.hxx"
#include "XCAFDoc_ColorTool.hxx"

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

std::vector<Shape>
STEPFile::read() const
{
    std::vector<Shape> shapes;

    TCollection_AsciiString fname(file_name().c_str());
    STEPCAFControl_Reader reader;
    reader.SetNameMode(Standard_True);
    reader.SetColorMode(Standard_True);
    reader.SetMatMode(Standard_True);

    Handle(TDocStd_Document) doc = new TDocStd_Document(TCollection_ExtendedString("formo-doc"));
    if (!reader.Perform(fname, doc))
        throw Exception("Failed to load STEP file");

    auto shape_tool = XCAFDoc_DocumentTool::ShapeTool(doc->Main());
    auto material_tool = XCAFDoc_DocumentTool::MaterialTool(doc->Main());

    TDF_LabelSequence shape_labels;
    shape_tool->GetShapes(shape_labels);

    for (Standard_Integer i = 1; i <= shape_labels.Length(); ++i) {
        auto shape_label = shape_labels.Value(i);
        auto shape = XCAFDoc_ShapeTool::GetShape(shape_label);
        Shape formo_shape(shape);

        // Get the name associated with the label
        Handle(TDataStd_Name) name_attr;
        if (shape_label.FindAttribute(TDataStd_Name::GetID(), name_attr)) {
            auto name = name_attr->Get();
            char * nm = new char[name.LengthOfCString()];
            name.ToUTF8CString(nm);
            formo_shape.set_name(nm);
            delete[] nm;
        }

        // get material associated with the label (if any)
        Handle(TDataStd_TreeNode) node;
        if (shape_label.FindAttribute(XCAFDoc::MaterialRefGUID(), node) && node->HasFather()) {
            const TDF_Label material_label = node->Father()->Label();
            Handle(XCAFDoc_Material) mat;
            if (material_label.FindAttribute(XCAFDoc_Material::GetID(), mat)) {
                formo_shape.set_material(mat->GetName()->ToCString(),
                                         mat->GetDescription()->ToCString(),
                                         mat->GetDensity());
            }
        }

        shapes.push_back(formo_shape);
    }

    return shapes;
}

} // namespace formo
