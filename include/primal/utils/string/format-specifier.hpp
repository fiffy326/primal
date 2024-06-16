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
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @author Emma Casey
 * @date 2024-06-14
 * @file format-specifier.hpp
 * @brief Defines a function template that gets the printf format specifier
 * associated with a given type.
 */

#ifndef PRIMAL_FORMAT_SPECIFIER_HPP
#define PRIMAL_FORMAT_SPECIFIER_HPP

#include <cinttypes>
#include <stdexcept>
#include <string>
#include <type_traits>

namespace primal::utils::string {

/**
 * Gets the printf format specifier associated with a given type.
 * @tparam T Printf argument type
 * @return Printf format specifier
 */
template <typename T>
std::string formatSpecifier() {
    if constexpr (std::is_same_v<T, char*>) return "%s";
    if constexpr (std::is_same_v<T, std::string>) return "%s";
    if constexpr (std::is_floating_point_v<T>) return "%f";
    if constexpr (std::is_signed_v<T>) {
        if constexpr (std::is_same_v<T, int8_t>)
            return "%" + std::string(PRIi8);
        if constexpr (std::is_same_v<T, int16_t>)
            return "%" + std::string(PRIi16);
        if constexpr (std::is_same_v<T, int32_t>)
            return "%" + std::string(PRIi32);
        if constexpr (std::is_same_v<T, int64_t>)
            return "%" + std::string(PRIi64);
    }
    if constexpr (std::is_unsigned_v<T>) {
        if constexpr (std::is_same_v<T, uint8_t>)
            return "%" + std::string(PRIu8);
        if constexpr (std::is_same_v<T, uint16_t>)
            return "%" + std::string(PRIu16);
        if constexpr (std::is_same_v<T, uint32_t>)
            return "%" + std::string(PRIu32);
        if constexpr (std::is_same_v<T, uint64_t>)
            return "%" + std::string(PRIu64);
    }
    throw std::runtime_error("Format specifier not implemented for type.");
}

} // namespace primal::utils::string

#endif // PRIMAL_FORMAT_SPECIFIER_HPP
