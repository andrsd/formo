// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/vector.h"
#include "formo/direction.h"
#include "formo/point.h"

namespace formo {

Vector::Vector(double x, double y, double z) : vec(x, y, z) {}

Vector::Vector(const Direction & dir) : vec(dir) {}

Vector::Vector(const Point & pt1, const Point & pt2) : vec(pt1, pt2) {}

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

Vector
operator*(double alpha, const Vector & vec)
{
    return Vector(alpha * vec.x(), alpha * vec.y(), alpha * vec.z());
}

} // namespace formo
