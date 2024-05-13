//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_CARFACTORY_H
#define CHECHECI_CAR_LEASING_CARFACTORY_H

#include "LeasingCar.h"
#include "RentingCar.h"


class CarFactory {

    protected:
        Car * availableCars[1000];
        Car * givenCars[1000];

        int availableCarsNr;
        int givenCarsNr;

    public:
        CarFactory();
        CarFactory(Car * leasingCar);

        void DisplayRentedCars();
        void DisplayLoanedCars();
        void DisplaySoldCars();
        void UpdateCarListing();

        void AddCar(Car *);
        Car ** GetAvailableCars();
        Car ** GetGivenCars();

        int CurrentAvailableCarsNr();
        int GivenCarsNr();
};


#endif //CHECHECI_CAR_LEASING_CARFACTORY_H
