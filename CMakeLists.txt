cmake_minimum_required(VERSION 3.28)
project(Checheci_Car_Leasing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Checheci_Car_Leasing
        main.cpp
        Car.cpp
        RentingCar.cpp
        LeasingCar.cpp
        LeasingCar.h
        CarFactory.cpp
        CarFactory.h
        Display.cpp
        Display.h
        LoginHandler.cpp
        LoginHandler.h
        FileHandler.cpp
        FileHandler.h
        RentingCar.h
        Car.h
)
