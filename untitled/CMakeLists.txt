cmake_minimum_required(VERSION 3.17)
project(Elevator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Elevator main.cpp Dispatch.cpp Dispatch.h Elevator.cpp Elevator.h Person.cpp Person.h)