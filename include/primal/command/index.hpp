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
 * @file index.hpp
 * @brief Defines a function template that prints the prime with a particular
 * index.
 */

#ifndef PRIMAL_INDEX_HPP
#define PRIMAL_INDEX_HPP

#include <cmath>
#include <concepts>
#include <iostream>
#include <type_traits>
#include <vector>

#include "primal/utils/math/sieve.hpp"

namespace primal::command {

/**
 * Prints the prime with a particular index.
 * @tparam T Unsigned integer type
 * @param n Prime index
 */
template <typename T>
requires std::is_unsigned_v<T>
void index(T n) {
    // Prime number theorem estimate of the Nth prime.
    T ceiling_estimate = n * std::log(n) + n * std::log(std::log(n));

    // Minimum sieve ceiling (in case the estimate is below the Nth prime).
    T ceiling_min = 15;

    // Actual sieve ceiling used for computations.
    T ceiling;

    // Prepare a vector to store the sieved primes.
    std::vector<T> primes;

    // Sieve until the Nth prime is found.
    while (true) {
        // (Re)compute the sieve ceiling.
        ceiling = std::max(ceiling_estimate, ceiling_min);

        // Compute the primes up to the ceiling.
        utils::math::sieve(ceiling, primes);

        // Subtract 1 to compensate for zero-based indexing.
        T i = n - 1;

        // Display the Nth prime if it was found.
        if (i < primes.size()) {
            std::cout << "Prime #" << n << " = " << primes[i] << "\n";
            break;
        }

        // Increase the sieve ceiling by 10% if the Nth prime wasn't found.
        std::cout << "Increasing sieve ceiling by 10%...\n";
        ceiling_min = static_cast<T>(ceiling * 1.1);

        // Clear the primes vector before sieving again.
        primes.clear();
    }
}

} // namespace primal::commands

#endif // PRIMAL_INDEX_HPP
