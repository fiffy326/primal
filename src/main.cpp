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
 * @file main.cpp
 * @brief Defines the program entry point.
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "primal/options.hpp"
#include "primal/session.hpp"

/**
 * Program entry point.
 * @param argc Number of command-line arguments
 * @param argv Command-line arguments
 * @return EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char** argv) {
    using namespace primal;
    try {
        // Parse the command-line arguments.
        Options options(argc, argv);

        // Start the appropriate type of session.
        switch (options.function) {
        case Function::INTERACTIVE:
            session();
            break;
        default:
            session(options);
            break;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
