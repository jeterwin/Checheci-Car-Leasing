//
// Created by Erwin on 5/10/2024.
//

#include "LeasingCar.h"

LeasingCar::LeasingCar()
{
    leasingPeriod = 0;
    leasingPrice = 0;
}

LeasingCar::LeasingCar(int leasingPrice, int leasingPeriod)
{
    this -> leasingPeriod = leasingPeriod;
    this -> leasingPrice = leasingPrice;
}

LeasingCar::LeasingCar(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
                       enum FuelType fuelType, enum TransmissionType transmissionType,
                               enum BodyType bodyType,enum Drivetrain drivetrain,
                                       std::string VIN, std::string color,std::string make, std::string model,
                                       int leasingPrice, int leasingPeriod)
                       : Car(horsePower, carPrice, productionYear, kmsDriven, motorSize, fuelType, transmissionType,
                             bodyType, drivetrain, VIN, color, make, model),
                             leasingPrice(leasingPrice), leasingPeriod(leasingPeriod) {}

void LeasingCar::print() {
    std::cout << "Leasing Price: " << leasingPrice << "\n";
    std::cout << "Leasing Period: " << leasingPeriod << "\n";
    std::cout << *this;
}

