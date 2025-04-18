// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/solid.h"
#include "formo/shell.h"
#include "formo/exception.h"
#include "BRepBuilderAPI_MakeSolid.hxx"
#include "GProp_GProps.hxx"
#include "BRepGProp.hxx"

namespace formo {

Solid::Solid(const TopoDS_Solid & solid) : Shape(solid), solid_(solid) {}

Solid::Solid(const Shell & shell)
{
    BRepBuilderAPI_MakeSolid mk(shell);
    if (!mk.IsDone())
        throw Exception("Solid was not created");
    this->solid_ = mk.Solid();
    set_shape(this->solid_);
}

void
Solid::set_solid(const TopoDS_Solid & solid)
{
    this->solid_ = solid;
}

Solid::operator TopoDS_Solid() const
{
    return this->solid_;
}

} // namespace formo
