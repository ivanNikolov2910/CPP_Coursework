cmake_minimum_required(VERSION 3.26)
project(Coursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(Coursework main.cpp
        model/Flight.cpp
        model/Flight.h
        constants/constants.h
        engine/flight/FlightEngine.cpp
        engine/flight/FlightEngine.h
        model/utils/FlightUtils.cpp
        model/Plane.cpp
        model/Plane.h
        model/submodels/Expenses.cpp
        model/submodels/Expenses.h
        model/CargoPlane.cpp
        model/CargoPlane.h
        model/AirlinePlane.cpp
        model/AirlinePlane.h
        model/Runway.cpp
        model/Runway.h
        model/submodels/Staff.cpp
        model/submodels/Staff.h
)
