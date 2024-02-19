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

# Fetch Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(state_management src/state_management.cpp)

add_executable(2048 src/main.cpp)
target_link_libraries(2048 PRIVATE sfml-graphics state_management)
target_compile_features(2048 PRIVATE cxx_std_17)

# Enable testing
enable_testing()

# Unit test for state_management
add_executable(test_state_management test/test_state_management.cpp)
target_link_libraries(test_state_management PRIVATE state_management gtest_main)
target_compile_features(test_state_management PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests(test_state_management)

install(TARGETS 2048)
