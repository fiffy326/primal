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
 * @file session.cpp
 * @brief Defines functions that start different types of session.
 */

#include "primal/session.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>

#include "primal/ascii-art.hpp"
#include "primal/functions/index.hpp"
#include "primal/functions/list.hpp"
#include "primal/functions/test.hpp"
#include "primal/options.hpp"
#include "primal/utils/prompt.hpp"
#include "primal/version.hpp"

void primal::session() {
    using utils::prompt;

    std::cout << asciiArt;
    std::cout << "[1] Print the prime with a particular index.\n"
              << "[2] Print every prime up to a given ceiling.\n"
              << "[3] Print whether a given number is a prime.\n\n";

    switch (prompt<Function>("Option: ")) {
    case Function::INDEX:
        functions::index(prompt<uint64_t>("Index: "));
        break;
    case Function::LIST:
        functions::list(prompt<uint64_t>("Ceiling: "));
        break;
    case Function::TEST:
        functions::test(prompt<uint64_t>("Number: "));
        break;
    default:
        throw std::runtime_error("Invalid option.");
    }
}

void primal::session(const Options& options) {
    switch (options.function) {
    case Function::INDEX:
        functions::index(options.indexArg);
        break;
    case Function::LIST:
        functions::list(options.listArg);
        break;
    case Function::TEST:
        functions::test(options.testArg);
        break;
    case Function::VERSION:
        std::cout << "Version: " << version << "\n";
        break;
    case Function::HELP:
        std::cout << options.getHelpText() << "\n";
        break;
    default:
        throw std::runtime_error("Invalid option.");
    }
}
