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

void RentingCar::print() {
    std::cout << "Renting Period: " << rentingPeriod << "\n";
    std::cout << "Renting Price: " << rentingPrice << "\n";
    std::cout << *this;
}

RentingCar::RentingCar(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
           enum FuelType fuelType, enum TransmissionType transmissionType, enum BodyType bodyType, enum Drivetrain drivetrain, std::string VIN, std::string color,
           std::string make, std::string model, int rentingPrice, int rentingPeriod)
    : Car(horsePower, carPrice, productionYear, kmsDriven, motorSize, fuelType, transmissionType, bodyType, drivetrain, VIN, color, make, model) , rentingPrice(rentingPrice), rentingPeriod(rentingPeriod){
}

std::string RentingCar::getStatus()
{
    return "Renting";
}