# Specify the source files
set(SOURCES
        main.cpp
        options.cpp
        session.cpp)

# Define the target
add_executable(${PROJECT_NAME} ${SOURCES})

# Set compiler flags for the target
set_target_compiler_flags(${PROJECT_NAME})

# Include directory
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Include the build directory for access to generated headers
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})

# Include external libraries
add_subdirectory(${PROJECT_SOURCE_DIR}/external/cxxopts ${CMAKE_CURRENT_BINARY_DIR}/cxxopts)

# Link the external libraries
target_link_libraries(${PROJECT_NAME} PRIVATE cxxopts)
