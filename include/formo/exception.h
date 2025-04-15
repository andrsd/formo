// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#pragma once

#include <exception>
#include <string>
#include <vector>
#include "fmt/format.h"

namespace formo {

/// Exception thrown from our code, so that application code can determine where problems originated
/// from
class Exception : public std::exception {
public:
    template <typename... T>
    Exception(fmt::format_string<T...> format, T... args)
    {
        this->msg_ = fmt::format(format, std::forward<T>(args)...);
    }

    /// Get the exception message
    const char * what() const noexcept override;

private:
    /// Error message
    std::string msg_;
};

} // namespace formo
