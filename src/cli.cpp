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
 * @file cli.cpp
 * @brief Defines a Cli class that parses command-line arguments.
 */

#include "primal/cli.hpp"

#include <cstdint>
#include <stdexcept>
#include <string>

#include "cxxopts.hpp"
#include "primal/command.hpp"

primal::Cli::Cli(int argc, char** argv)
    : opts(argv[0], description), command(Command::INTERACTIVE), indexArg(0),
      listArg(0), testArg(0), helpFlag(false), versionFlag(false) {
    addOptions();
    parseOptions(argc, argv);
}

std::string primal::Cli::getHelpText() const { return opts.help(); }

void primal::Cli::addOptions() {
    using cxxopts::value;

    opts.add_options()("l,list", "Print every prime up to a given ceiling.",
                       value<uint64_t>()->default_value("0"));

    opts.add_options()("i,index", "Print the prime with a particular index.",
                       value<uint64_t>()->default_value("0"));

    opts.add_options()("t,test", "Print whether a given number is a prime.",
                       value<uint64_t>()->default_value("0"));

    opts.add_options()("v,version", "Show version information.",
                       value<bool>()->default_value("false"));

    opts.add_options()("h,help", "Show usage information.",
                       value<bool>()->default_value("false"));
}

void primal::Cli::parseOptions(int argc, char** argv) {
    // Assign the argument values to their respective attributes.
    auto parsedOpts = opts.parse(argc, argv);
    indexArg = parsedOpts["index"].as<uint64_t>();
    listArg = parsedOpts["list"].as<uint64_t>();
    testArg = parsedOpts["test"].as<uint64_t>();
    helpFlag = parsedOpts["help"].as<bool>();
    versionFlag = parsedOpts["version"].as<bool>();

    // Total number of options provided.
    int optCount = (indexArg ? 1 : 0) + (listArg ? 1 : 0) + (testArg ? 1 : 0) +
                   (helpFlag ? 1 : 0) + (versionFlag ? 1 : 0);

    // Only allow 1 option to be entered.
    if (optCount > 1) throw std::runtime_error("Invalid options.");

    // Set the appropriate command for the option provided.
    if (indexArg) command = Command::INDEX;
    if (listArg) command = Command::LIST;
    if (testArg) command = Command::TEST;
    if (helpFlag) command = Command::HELP;
    if (versionFlag) command = Command::VERSION;
}
