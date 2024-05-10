cmake_minimum_required(VERSION 3.28)
project(Checheci_Car_Leasing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Checheci_Car_Leasing
        main.cpp
        Car.h
        Car.cpp
        RentingCar.cpp
        RentingCar.h
        LeasingCar.cpp
        LeasingCar.h
        CarFactory.cpp
        CarFactory.h
)
