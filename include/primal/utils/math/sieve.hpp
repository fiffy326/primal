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

#ifndef PRIMAL_SIEVE_HPP
#define PRIMAL_SIEVE_HPP

#include <cmath>
#include <concepts>
#include <type_traits>
#include <vector>

/**
 * @author Emma Casey
 * @date 2024-06-14
 * @file sieve.hpp
 * @brief Defines a function template that finds all prime numbers below a given
 * ceiling using a Sieve of Eratosthenes.
 */

namespace primal::utils::math {

/**
 * Find all prime numbers below a given ceiling using a Sieve of Eratosthenes.
 * @tparam T Unsigned integer type
 * @param ceiling Largest number to check
 * @param primes Vector of primes found
 */
template <typename T>
requires std::is_unsigned_v<T>
void sieve(T ceiling, std::vector<T>& primes) {
    // Offset the ceiling by 1 to compensate for zero-based indexing.
    ceiling++;

    // Return early unless the ceiling is above the first prime number (2).
    if (ceiling <= 2) return;

    // Prepare a vector to mark ruled out numbers.
    std::vector<bool> isPrime(ceiling, true);

    // Rule out 0 and 1 (they are neither prime nor composite).
    isPrime[0] = isPrime[1] = false;

    // Rule out all even numbers (skip 2 because it is an exception).
    for (T i = 4; i < ceiling; i += 2) {
        isPrime[i] = false;
    }

    // Rule out multiples of primes.
    // Only check odds because evens have already been ruled out.
    for (T i = 3; i * i < ceiling; i += 2) {
        // Skip non-prime numbers.
        if (!isPrime[i]) continue;

        // Rule out multiples of the current number.
        for (T j = i * i; j < ceiling; j += i * 2) {
            isPrime[j] = false;
        }
    }

    // Fill the primes vector with the remaining numbers.
    primes.push_back(2);
    for (T i = 3; i < isPrime.size(); i += 2) {
        if (isPrime[i]) primes.push_back(i);
    }
}

} // namespace primal::utils::math

#endif // PRIMAL_SIEVE_HPP
