// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/color.h"

namespace formo {

Color::Color() : r_(0), g_(0), b_(0) {}

Color::Color(int r, int g, int b) : r_(r), g_(g), b_(b) {}

int
Color::red() const
{
    return this->r_;
}

double
Color::redF() const
{
    return this->r_ / 255.;
}

int
Color::green() const
{
    return this->g_;
}

double
Color::greenF() const
{
    return this->g_ / 255.;
}

int
Color::blue() const
{
    return this->b_;
}

double
Color::blueF() const
{
    return this->b_ / 255.;
}

} // namespace formo
