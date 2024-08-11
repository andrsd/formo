// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/direction.h"
#include "formo/vector.h"
#include "formo/axis1.h"
#include "formo/axis2.h"

namespace formo {

Direction::Direction(double x, double y, double z) : dir(x, y, z) {}

Direction::Direction(const Vector & vec) : dir(vec) {}

Direction::Direction(const gp_Dir & dir) : dir(dir) {}

double
Direction::x() const
{
    return this->dir.X();
}

double
Direction::y() const
{
    return this->dir.Y();
}

double
Direction::z() const
{
    return this->dir.Z();
}

void
Direction::mirror(const Direction & v)
{
    this->dir.Mirror(v);
}

void
Direction::mirror(const Axis1 & ax1)
{
    this->dir.Mirror(ax1);
}

void
Direction::mirror(const Axis2 & ax2)
{
    this->dir.Mirror(ax2);
}

Direction
Direction::mirrored(const Direction & v) const
{
    return Direction(this->dir.Mirrored(v));
}

Direction
Direction::mirrored(const Axis1 & ax1) const
{
    return Direction(this->dir.Mirrored(ax1));
}

Direction
Direction::mirrored(const Axis2 & ax2) const
{
    return Direction(this->dir.Mirrored(ax2));
}

void
Direction::rotate(const Axis1 & ax1, const double angle)
{
    this->dir.Rotate(ax1, angle);
}

Direction
Direction::rotated(const Axis1 & ax1, const double angle) const
{
    return Direction(this->dir.Rotated(ax1, angle));
}

Direction::operator gp_Dir() const
{
    return this->dir;
}

Direction
Direction::operator-() const
{
    return Direction(this->dir.Reversed());
}

} // namespace formo
