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
 * @file test.hpp
 * @brief Defines a function template that prints whether a given number is a
 * prime.
 */

#include <concepts>
#include <iostream>
#include <type_traits>
#include <vector>

#include "primal/utils/math/primality.hpp"
#include "primal/utils/math/primality_test.hpp"

#ifndef PRIMAL_TEST_HPP
#define PRIMAL_TEST_HPP

namespace primal::command {

/**
 * Prints whether a given number is a prime.
 * @tparam T Unsigned integer type
 * @param n Number to test
 */
template <typename T>
requires std::is_unsigned_v<T>
void test(T n) {
    using namespace utils::math;

    switch (sieveTest(n)) {
    case Primality::PRIME:
        std::cout << n << " is prime.\n";
        break;
    case Primality::COMPOSITE:
        std::cout << n << " is composite.\n";
        break;
    case Primality::NEITHER:
        std::cout << n << " is neither prime nor composite.\n";
        break;
    }
}

} // namespace primal::commands

#endif // PRIMAL_TEST_HPP
