// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/shell.h"

namespace formo {

Shell::Shell(const TopoDS_Shell & shell) : Shape(shell), shell_(shell) {}

Shell::operator TopoDS_Shell() const
{
    return this->shell_;
}

} // namespace formo
