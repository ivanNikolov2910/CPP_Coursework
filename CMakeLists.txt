cmake_minimum_required(VERSION 3.26)
project(Coursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(Coursework main.cpp
        model/corp-data/Staff.cpp
        model/corp-data/Runway.cpp
        model/plane/Plane.cpp
        model/plane/PassengerPlane.cpp
        model/corp-data/Flight.cpp
        model/plane/CargoPlane.cpp)
