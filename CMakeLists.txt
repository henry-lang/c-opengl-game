cmake_minimum_required(VERSION 3.12)
project(Game C)

# Find all source files in src directory recursively
file(GLOB_RECURSE SOURCES "src/*.c")

# Set the compiler
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 11)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O2 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fbracket-depth=1024")

# Create the executable target
add_executable(game ${SOURCES} lib/glad/src/glad.c)

# Include directories for glad and glfw
target_include_directories(game PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/glad/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/include
)

# Link GLFW library
target_link_libraries(game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/src/libglfw3.a)

# Additional libraries and flags based on the platform
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_link_libraries(game PRIVATE "-framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa")
endif()

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(game PRIVATE dl pthread)
endif()

if (WIN32)
    target_link_libraries(game PRIVATE "-mwindows")
endif()

# Set the output name
set_target_properties(game PROPERTIES OUTPUT_NAME "game")

# Custom target for cleaning
add_custom_target(clean-all
    COMMAND ${CMAKE_BUILD_TOOL} clean
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
)
