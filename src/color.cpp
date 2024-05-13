// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/color.h"

namespace formo {

Color::Color() : r(0), g(0), b(0) {}

Color::Color(int r, int g, int b) : r(r), g(g), b(b) {}

int
Color::red() const
{
    return this->r;
}

double
Color::redF() const
{
    return this->r / 255.;
}

int
Color::green() const
{
    return this->g;
}

double
Color::greenF() const
{
    return this->g / 255.;
}

int
Color::blue() const
{
    return this->b;
}

double
Color::blueF() const
{
    return this->b / 255.;
}


} // namespace formo
