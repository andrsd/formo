// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/direction.h"

namespace formo {

Direction::Direction(double x, double y, double z) : dir(x, y, z) {}

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

Direction::operator gp_Dir() const
{
    return this->dir;
}

} // namespace formo
