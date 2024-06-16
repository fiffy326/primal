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
 * @file options.hpp
 * @brief Declares an Options class that parses command-line arguments.
 */

#ifndef PRIMAL_OPTIONS_HPP
#define PRIMAL_OPTIONS_HPP

#include <cstdint>
#include <string>

#include "cxxopts.hpp"

namespace primal {

/**
 * Represents the different functions that the program may perform.
 */
enum class Function {
    /**
     * Start an interactive session.
     */
    INTERACTIVE = 0,

    /**
     * Print the prime with a particular index.
     */
    INDEX = 1,

    /**
     * Print every prime up to a given ceiling.
     */
    LIST = 2,

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

/**
 * Parses command-line arguments.
 */
class Options {
public:
    /**
     * Parse command-line arguments.
     * @param argc Number of command-line arguments
     * @param argv Command-line arguments
     */
    Options(int argc, char** argv);

    /**
     * Get the program help text.
     * @return Program help text
     */
    std::string getHelpText() const;

    /**
     * Function associated with the provided command-line options.
     */
    Function function;

    /**
     * Argument value for the '--index' option.
     */
    uint64_t indexArg;

    /**
     * Argument value for the '--list' option.
     */
    uint64_t listArg;

    /**
     * Argument value for the '--test' option.
     */
    uint64_t testArg;

private:
    /**
     * Add the command-line options to the underlying cxxopts instance.
     */
    void addOptions();

    /**
     * Parse the command-line options from the cxxopts instance and assign their
     * values to their respective attributes.
     * @param argc Number of command-line arguments
     * @param argv Command-line arguments
     */
    void parseOptions(int argc, char** argv);

    /**
     * Underlying cxxopts instance.
     */
    cxxopts::Options opts;

    /**
     * Program description for the help text.
     */
    static constexpr char description[] =
        "Computes prime numbers using a Sieve of Eratosthenes.";
};

} // namespace primal

#endif // PRIMAL_OPTIONS_HPP
