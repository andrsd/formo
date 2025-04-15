// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/direction.h"
#include "formo/vector.h"
#include "formo/axis1.h"
#include "formo/axis2.h"

namespace formo {

Direction::Direction(double x, double y, double z) : dir_(x, y, z) {}

Direction::Direction(const Vector & vec) : dir_(vec) {}

Direction::Direction(const gp_Dir & dir) : dir_(dir) {}

double
Direction::x() const
{
    return this->dir_.X();
}

double
Direction::y() const
{
    return this->dir_.Y();
}

double
Direction::z() const
{
    return this->dir_.Z();
}

bool
Direction::is_equal(const Direction & other, double ang_tol) const
{
    return this->dir_.IsEqual(other, ang_tol);
}

bool
Direction::is_normal(const Direction & other, double ang_tol) const
{
    return this->dir_.IsNormal(other, ang_tol);
}

bool
Direction::is_opposite(const Direction & other, double ang_tol) const
{
    return this->dir_.IsOpposite(other, ang_tol);
}

bool
Direction::is_parallel(const Direction & other, double ang_tol) const
{
    return this->dir_.IsParallel(other, ang_tol);
}

void
Direction::mirror(const Direction & v)
{
    this->dir_.Mirror(v);
}

void
Direction::mirror(const Axis1 & ax1)
{
    this->dir_.Mirror(ax1);
}

void
Direction::mirror(const Axis2 & ax2)
{
    this->dir_.Mirror(ax2);
}

Direction
Direction::mirrored(const Direction & v) const
{
    return Direction(this->dir_.Mirrored(v));
}

Direction
Direction::mirrored(const Axis1 & ax1) const
{
    return Direction(this->dir_.Mirrored(ax1));
}

Direction
Direction::mirrored(const Axis2 & ax2) const
{
    return Direction(this->dir_.Mirrored(ax2));
}

void
Direction::rotate(const Axis1 & ax1, const double angle)
{
    this->dir_.Rotate(ax1, angle);
}

Direction
Direction::rotated(const Axis1 & ax1, const double angle) const
{
    return Direction(this->dir_.Rotated(ax1, angle));
}

void
Direction::reverse()
{
    this->dir_.Reverse();
}

Direction
Direction::reversed() const
{
    return Direction(this->dir_.Reversed());
}

Direction::operator gp_Dir() const
{
    return this->dir_;
}

Direction
Direction::operator-() const
{
    return Direction(this->dir_.Reversed());
}

double
dot_product(const Direction & v1, const Direction & v2)
{
    gp_Dir v(v1);
    return v.Dot(v2);
}

Direction
cross_product(const Direction & v1, const Direction & v2)
{
    gp_Dir v(v1);
    return Direction(v.Crossed(v2));
}

} // namespace formo
