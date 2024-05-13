//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include "Car.h"

Car::Car()
{
    horsePower = carPrice = productionYear = kmsDriven = motorSize = 0;
    fuelType = Electric;
    transmissionType = Manual;
    color = brand = model = carName = "";
}

Car::Car(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
    enum FuelType fuelType, enum TransmissionType transmissionType, std::string color, std::string brand, std::string model, std::string carName)
            : horsePower(horsePower), carPrice(carPrice), productionYear(productionYear),
            kmsDriven(kmsDriven), motorSize(motorSize), fuelType(fuelType),
            transmissionType(transmissionType), color(color), brand(brand), model(model), carName(carName) {}

int Car::GetHP()
{
    return this -> horsePower;
}