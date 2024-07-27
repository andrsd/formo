// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/linear_pattern.h"
#include "formo/vector.h"

namespace formo {

LinearPattern::LinearPattern(const Axis2 & ax2, int nx, double dx) :
    Pattern(),
    ax2(ax2),
    nx(nx),
    dx(dx),
    ny(0),
    dy(0)
{
    std::vector<Point> points;
    auto origin = ax2.location();
    auto x_vec = Vector(ax2.x_direction());
    for (int i = 0; i < nx; i++) {
        auto x_ofst = i * dx * x_vec;
        auto pt = origin + x_ofst;
        points.emplace_back(pt);
    }
    set_points(points);
}

LinearPattern::LinearPattern(const Axis2 & ax2, int nx, int ny, double dx, double dy) :
    Pattern(),
    ax2(ax2),
    nx(nx),
    dx(dx),
    ny(ny),
    dy(dy)
{
    std::vector<Point> points;
    auto origin = ax2.location();
    auto x_vec = Vector(ax2.x_direction());
    auto y_vec = Vector(ax2.y_direction());
    for (int j = 0; j < ny; j++) {
        auto y_ofst = j * dy * y_vec;
        for (int i = 0; i < nx; i++) {
            auto x_ofst = i * dx * x_vec;
            auto pt = origin + x_ofst + y_ofst;
            points.emplace_back(pt);
        }
    }
    set_points(points);
}

} // namespace formo
