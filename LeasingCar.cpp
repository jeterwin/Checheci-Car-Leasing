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

LeasingCar::LeasingCar(std::string carOwner, std::string make, std::string model, int carPrice, enum BodyType bodyType, std::string color,
int productionYear, std::string VIN, int kmsDriven, enum FuelType fuelType,
enum TransmissionType transmissionType, enum Drivetrain drivetrain, int motorSize, int horsePower, int leasingPrice, int leasingPeriod)
: Car(carOwner, make, model, carPrice, bodyType, color, productionYear, VIN, kmsDriven,
fuelType, transmissionType, drivetrain, motorSize, horsePower), leasingPrice(leasingPrice), leasingPeriod(leasingPeriod) {}

std::fstream& operator<<(std::fstream& file, const LeasingCar& car)
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

std::ostream& operator<<(std::ostream& os, const LeasingCar& car)
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
    os << "Horse Power: " << car.horsePower << "\n";
    os << "Leasing Price: " << car.leasingPrice << "\n";
    os << "Leasing Period: " << car.leasingPeriod;

    return os;
}

std::string LeasingCar::ObjectToString()
{
    std::string str_object;
    str_object+=carOwner+","+make+","+model+","+std::to_string(carPrice)+","+ stringBodyType(bodyType)+","+color+","+
                std::to_string(productionYear)+","+VIN+","+std::to_string(kmsDriven)+","+stringFuelType(fuelType)+","+
                stringTransmissionType(transmissionType)+","+ stringDrivetrain(drivetrain)+","+std::to_string(motorSize)+
                +","+std::to_string(horsePower)+","+std::to_string(leasingPrice)+","+std::to_string(leasingPeriod);
    return str_object;
}

void LeasingCar::writeToFile(std::string carOwner)
{
    std::string filePath = FileHandler::GetLeasedCarsFileName();
    std::fstream myFile (filePath, std::ios_base::app);

    if (myFile.is_open())
    {
        myFile << leasingPrice << "," << leasingPeriod << ",";
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

void LeasingCar::deleteFromFile()
{
    //Car::deleteFromFile();
}

