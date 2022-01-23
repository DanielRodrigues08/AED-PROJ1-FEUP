cmake_minimum_required(VERSION 3.10)
project(AED_PROJ1)

set(CMAKE_CXX_STANDARD 11)

add_executable(AED_PROJ1 main.cpp
        src/Carriage.cpp
        src/CheckIn.cpp
        src/Date.cpp
        src/Flight.cpp
        src/Person.cpp
        src/Plane.cpp
        src/Services.cpp
        src/Station.cpp
        src/Suitcase.cpp
        src/Ticket.cpp
        src/Time.cpp
        src/Transport.cpp
        src/TransportCar.cpp
        src/Treadmill.cpp
        src/CheckedSuitcase.cpp src/CheckedSuitcase.h src/Location.cpp src/Location.h src/Menu.cpp src/Input.cpp src/Save.cpp src/Save.h src/Populate.cpp src/Populate.h)


