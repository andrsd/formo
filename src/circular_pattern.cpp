// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/circular_pattern.h"
#include "formo/vector.h"
#include "formo/axis1.h"

namespace formo {

CircularPattern::CircularPattern(const Axis2 & center,
                                 double radius,
                                 int divisions,
                                 double start_angle) :
    Pattern(),
    center_(center),
    radius_(radius),
    divs_(divisions)
{
    std::vector<Point> points;
    auto ctr = center.location();
    auto x_vec = radius * Vector(center.x_direction());
    x_vec.rotate(center.axis(), start_angle);
    Axis1 ctr_ax1(ctr, center.direction());
    double dangle = 2. * M_PI / divs_;
    for (int i = 0; i < divs_; i++) {
        double angle = i * dangle;
        auto v = x_vec.rotated(ctr_ax1, angle);
        auto pt = ctr + v;
        points.emplace_back(pt);
    }
    set_points(points);
}

} // namespace formo
