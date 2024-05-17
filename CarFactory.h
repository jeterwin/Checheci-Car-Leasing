//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_CARFACTORY_H
#define CHECHECI_CAR_LEASING_CARFACTORY_H

#include <map>

#include "LeasingCar.h"
#include "RentingCar.h"
#include "main.h"


class CarFactory {

protected:
    Car * availableCars[1000];
    Car * givenCars[1000];

    int availableCarsNr;
    int givenCarsNr;

public:
    CarFactory();
    CarFactory(Car * leasingCar);

    void SearchForCar(std::string personName);
    static void DeleteCarFromFile(std::string fileName, int lineToBeDeleted);

    void DisplayCarsForRentOrLease(int displayedCars, int option);
    void DisplayRentedOrLeasedCars(std::string carOwner, int option);
    void DisplayAvailableCars(int displayedCars);
    void DisplaySoldCars(std::string carOwner);

    void UpdateCarListing(std::string carOwner);

    void AddCar(Car *);

    Car ** GetAvailableCars();
    Car ** GetGivenCars();

    int CurrentAvailableCarsNr();
    int GivenCarsNr();
};


#endif //CHECHECI_CAR_LEASING_CARFACTORY_H