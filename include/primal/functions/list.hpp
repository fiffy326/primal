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
 * @file list.hpp
 * @brief Defines a function template that prints every prime up to a given
 * ceiling.
 */

#ifndef PRIMAL_LIST_HPP
#define PRIMAL_LIST_HPP

#include <concepts>
#include <cstdio>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "primal/utils/math/sieve.hpp"
#include "primal/utils/string/format-specifier.hpp"

namespace primal::functions {

/**
 * Print every prime up to a given ceiling.
 * @tparam T Unsigned integer type
 * @param ceiling Largest number to check
 */
template <typename T>
requires std::is_unsigned_v<T>
void list(T ceiling) {
    using utils::math::sieve;
    using utils::string::formatSpecifier;

    // Calculate the primes up to the ceiling.
    std::vector<T> primes;
    sieve(ceiling, primes);

    // Build the printf string for the output.
    std::string format = formatSpecifier<T>();
    std::stringstream outputFormatStream;
    outputFormatStream << "Prime #" << format << " = " << format << "\n";
    std::string outputFormat = outputFormatStream.str();
    const char* output = outputFormat.c_str();

    // Print the calculated primes and their indices.
    // Use printf inside the loop to increase performance.
    for (T i = 0; i < primes.size(); i++) {
        printf(output, (i + 1), primes[i]);
    }
}

} // namespace primal::functions

#endif // PRIMAL_LIST_HPP
