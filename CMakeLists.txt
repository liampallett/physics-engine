cmake_minimum_required(VERSION 4.1)
project(physics-engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(physics-engine main.cpp
        include/Vector2.hpp
        include/Body.hpp
        include/PhysicsHandler.hpp
)
