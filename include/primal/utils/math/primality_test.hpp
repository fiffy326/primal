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
 * @file primality_test.hpp
 * @brief Defines function templates that perform primality tests on numbers.
 */

#include <concepts>
#include <optional>
#include <type_traits>
#include <vector>

#include "primal/utils/math/primality.hpp"
#include "primal/utils/math/sieve.hpp"

#ifndef PRIMAL_PRIMALITY_TEST_HPP
#define PRIMAL_PRIMALITY_TEST_HPP

namespace primal::utils::math {

/**
 * Performs preliminary checks on a number to quickly determine the primality
 * of easy-to-categorize numbers.
 * @details Test may be inconclusive and is intended to be used in conjunction
 * with more rigorous tests.
 * @tparam T Unsigned integer type
 * @param n Number to check
 * @return Primality enum of test outcome if conclusive, std::nullopt otherwise
 */
template <typename T>
std::optional<Primality> preliminaryCheck(T n) {
    if ((n == 0) || (n == 1)) return Primality::NEITHER;
    if ((n == 2) || (n == 3)) return Primality::PRIME;
    if (!(n % 2) || !(n % 3)) return Primality::COMPOSITE;
    return std::nullopt;
}

/**
 * Performs a primality test on a number using trial division.
 * @tparam T Unsigned integer type
 * @param n Number to test
 * @return Primality enum of test outcome
 */
template <typename T>
requires std::is_unsigned_v<T>
Primality divisionTest(T n) {
    // Perform a preliminary check to filter out easy-to-categorize numbers.
    if (auto result = preliminaryCheck(n)) return *result;

    // Test the surviving numbers using trial division.
    for (T i = 5; i * i < n; i += 6) {
        if (!(n % i) || !(n % (i + 2))) return Primality::COMPOSITE;
    }

    // Any number that survives the trial division test must be prime.
    return Primality::PRIME;
}

/**
 * Performs a primality test on a number using a Sieve of Eratosthenes.
 * @tparam T Unsigned integer type
 * @param n Number to test
 * @return Primality enum of test outcome
 */
template <typename T>
requires std::is_unsigned_v<T>
Primality sieveTest(T n) {
    // Perform a preliminary check to filter out easy-to-categorize numbers.
    if (auto result = preliminaryCheck(n)) return *result;

    // Test the surviving numbers using a Sieve of Eratosthenes.
    std::vector<T> primes;
    sieve(n, primes);

    // If the number is prime, it will be the last element in the vector.
    if (!primes.empty() && primes.back() == n) return Primality::PRIME;

    // If the sieve did not produce the number, it is composite.
    return Primality::COMPOSITE;
}

/**
 * Checks whether a number is prime or not using a Sieve of Eratosthenes.
 * @tparam T Unsigned integer type
 * @param n Number to check
 * @return True if prime, false otherwise
 */
template <typename T>
requires std::is_unsigned_v<T>
bool isPrime(T n) {
    return sieveTest(n) == Primality::PRIME;
}

} // namespace primal::utils::math

#endif // PRIMAL_PRIMALITY_TEST_HPP
