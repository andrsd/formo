// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/vector.h"
#include "formo/direction.h"
#include "formo/point.h"
#include "formo/axis1.h"

namespace formo {

Vector::Vector(const gp_Vec & vec) : vec(vec) {}

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

bool
Vector::is_equal(const Vector & other, double lin_tol, double ang_tol) const
{
    return this->vec.IsEqual(other, lin_tol, ang_tol);
}

bool
Vector::is_normal(const Vector & other, double ang_tol) const
{
    return this->vec.IsNormal(other, ang_tol);
}

bool
Vector::is_opposite(const Vector & other, double ang_tol) const
{
    return this->vec.IsOpposite(other, ang_tol);
}

bool
Vector::is_parallel(const Vector & other, double ang_tol) const
{
    return this->vec.IsParallel(other, ang_tol);
}

double
Vector::magnitude() const
{
    return this->vec.Magnitude();
}

void
Vector::rotate(const Axis1 & ax1, const double angle)
{
    this->vec.Rotate(ax1, angle);
}

Vector
Vector::rotated(const Axis1 & ax1, const double angle) const
{
    return Vector(this->vec.Rotated(ax1, angle));
}

void
Vector::scale(double s)
{
    this->vec.Scale(s);
}

Vector
Vector::scaled(double s) const
{
    return Vector(this->vec.Scaled(s));
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

Vector
Vector::operator+(const Vector & other) const
{
    return Vector(x() + other.x(), y() + other.y(), z() + other.z());
}

Vector
Vector::operator-(const Vector & other) const
{
    return Vector(x() - other.x(), y() - other.y(), z() - other.z());
}

} // namespace formo
