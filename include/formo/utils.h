// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include <string>

namespace formo {
namespace utils {

/**
 * Convert supplied string to lower case.
 * @param name The string to convert upper case.
 */
std::string to_lower(const std::string & name);

/**
 * Check if string `str` ends with specified text
 *
 * @param str String to check
 * @param end The expected text
 */
bool ends_with(const std::string & str, const std::string & end);

} // namespace utils
} // namespace formo
