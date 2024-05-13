// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "formo/config.h"

namespace py = pybind11;

PYBIND11_MODULE(formo, m)
{
    m.doc() = "pybind11 plugin for formo";
    py::setattr(m, "version", py::str(FORMO_VERSION));
}
