// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/vector.h"
#include "formo/direction.h"
#include "formo/point.h"
#include "formo/axis1.h"
#include "formo/axis2.h"

namespace formo {

Vector::Vector(const gp_Vec & vec) : vec_(vec) {}

Vector::Vector(double x, double y, double z) : vec_(x, y, z) {}

Vector::Vector(const Direction & dir) : vec_(dir) {}

Vector::Vector(const Point & pt1, const Point & pt2) : vec_(pt1, pt2) {}

double
Vector::x() const
{
    return this->vec_.X();
}

double
Vector::y() const
{
    return this->vec_.Y();
}

double
Vector::z() const
{
    return this->vec_.Z();
}

bool
Vector::is_equal(const Vector & other, double lin_tol, double ang_tol) const
{
    return this->vec_.IsEqual(other, lin_tol, ang_tol);
}

bool
Vector::is_normal(const Vector & other, double ang_tol) const
{
    return this->vec_.IsNormal(other, ang_tol);
}

bool
Vector::is_opposite(const Vector & other, double ang_tol) const
{
    return this->vec_.IsOpposite(other, ang_tol);
}

bool
Vector::is_parallel(const Vector & other, double ang_tol) const
{
    return this->vec_.IsParallel(other, ang_tol);
}

double
Vector::magnitude() const
{
    return this->vec_.Magnitude();
}

void
Vector::mirror(const Vector & v)
{
    this->vec_.Mirror(v);
}

void
Vector::mirror(const Axis1 & ax1)
{
    this->vec_.Mirror(ax1);
}

void
Vector::mirror(const Axis2 & ax2)
{
    this->vec_.Mirror(ax2);
}

Vector
Vector::mirrored(const Vector & v) const
{
    return Vector(this->vec_.Mirrored(v));
}

Vector
Vector::mirrored(const Axis1 & ax1) const
{
    return Vector(this->vec_.Mirrored(ax1));
}

Vector
Vector::mirrored(const Axis2 & ax2) const
{
    return Vector(this->vec_.Mirrored(ax2));
}

void
Vector::rotate(const Axis1 & ax1, const double angle)
{
    this->vec_.Rotate(ax1, angle);
}

Vector
Vector::rotated(const Axis1 & ax1, const double angle) const
{
    return Vector(this->vec_.Rotated(ax1, angle));
}

void
Vector::scale(double s)
{
    this->vec_.Scale(s);
}

Vector
Vector::scaled(double s) const
{
    return Vector(this->vec_.Scaled(s));
}

void
Vector::normalize()
{
    this->vec_.Normalize();
}

Vector
Vector::normalized() const
{
    return Vector(this->vec_.Normalized());
}

Vector::operator gp_Vec() const
{
    return this->vec_;
}

Vector
operator*(double alpha, const Vector & vec)
{
    return Vector(alpha * vec.x(), alpha * vec.y(), alpha * vec.z());
}

Vector
operator*(double alpha, const Direction & dir)
{
    return Vector(alpha * dir.x(), alpha * dir.y(), alpha * dir.z());
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

Vector
Vector::operator*(double scalar) const
{
    return Vector(scalar * x(), scalar * y(), scalar * z());
}

double
dot_product(const Vector & v1, const Vector & v2)
{
    gp_Vec v(v1);
    return v.Dot(v2);
}

Vector
cross_product(const Vector & v1, const Vector & v2)
{
    gp_Vec v(v1);
    return Vector(v.Crossed(v2));
}

} // namespace formo
