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
 * @file prompt.hpp
 * @brief Defines a function template that prompts the user for input and parses
 * it to the requested type.
 */

#ifndef PRIMAL_PROMPT_HPP
#define PRIMAL_PROMPT_HPP

#include <iostream>
#include <string>

#include "primal/utils/string/parse.hpp"

namespace primal::utils {

/**
 * Prompts the user for input and parses it to the requested type.
 * @tparam T Return type
 * @param text Prompt text
 * @return Parsed input value
 */
template <typename T>
T prompt(const std::string& text) {
    std::cout << text;
    std::string input;
    std::cin >> input;
    std::cout << "\n";
    return string::parse<T>(input);
}

} // namespace primal::utils

#endif // PRIMAL_PROMPT_HPP
