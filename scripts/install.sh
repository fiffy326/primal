#!/usr/bin/env sh

#
# Copyright (c) 2024 Emma Casey
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program. If not, see <https://www.gnu.org/licenses/>.
#

# Create and enter a build directory
mkdir ../build
cd ../build || exit

# Generate build recipe
cmake ..

# Build the project
cmake --build .

# Install the binary and manpage
sudo cmake --install .

# Return to the scripts directory
cd ../scripts || exit

# Remove the build directory
rm -rf ../build

# Tell the user what has been done
printf "\nThe program and manpage have been installed.\n\n"
printf "Use the command 'primal' to run the program.\n"
printf "Use the command 'man primal' for usage info.\n"
