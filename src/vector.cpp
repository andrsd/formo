// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/vector.h"
#include "formo/direction.h"

namespace formo {

Vector::Vector(double x, double y, double z) : vec(x, y, z) {}

Vector::Vector(const Direction & dir) : vec(dir) {}

double
Vector::x() const
{
    return this->vec.X();
}

double
Vector::y() const
{
    return this->vec.Y();
}

double
Vector::z() const
{
    return this->vec.Z();
}

Vector::operator gp_Vec() const
{
    return this->vec;
}

} // namespace formo
