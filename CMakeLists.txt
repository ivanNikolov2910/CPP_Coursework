cmake_minimum_required(VERSION 3.26)
project(Coursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(Coursework main.cpp
        model/plane/Plane.cpp
        model/plane/PassengerPlane.cpp
        model/plane/CargoPlane.cpp
        model/corp-data/Staff.cpp
        model/corp-data/Runway.cpp
        model/corp-data/Flight.cpp
        model/utils/source/StaffUtils.cpp
        model/utils/source/RunwayUtils.cpp
        model/utils/source/PlaneUtils.cpp
        model/utils/source/FlightUtils.cpp
        engine/source/StaffEngine.cpp
        engine/source/RunwayEngine.cpp
        engine/source/PlaneEngine.cpp
        engine/source/FlightEngine.cpp
        engine/flights-options/FlightsOptions.cpp)
