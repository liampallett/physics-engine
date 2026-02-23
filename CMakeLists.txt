cmake_minimum_required(VERSION 4.1)
project(newtonian_orbit_mechanics)

set(CMAKE_CXX_STANDARD 20)

add_executable(newtonian_orbit_mechanics main.cpp
        include/Vector2.hpp
)
