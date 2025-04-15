// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "TopoDS_Shell.hxx"

namespace formo {

class Shell : public Shape {
public:
    Shell(const TopoDS_Shell & shell);

    operator TopoDS_Shell() const;

private:
    TopoDS_Shell shell_;
};

} // namespace formo
