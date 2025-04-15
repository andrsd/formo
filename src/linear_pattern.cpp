// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/linear_pattern.h"
#include "formo/vector.h"

namespace formo {

LinearPattern::LinearPattern(const Axis2 & ax2, int nx, double dx) :
    Pattern(),
    ax2_(ax2),
    nx_(nx),
    dx_(dx),
    ny_(0),
    dy_(0)
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
    ax2_(ax2),
    nx_(nx),
    dx_(dx),
    ny_(ny),
    dy_(dy)
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

double
LinearPattern::nx() const
{
    return this->nx_;
}

double
LinearPattern::ny() const
{
    return this->ny_;
}

double
LinearPattern::dx() const
{
    return this->dx_;
}

double
LinearPattern::dy() const
{
    return this->dy_;
}

} // namespace formo
