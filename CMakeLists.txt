cmake_minimum_required(VERSION 3.16)
project(2048SFMLProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0)
FetchContent_MakeAvailable(SFML)
include_directories(${SFML_SOURCE_DIR}/include)

# Fetch Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
get_target_property(GTEST_INCLUDE_DIRS gtest INTERFACE_INCLUDE_DIRECTORIES)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/include)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Libarries.
add_library(game src/game.cpp)
target_link_libraries(game PRIVATE sfml-graphics board)

add_library(board src/board.cpp)
target_link_libraries(board PRIVATE board_management)

add_library(board_management src/board_management.cpp)

# Main binary.
add_executable(2048 src/main.cpp)
target_link_libraries(2048 PRIVATE game)
target_compile_features(2048 PRIVATE cxx_std_17)

# Enable testing
enable_testing()

# Unit test for board library
add_executable(board_test test/board_test.cpp)
target_link_libraries(board_test PRIVATE board gtest_main)
target_compile_features(board_test PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests(board_test)

# Unit test for board_management library
add_executable(board_management_test test/board_management_test.cpp)
target_link_libraries(board_management_test PRIVATE board_management gtest_main)
target_compile_features(board_management_test PRIVATE cxx_std_17)

gtest_discover_tests(board_management_test)

install(TARGETS 2048)
