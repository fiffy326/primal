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
 * @file primality-test.hpp
 * @brief Defines function templates that perform primality tests on numbers.
 */

#ifndef PRIMAL_PRIMALITY_TEST_HPP
#define PRIMAL_PRIMALITY_TEST_HPP

#include <concepts>
#include <optional>
#include <type_traits>
#include <vector>

#include "primal/utils/math/sieve.hpp"

namespace primal::utils::math {

/**
 * Represents the possible outcomes of a primality test.
 */
enum class Primality {
    /**
     * The number is neither prime nor composite.
     */
    NEITHER = 0,

    /**
     * The number is composite.
     */
    COMPOSITE = 1,

    /**
     * The number is prime.
     */
    PRIME = 2
};

/**
 * Performs preliminary checks on a number to quickly determine the primality of
 * easy-to-categorize numbers.
 * @details Test may be inconclusive and is intended to be used in conjunction
 * with more rigorous tests.
 * @tparam T Unsigned integer type
 * @param number Number to check
 * @return Primality enum of test outcome if conclusive, std::nullopt otherwise
 */
template <typename T>
std::optional<Primality> preliminaryCheck(T number) {
    if ((number == 0) || (number == 1)) return Primality::NEITHER;
    if ((number == 2) || (number == 3)) return Primality::PRIME;
    if (!(number % 2) || !(number % 3)) return Primality::COMPOSITE;
    return std::nullopt;
}

/**
 * Performs a primality test on a number using trial division.
 * @tparam T Unsigned integer type
 * @param number Number to test
 * @return Primality enum of test outcome
 */
template <typename T>
requires std::is_unsigned_v<T>
Primality divisionTest(T number) {
    // Filter out easy-to-categorize numbers.
    if (auto result = preliminaryCheck(number)) return *result;

    // Test remaining numbers using trial division.
    for (T i = 5; i * i < number; i += 6) {
        if (!(number % i) || !(number % (i + 2))) return Primality::COMPOSITE;
    }

    // The number must be prime if it survived the trial division test.
    return Primality::PRIME;
}

/**
 * Performs a primality test on a number using a Sieve of Eratosthenes.
 * @tparam T Unsigned integer type
 * @param number Number to test
 * @return Primality enum of test outcome
 */
template <typename T>
requires std::is_unsigned_v<T>
Primality sieveTest(T number) {
    // Filter out easy-to-categorize numbers.
    if (auto result = preliminaryCheck(number)) return *result;

    // Test remaining numbers using a Sieve of Eratosthenes.
    std::vector<T> primes;

    // If the final element in the vector is the number, then it is prime.
    if (!primes.empty() && primes.back() == number) return Primality::PRIME;

    // The number must be composite if the Sieve didn't generate it.
    return Primality::COMPOSITE;
}

/**
 * Checks whether a number is prime or not using a Sieve of Eratosthenes.
 * @tparam T Unsigned integer type
 * @param number Number to check
 * @return True if prime, false otherwise
 */
template <typename T>
requires std::is_unsigned_v<T>
bool isPrime(T number) {
    return sieveTest(number) == Primality::PRIME;
}

} // namespace primal::utils::math

#endif // PRIMAL_PRIMALITY_TEST_HPP
