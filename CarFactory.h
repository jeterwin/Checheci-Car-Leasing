//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_CARFACTORY_H
#define CHECHECI_CAR_LEASING_CARFACTORY_H

#include <map>
#include <vector>

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

    void SearchForCar(std::vector<Car>, std::string personName);
    static void DeleteCarFromFile(std::string fileName, int lineToBeDeleted);

    void DisplayCarsForRentOrLease(std::vector<Car>, int displayedCars, int option);
    void DisplayRentedOrLeasedCars(std::vector<Car>, std::string carOwner, int option);
    void DisplayAvailableCars(std::vector<Car>, int displayedCars);
    void DisplaySoldCars(std::vector<Car>, std::string carOwner);

    void UpdateCarListing(std::string carOwner);

    void AddCar(int addingChoice, std::vector<Car>& carVectorToBeAdded);
};


#endif //CHECHECI_CAR_LEASING_CARFACTORY_H