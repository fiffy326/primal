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
 * @file cli.hpp
 * @brief Declares a Cli class that parses command-line arguments.
 */

#ifndef PRIMAL_CLI_HPP
#define PRIMAL_CLI_HPP

#include <cstdint>
#include <string>

#include "cxxopts.hpp"
#include "primal/command.hpp"

namespace primal {

/**
 * Parses command-line arguments.
 */
class Cli {
public:
    /**
     * Parse the command-line arguments.
     * @param argc Number of command-line arguments
     * @param argv Command-line arguments
     */
    Cli(int argc, char** argv);

    /**
     * Get the program help text.
     * @return Program help text
     */
    std::string getHelpText() const;

    /**
     * Command associated with the provided options.
     */
    Command command;

    /**
     * Argument value for the '--list' command.
     */
    uint64_t indexArg;

    /**
     * Argument value for the '--index' command.
     */
    uint64_t listArg;

    /**
     * Argument value for the '--test' command.
     */
    uint64_t testArg;

private:
    /**
     * Add the command-line options to the cxxopts instance.
     */
    void addOptions();

    /**
     * Parse the command-line options and assign their values to their
     * respective attributes.
     * @param argc Number of command-line arguments
     * @param argv Command-line arguments
     */
    void parseOptions(int argc, char** argv);

    /**
     * Underlying cxxopts instance.
     */
    cxxopts::Options opts;

    /**
     * Flag for the '--help' command.
     */
    bool helpFlag;

    /**
     * Flag for the '--version' command.
     */
    bool versionFlag;

    /**
     * Program description for the help message.
     */
    static constexpr char description[] =
        "Computes prime numbers using a Sieve of Eratosthenes.";
};

} // namespace primal

#endif // PRIMAL_CLI_HPP
