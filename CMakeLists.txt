cmake_minimum_required(VERSION 3.17)
project(greenhouse_control VERSION 0.1.0)

add_subdirectory(libs/SFML)
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/libs/imgui)
add_subdirectory(libs/imgui-sfml)

include_directories(include
                    libs/SFML/include
                    libs/imgui
                    libs/imgui-sfml)
add_executable(tomato_example   src/tomato_example.cpp 
                                src/tomato_plant.cpp 
                                src/cucumber_plant.cpp
                                src/water_tank.cpp
                                src/green_house.cpp)

target_link_libraries(tomato_example sfml-graphics sfml-system ImGui-SFML::ImGui-SFML)


