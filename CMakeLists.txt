cmake_minimum_required(VERSION 3.17)

project(simulator VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/SFML)

set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/lib/imgui)
add_subdirectory(lib/imgui-sfml)

include_directories(include
                    lib/SFML/include
                    lib/imgui
                    lib/imgui-sfml)

add_executable(simulator src/tomato_plant.cpp
                         src/tomato_example.cpp)
target_link_libraries(simulator sfml-graphics sfml-system ImGui-SFML::ImGui-SFML)