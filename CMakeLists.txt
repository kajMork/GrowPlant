cmake_minimum_required(VERSION 3.17)
project(greenhouse_control VERSION 0.1.0)

add_subdirectory(lib/SFML)
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/lib/imgui)
add_subdirectory(lib/imgui-sfml)

include_directories(include
                    lib/SFML/include
                    lib/imgui
                    lib/imgui-sfml)
add_executable(tomato_example   src/tomato_example.cpp
                                src/tomato_plant.cpp 
                                src/cucumber_plant.cpp)

target_link_libraries(tomato_example sfml-graphics sfml-system ImGui-SFML::ImGui-SFML)