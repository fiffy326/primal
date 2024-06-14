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
 * @file session.hpp
 * @brief Declares functions that start different types of session.
 */

#ifndef PRIMAL_SESSION_HPP
#define PRIMAL_SESSION_HPP

#include "primal/cli.hpp"

namespace primal {

/**
 * Starts a session using interactive user input.
 */
void session();

/**
 * Starts a session using the command-line options.
 * @param cli Parsed command-line options object
 */
void session(Cli& cli);

} // namespace primal

#endif // PRIMAL_SESSION_HPP
