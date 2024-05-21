//
// Created by giurg on 5/15/2024.
//

#ifndef CHECHECI_CAR_LEASING_MAIN_H
#define CHECHECI_CAR_LEASING_MAIN_H

#include "Car.h"
#include "RentingCar.h"
#include "LeasingCar.h"

class MainClass
{
public:
    static void MenuOptions();
    static std::string GetUsername();

    static void CallUpdRentedCars();
    static void CallUpdLeasedCars();

    static void CallUpdRentingCars();
    static void CallUpdLeasingCars();

    static void CallUpdAvailableCars();
};

#endif //CHECHECI_CAR_LEASING_MAIN_H