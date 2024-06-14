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
 * @file session.cpp
 * @brief Defines functions that start different types of session.
 */

#include "primal/session.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>

#include "primal/ascii_art.hpp"
#include "primal/cli.hpp"
#include "primal/command/index.hpp"
#include "primal/command/list.hpp"
#include "primal/command/test.hpp"
#include "primal/utils/prompt.hpp"
#include "primal/utils/string/parse.hpp"
#include "version.hpp"

void primal::session() {
    using primal::Cli;
    using primal::utils::prompt;

    std::cout << asciiArt;
    std::cout << "[1] Print every prime up to a given ceiling.\n"
              << "[2] Print the prime with a particular index.\n"
              << "[3] Print whether a given number is a prime.\n\n";

    switch (prompt<Command>("Option: ")) {
    case Command::LIST:
        command::list(prompt<uint64_t>("Ceiling: "));
        break;
    case Command::INDEX:
        command::index(prompt<uint64_t>("Index: "));
        break;
    case Command::TEST:
        command::test(prompt<uint64_t>("Number: "));
        break;
    default:
        throw std::runtime_error("Invalid option.");
    }
}

void primal::session(Cli& cli) {
    switch (cli.command) {
    case Command::INDEX:
        command::index(cli.indexArg);
        break;
    case Command::LIST:
        command::list(cli.listArg);
        break;
    case Command::TEST:
        command::test(cli.testArg);
        break;
    case Command::HELP:
        std::cout << cli.getHelpText() << "\n";
        break;
    case Command::VERSION:
        std::cout << "Version: " << version << "\n";
        break;
    default:
        throw std::runtime_error("Invalid option.");
    }
}
