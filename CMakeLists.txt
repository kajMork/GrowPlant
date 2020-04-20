cmake_minimum_required(VERSION 3.17)
project(greenhouse_control VERSION 0.1.0)

include_directories(include)
add_executable(tomato_example   src/tomato_example.cpp 
                                src/tomato_plant.cpp 
                                src/cucumber_plant.cpp)


