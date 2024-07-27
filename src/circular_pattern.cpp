// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/circular_pattern.h"
#include "formo/vector.h"
#include "formo/axis1.h"

namespace formo {

CircularPattern::CircularPattern(const Axis2 & center, double radius, int divisions) :
    Pattern(),
    center(center),
    radius(radius),
    divs(divisions)
{
    std::vector<Point> points;
    auto ctr = center.location();
    auto x_vec = radius * Vector(center.x_direction());
    Axis1 ctr_ax1(ctr, center.direction());
    double dangle = 2. * M_PI / divs;
    for (int i = 0; i < divs; i++) {
        double angle = i * dangle;
        auto v = x_vec.rotated(ctr_ax1, angle);
        auto pt = ctr + v;
        points.emplace_back(pt);
    }
    set_points(points);
}

} // namespace formo
