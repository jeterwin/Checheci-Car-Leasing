//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include <fstream>

#include "Car.h"
#include "FileHandler.h"



Car::Car()
{
    horsePower = carPrice = productionYear = kmsDriven = motorSize = 0;
    fuelType = Electric;
    transmissionType = Manual;
    bodyType = Coupe;
    drivetrain = AWD;
    VIN = color = make = model = "";
}

Car::Car(std::string make, std::string model, int carPrice, enum BodyType bodyType, std::string color,
            int productionYear, std::string VIN, int kmsDriven, enum FuelType fuelType,
            enum TransmissionType transmissionType, enum Drivetrain drivetrain, int motorSize, int horsePower)
                    : make(make), model(model), carPrice(carPrice), bodyType(bodyType), color(color), productionYear(productionYear),
                      VIN(VIN), kmsDriven(kmsDriven), fuelType(fuelType), transmissionType(transmissionType), drivetrain(drivetrain),
                      motorSize(motorSize), horsePower(horsePower) {}

std::ostream& operator<<(std::ostream& os, const Car& car)
{
    os << "Make: "<< car.make << "\n";
    os << "Model: "<< car.model << "\n";
    os << "Price: "<< car.carPrice << "\n";
    os << "Body Type: "<< stringBodyType(car.bodyType) << "\n";
    os << "Color: "<< car.color << "\n";
    os << "Year of Fabrication: " << car.productionYear << "\n";
    os << "VIN: " << car.VIN << "\n";
    os << "Mileage: " << car.kmsDriven << "\n";
    os << "Fuel Type: " << stringFuelType(car.fuelType) << "\n";
    os << "Transmission: " << stringTransmissionType(car.transmissionType) << "\n";
    os << "Drivetrain: " << stringDrivetrain(car.drivetrain) << "\n";
    os << "Capacity: " << car.motorSize << "\n";
    os << "Horse Power: " << car.horsePower;

    return os;
}

std::fstream& operator<<(std::fstream& file, const Car& car)
{
    file << car.make << " ";
    file << car.model << " ";
    file << car.carPrice << " ";
    file << stringBodyType(car.bodyType) << " ";
    file << car.color << " ";
    file << car.productionYear << " ";
    file << car.VIN << " ";
    file << car.kmsDriven << " ";
    file << stringFuelType(car.fuelType) << " ";
    file << stringTransmissionType(car.transmissionType) << " ";
    file << stringDrivetrain(car.drivetrain) << " ";
    file << car.motorSize << " ";
    file << car.horsePower;
    file << "\n";

    return file;
}

void Car::writeToFile()
{
    FileHandler handler;
    std::string filePath = handler.GetAvailableCars();

    std::fstream myFile (filePath, std::ios_base::app);
    if (myFile.is_open())
    {
        myFile << *this;
        myFile.close();
    }
    else
        return;

}

void Car::deleteFromFile()
{
    FileHandler handler;
    std::string filePath = handler.GetAvailableCars();
}

std::string Car::getStatus()
{
    return "Available";
}

int Car::GetHP()
{
    return this -> horsePower;
}

std::string stringTransmissionType(enum TransmissionType x)
{
    switch(x)
    {
        case 0:
            return "Automatic";
            break;

        case 1:
            return "Manual";
            break;

        default:
            return "InvalidTransmissionType";
    }
}

std::string stringFuelType(enum FuelType x)
{
    switch(x)
    {
        case 0:
            return "Diesel";
            break;

        case 1:
            return "Electric";
            break;

        case 2:
            return "Hybrid";
            break;

        case 3:
            return "Gasoline";
            break;

        default:
            return "InvalidFuelType";
    }
}

std::string stringBodyType(enum BodyType x)
{
    switch(x)
    {
        case 0:
            return "Suv";
            break;

        case 1:
            return "Coupe";
            break;

        case 2:
            return "Sports";
            break;

        default:
            return "InvalidBodyType";
    }
}

std::string stringDrivetrain(enum Drivetrain x)
{
    switch(x)
    {
        case 0:
            return "AWD";
            break;

        case 1:
            return "4WD";
            break;

        case 2:
            return "RWD";
            break;

        case 3:
            return "FWD";
            break;

        default:
            return "InvalidDrivetrain";
    }
}

