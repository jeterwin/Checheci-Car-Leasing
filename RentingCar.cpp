//
// Created by Erwin on 5/10/2024.
//

#include "RentingCar.h"
#include <iostream>

RentingCar::RentingCar()
{
    rentingPeriod = 0;
    rentingPrice = 0;
}


RentingCar::
RentingCar(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
enum FuelType fuelType, enum TransmissionType transmissionType, string color, string brand, string model, string carName, int rentingPrice, int rentingPeriod)
{
    this -> horsePower = horsePower;
}

