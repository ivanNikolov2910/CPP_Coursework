cmake_minimum_required(VERSION 3.26)
project(Coursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(Coursework main.cpp
        model/utils/Validation.cpp
        model/CargoPlane.cpp
        model/CargoPlane.h
        model/PassengerPlane.cpp
        model/PassengerPlane.h
        model/Staff.h
        engine/StaffEngine.cpp
        model/utils/StaffUtils.cpp
        engine/RunwayEngine.cpp
        model/utils/RunwayUtils.cpp
        engine/flights-options/FlightsOptions.cpp
)
