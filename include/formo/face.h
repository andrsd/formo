// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include "formo/shape.h"
#include "formo/wire.h"
#include "formo/plane.h"
#include "TopoDS_Face.hxx"

namespace formo {

class Face : public Shape {
public:
    explicit Face(const Wire & wire);

    explicit Face(const TopoDS_Face & face);

    bool is_plane() const;

    Plane plane() const;

    operator TopoDS_Face() const;

private:
    TopoDS_Face face_;
};

} // namespace formo
