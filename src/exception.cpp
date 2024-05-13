// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/exception.h"

namespace formo {

const char *
Exception::what() const noexcept
{
    return this->msg.c_str();
}

} // namespace formo
