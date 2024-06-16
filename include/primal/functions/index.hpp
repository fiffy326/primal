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

#ifndef PRIMAL_INDEX_HPP
#define PRIMAL_INDEX_HPP

/**
 * @author Emma Casey
 * @date 2024-06-14
 * @file index.hpp
 * @brief Defines a function template that prints the prime with a particular
 * index.
 */

#include <cmath>
#include <concepts>
#include <iostream>
#include <type_traits>
#include <vector>

#include "primal/utils/math/sieve.hpp"

namespace primal::functions {

/**
 * Prints the prime with a particular index.
 * @tparam T Unsigned integer type
 * @param number Prime index
 */
template <typename T>
requires std::is_unsigned_v<T>
void index(T number) {
    using std::log, std::max;
    using utils::math::sieve;

    // Prepare a vector to store the primes found.
    std::vector<T> primes;

    // Sieve ceiling used for calculations.
    T ceiling;

    // Prime number theorem estimate of the Nth prime.
    T ceilingEstimate = number * log(number) + number * log(log(number));

    // Minimum sieve ceiling (in case the estimate is below the Nth prime).
    T ceilingMin = 15;

    // Offset the number by -1 to compensate for zero-based indexing.
    number--;

    // Sieve until the Nth prime is found.
    while (true) {
        // (Re)calculate the sieve ceiling.
        ceiling = max(ceilingEstimate, ceilingMin);

        // Calculate the primes up to the ceiling.
        sieve(ceiling, primes);

        // Display the Nth prime if it was found.
        if (number < primes.size()) {
            std::cout << "Prime #" << number << " = " << primes[number] << "\n";
            break;
        }

        // Increase the sieve ceiling by 10% if the Nth prime was not found.
        ceilingMin = static_cast<T>(ceiling * 1.1);

        // Clear the primes vector before sieving again.
        primes.clear();
    }
}

} // namespace primal::functions

#endif // PRIMAL_INDEX_HPP
