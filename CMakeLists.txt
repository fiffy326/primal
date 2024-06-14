cmake_minimum_required(VERSION 3.28)
project(primal
        VERSION 0.1.0
        DESCRIPTION "Computes prime numbers using a Sieve of Eratosthenes."
        HOMEPAGE_URL "https://github.com/fiffy326/primal"
        LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if (EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory.\
    Please create a build subdirectory.")
endif ()

# Include CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CompilerFlags)

# Include the src directory
add_subdirectory(src)

# Include the docs directory
find_package(Doxygen)
if (Doxygen_FOUND)
    add_subdirectory(docs)
else ()
    message(STATUS "Doxygen not found, not building docs")
endif ()

# Configure version.hpp
configure_file(
        ${PROJECT_SOURCE_DIR}/cmake/version.hpp.in
        ${CMAKE_CURRENT_BINARY_DIR}/version.hpp @ONLY)

# Configure the manpage
configure_file(
        ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}.1.in
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.1 @ONLY)

# Install rules
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.1
        DESTINATION share/man/man1)

# Uninstall target
add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/${PROJECT_NAME}
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/share/man/man1/${PROJECT_NAME}.1
        COMMENT "Removing installed files"
)
