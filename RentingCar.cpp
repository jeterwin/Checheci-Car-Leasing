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
                    : rentingPrice(rentingPrice), rentingPeriod(rentingPeriod), Car(carOwner, make, model, carPrice, bodyType, color, productionYear, VIN, kmsDriven,
                        fuelType, transmissionType, drivetrain, motorSize, horsePower) {}

void RentingCar::writeToFile(std::string carOwner)
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


std::fstream& operator<<(std::fstream& file, const RentingCar& car)
{
    file << car.make << ",";
    file << car.model << ",";
    file << car.carPrice << ",";
    file << Car::stringBodyType(car.bodyType) << ",";
    file << car.color << ",";
    file << car.productionYear << ",";
    file << car.VIN << ",";
    file << car.kmsDriven << ",";
    file << Car::stringFuelType(car.fuelType) << ",";
    file << Car::stringTransmissionType(car.transmissionType) << ",";
    file << Car::stringDrivetrain(car.drivetrain) << ",";
    file << car.motorSize << ",";
    file << car.horsePower;
    file << "\n";

    return file;
}

std::ostream& operator<<(std::ostream& os, const RentingCar& car)
{
    os << "Make: "<< car.make << "\n";
    os << "Model: "<< car.model << "\n";
    os << "Price: "<< car.carPrice << "\n";
    os << "Body Type: "<< Car::stringBodyType(car.bodyType) << "\n";
    os << "Color: "<< car.color << "\n";
    os << "Year of Fabrication: " << car.productionYear << "\n";
    os << "VIN: " << car.VIN << "\n";
    os << "Mileage: " << car.kmsDriven << "\n";
    os << "Fuel Type: " << Car::stringFuelType(car.fuelType) << "\n";
    os << "Transmission: " << Car::stringTransmissionType(car.transmissionType) << "\n";
    os << "Drivetrain: " << Car::stringDrivetrain(car.drivetrain) << "\n";
    os << "Capacity: " << car.motorSize << "\n";
    os << "Horse Power: " << car.horsePower;

    return os;
}

std::string RentingCar::getStatus()
{
    return "Renting";
}

std::string RentingCar::GetCarOwnerName()
{
    //return Car::GetCarOwnerName();
    return this -> carOwner;
}
