cmake_minimum_required(VERSION 3.16)
project(2048SFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0)
FetchContent_MakeAvailable(SFML)

add_executable(2048 src/main.cpp)
target_link_libraries(2048 PRIVATE sfml-graphics)
target_compile_features(2048 PRIVATE cxx_std_17)

install(TARGETS 2048)
