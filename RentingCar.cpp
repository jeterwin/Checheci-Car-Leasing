//
// Created by Erwin on 5/10/2024.
//

#include <iostream>

#include "RentingCar.h"
#include "FileHandler.h"

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

RentingCar::RentingCar(int rentingPrice, int rentingPeriod, std::string make, std::string model, int carPrice, enum BodyType bodyType, std::string color,
                       int productionYear, std::string VIN, int kmsDriven, enum FuelType fuelType,
                       enum TransmissionType transmissionType, enum Drivetrain drivetrain,
                               int motorSize, int horsePower)
                    : rentingPrice(rentingPrice), rentingPeriod(rentingPeriod), Car(make, model, carPrice, bodyType, color, productionYear, VIN, kmsDriven,
                        fuelType, transmissionType, drivetrain, motorSize, horsePower) {}

void RentingCar::writeToFile()
{
    std::string filePath = FileHandler::GetRentedCarsFileName();

    std::fstream myFile (filePath, std::ios_base::app);
    if (myFile.is_open())
    {
        myFile << rentingPrice << "," << rentingPeriod << ",";
        myFile << *this;
        myFile.close();
    }
    else
        return;
}

std::string RentingCar::getStatus()
{
    return "Renting";
}

void RentingCar::writeToFile(std::string carOwner)
{
    //Car::writeToFile(fileToWriteInto, carOwner);
}
