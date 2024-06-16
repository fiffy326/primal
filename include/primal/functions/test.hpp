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

#ifndef PRIMAL_TEST_HPP
#define PRIMAL_TEST_HPP

#include <concepts>
#include <iostream>
#include <type_traits>
#include <vector>

#include "primal/utils/math/primality-test.hpp"

namespace primal::functions {

/**
 * Prints whether a given number is a prime.
 * @tparam T Unsigned integer type
 * @param number Number to test
 */
template <typename T>
requires std::is_unsigned_v<T>
void test(T number) {
    using utils::math::Primality;
    using utils::math::sieveTest;

    switch (sieveTest(number)) {
    case Primality::PRIME:
        std::cout << number << " is prime.\n";
        break;
    case Primality::COMPOSITE:
        std::cout << number << " is composite.\n";
        break;
    case Primality::NEITHER:
        std::cout << number << " is neither prime nor composite.\n";
        break;
    }
}

} // namespace primal::functions

#endif // PRIMAL_TEST_HPP
