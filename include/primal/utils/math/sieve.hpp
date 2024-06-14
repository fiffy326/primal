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
 * @file sieve.hpp
 * @brief Defines a function template that computes the prime numbers up to a
 * given ceiling using a Sieve of Eratosthenes.
 */

#ifndef PRIMAL_SIEVE_HPP
#define PRIMAL_SIEVE_HPP

#include <cmath>
#include <concepts>
#include <type_traits>
#include <vector>

namespace primal::utils::math {

/**
 * Computes the prime numbers up to a given ceiling using a Sieve of
 * Eratosthenes.
 * @tparam T Unsigned integer type
 * @param ceiling Largest number to check
 * @param primes Vector of prime numbers found
 */
template <typename T>
requires std::is_unsigned_v<T>
void sieve(T ceiling, std::vector<T>& primes) {
    // Offset the ceiling by 1 to compensate for zero-based indexing.
    ceiling++;

    // Return early unless the ceiling is above the first prime number (2).
    if (ceiling <= 2) return;

    // Prepare a bool vector to mark ruled out numbers.
    std::vector<bool> is_prime(ceiling, true);

    // Mark 0 and 1 as non-prime (they are neither prime nor composite).
    is_prime[0] = is_prime[1] = false;

    // Mark all even numbers as non-prime.
    // Skip the number 2 because it is an exception to the rule.
    for (T i = 4; i < ceiling; i += 2) {
        is_prime[i] = false;
    }

    // Mark multiples of known primes as composite.
    // Only check odd numbers because the evens have already been covered.
    for (T i = 3; i * i < ceiling; i += 2) {
        // Skip non-prime numbers.
        if (!is_prime[i]) continue;

        // Mark multiples of the current number as non-prime.
        for (T j = i * i; j < ceiling; j += i * 2) {
            is_prime[j] = false;
        }
    }

    // Populate the primes vector with the sieved primes.
    primes.push_back(2);
    for (T i = 3; i < is_prime.size(); i += 2) {
        if (is_prime[i]) primes.push_back(i);
    }
}

}

#endif // PRIMAL_SIEVE_HPP
