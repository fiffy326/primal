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
 * @file primality.hpp
 * @brief Defines an enum class that represents the possible outcomes of a
 * primality test.
 */

#ifndef PRIMAL_PRIMALITY_HPP
#define PRIMAL_PRIMALITY_HPP

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

}

#endif // PRIMAL_PRIMALITY_HPP
