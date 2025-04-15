// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/hexagonal_pattern.h"
#include "formo/point.h"
#include "formo/vector.h"
#include "formo/axis1.h"
#include <array>

namespace formo {

const int N_CORNERS = 6;
const int N_SIDES = 6;

HexagonalPattern::HexagonalPattern(const Axis2 & center, double flat_to_flat, int side_segs) :
    Pattern(),
    center_(center),
    flat_to_flat_(flat_to_flat),
    num_side_segs_(side_segs)
{
    auto ctr_pt = center.location();
    double radius = flat_to_flat / std::sqrt(3.);

    auto x_vec = radius * Vector(center.x_direction());
    Axis1 ctr_ax1(ctr_pt, center.direction());

    // find corners
    std::array<Point, N_CORNERS> corners;
    double deg60 = M_PI / 3.;
    for (int i = 0; i < N_CORNERS; i++) {
        double angle = i * deg60;
        auto v = x_vec.rotated(ctr_ax1, angle);
        auto pt = ctr_pt + v;
        corners[i] = pt;
    }

    // build sides
    std::vector<Point> points;
    for (int s = 0; s < N_SIDES; s++) {
        Vector side(corners[s], corners[(s + 1) % N_SIDES]);
        Direction side_dir(side);
        double ds = side.magnitude() / this->num_side_segs_;
        for (int i = 0; i < this->num_side_segs_; i++) {
            auto pt = corners[s] + i * ds * side_dir;
            points.emplace_back(pt);
        }
    }

    set_points(points);
}

} // namespace formo
