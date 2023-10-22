cmake_minimum_required(VERSION 3.26)
project(Coursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(Coursework main.cpp
        model/Flight.cpp
        model/Flight.h
        constants/constants.h
        engine/flight/flight.cpp
        engine/flight/flight.h
        model/utils/flight_utils.cpp
)
