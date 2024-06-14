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
#include "primal/utils/string/format_specifier.hpp"

namespace primal::command {

/**
 * Print every prime up to a given ceiling.
 * @tparam T Unsigned integer type
 * @param ceiling Largest number to check
 */
template <typename T>
requires std::is_unsigned_v<T>
void list(T ceiling) {
    // Compute the primes up to the ceiling.
    std::vector<T> primes;
    utils::math::sieve(ceiling, primes);

    // Build the printf string for the output.
    std::string format = utils::string::formatSpecifier<T>();
    std::stringstream output_format_stream;
    output_format_stream << "Prime #" << format << " = " << format << "\n";
    std::string output_format = output_format_stream.str();
    const char* output = output_format.c_str();

    // Print the computed primes and their indices.
    // Use printf inside the loop to increase performance.
    for (T i = 0; i < primes.size(); i++) {
        printf(output, (i + 1), primes[i]);
    }
}

} // namespace primal::commands

#endif // PRIMAL_LIST_HPP
