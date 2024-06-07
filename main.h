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

    static std::vector<Car> GetAvailableCars();
    static std::vector<LeasingCar> GetLeasingCars();
    static std::vector<RentingCar> GetRentingCars();

    static std::vector<Car> GetUsersAvailableCars();
    static std::vector<LeasingCar> GetUsersLeasingCars();
    static std::vector<RentingCar> GetUsersRentingCars();
};

#endif //CHECHECI_CAR_LEASING_MAIN_H