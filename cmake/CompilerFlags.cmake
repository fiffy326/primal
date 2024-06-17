function(set_target_compiler_flags TARGET)
    message(STATUS "Detected C++ compiler: ${CMAKE_CXX_COMPILER_ID}")

    if (NOT CMAKE_BUILD_TYPE)
        message(STATUS "CMAKE_BUILD_TYPE is not set, defaulting to Release")
        set(CMAKE_BUILD_TYPE "Release")
    endif ()

    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
            CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(DEBUG_FLAGS -Og -g)
        set(RELEASE_FLAGS -O3 -march=native)
    else ()
        message(WARNING
                "Skipping flags for unknown compiler: ${CMAKE_CXX_COMPILER_ID}")
        return()
    endif ()

    message(STATUS "Setting flags for ${CMAKE_BUILD_TYPE} build of ${TARGET}")
    target_compile_options(${TARGET} PRIVATE
            "$<$<CONFIG:Debug>:${DEBUG_FLAGS}>"
            "$<$<CONFIG:Release>:${RELEASE_FLAGS}>")
endfunction()
