//
// Created by Erwin on 5/10/2024.
//

#include <iostream>

#include "LeasingCar.h"
#include "FileHandler.h"

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

LeasingCar::LeasingCar(int leasingPrice, int leasingPeriod, std::string make, std::string model, int carPrice, enum BodyType bodyType, std::string color,
                       int productionYear, std::string VIN, int kmsDriven, enum FuelType fuelType,
                       enum TransmissionType transmissionType, enum Drivetrain drivetrain, int motorSize, int horsePower)
                       : Car(make, model, carPrice, bodyType, color, productionYear, VIN, kmsDriven,
                             fuelType, transmissionType, drivetrain, motorSize, horsePower), leasingPrice(leasingPrice), leasingPeriod(leasingPeriod) {}

void LeasingCar::print() {
    std::cout << "Leasing Price: " << leasingPrice << "\n";
    std::cout << "Leasing Period: " << leasingPeriod << "\n";
    std::cout << *this;
}

void LeasingCar::writeToFile()
{
    FileHandler handler;
    std::string filePath = handler.GetLeasedCars();

    std::fstream myFile (filePath, std::ios_base::app);
    if (myFile.is_open())
    {
        myFile << leasingPrice << " " << leasingPeriod << " ";
        myFile << *this;
        myFile.close();
    }
    else
        return;
}

std::string LeasingCar::getStatus()
{
    return "Leasing";
}

