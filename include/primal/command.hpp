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
 * @file command.hpp
 * @brief Defines an enum class that represents the different functions that the
 * program may perform.
 */

#ifndef PRIMAL_COMMAND_HPP
#define PRIMAL_COMMAND_HPP

namespace primal {

/**
 * Represents the different functions that the program may perform.
 * @details Numeric values correspond with interactive session menu inputs.
 */
enum class Command {
    /**
     * Start an interactive session.
     */
    INTERACTIVE = 0,

    /**
     * Print every prime up to a given ceiling.
     */
    LIST = 1,

    /**
     * Print the prime with a particular index.
     */
    INDEX = 2,

    /**
     * Print whether a given number is a prime.
     */
    TEST = 3,

    /**
     * Show version information.
     */
    VERSION = 4,

    /**
     * Show usage information.
     */
    HELP = 5
};

} // namespace primal

#endif // PRIMAL_COMMAND_HPP
