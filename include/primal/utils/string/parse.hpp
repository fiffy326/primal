/*
 * Copyright (c) 2024 Emma Casey
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @author Emma Casey
 * @date 2024-06-14
 * @file parse.hpp
 * @brief Defines function templates that parse strings to other types.
 */

#include <cerrno>
#include <concepts>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <string>
#include <type_traits>

#ifndef PRIMAL_PARSE_HPP
#define PRIMAL_PARSE_HPP

namespace primal::utils::string {

/**
 * Parses a numeric string to the requested numeric type.
 * @tparam T Numeric return type
 * @param text Numeric string
 * @return Numeric value
 */
template <typename T>
requires std::is_arithmetic_v<T>
T parse(const std::string& text) {
    errno = 0; // Reset the errno before conversion.
    char* end; // Next char in the string after numeric value.

    // Convert the numeric string to the requested numeric type.
    T value;
    if constexpr (std::is_floating_point_v<T>) {
        value = std::strtold(text.c_str(), &end);
    } else if constexpr (std::is_signed_v<T>) {
        value = std::strtoll(text.c_str(), &end, 10);
    } else if constexpr (std::is_unsigned_v<T>) {
        value = std::strtoull(text.c_str(), &end, 10);
    }

    // Range of valid values for the requested numeric type.
    T type_min = std::numeric_limits<T>::min();
    T type_max = std::numeric_limits<T>::max();

    // Check if the input was valid and parsed successfully.
    if (text.empty() || *end != '\0') {
        throw std::runtime_error("String was not a valid numeric value.");
    } else if (errno == ERANGE || value < type_min || value > type_max) {
        throw std::runtime_error("Numeric value of string was out of range "
                                 "for the requested numeric type.");
    }

    // Return the parsed numeric value.
    return static_cast<T>(value);
}

/**
 * Parses a numeric string to the requested enum type.
 * @details Numeric values not contained in the enum will still be parsed. It is
 * the caller's responsibility to handle invalid inputs.
 * @tparam T Enum return type
 * @param text Numeric string
 * @return Enum value
 */
template <typename T>
requires std::is_enum_v<T>
T parse(const std::string& text) {
    return static_cast<T>(parse<std::underlying_type_t<T>>(text));
}

} // namespace primal::utils::string

#endif // PRIMAL_PARSE_HPP
