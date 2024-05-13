// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/prism.h"
#include "formo/exception.h"
#include "BRepPrimAPI_MakePrism.hxx"

namespace formo {

Prism::Prism(const Shape & shape, const Vector & vec)
{
    BRepPrimAPI_MakePrism prism(shape, vec);
    prism.Build();
    if (!prism.IsDone())
        throw Exception("Prism was not created");
    set_shape(prism.Shape());
}

} // namespace formo
