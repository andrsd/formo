// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/utils.h"

namespace formo {
namespace utils {

std::string
to_lower(const std::string & name)
{
    std::string lower(name);
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

bool
ends_with(const std::string & str, const std::string & end)
{
    return str.size() >= end.size() && str.compare(str.size() - end.size(), end.size(), end) == 0;
}

} // namespace utils
} // namespace formo
