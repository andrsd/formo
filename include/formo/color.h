// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

namespace formo {

class Color {
public:
    Color();
    Color(int r, int g, int b);

    int red() const;
    double redF() const;
    int green() const;
    double greenF() const;
    int blue() const;
    double blueF() const;

private:
    int r_, g_, b_;
};

} // namespace formo
