cmake_minimum_required(VERSION 3.26)
project(Coursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(Coursework main.cpp
        model/Staff.cpp
        model/Runway.cpp
        model/Plane.cpp
        model/PassengerPlane.cpp
        model/Flight.cpp
        model/CargoPlane.cpp)
