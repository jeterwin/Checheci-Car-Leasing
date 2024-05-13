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
    bodyType = Coupe;
    drivetrain = AWD;
    VIN = color = make = model = "";
}

Car::Car(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
    enum FuelType fuelType, enum TransmissionType transmissionType, enum BodyType bodyType, enum Drivetrain drivetrain, std::string VIN, std::string color, std::string make, std::string model)
            : horsePower(horsePower), carPrice(carPrice), productionYear(productionYear),
            kmsDriven(kmsDriven), motorSize(motorSize), fuelType(fuelType),
            transmissionType(transmissionType), bodyType(bodyType), drivetrain(drivetrain), VIN(VIN), color(color), make(make), model(model){}


std::ostream& operator<<(std::ostream& os, const Car& car)
{
    os << "Make: "<< car.make << "\n";
    os << "Model: "<< car.model << "\n";
    os << "Price: "<< car.carPrice << "\n";
    os << "Body Type: "<< car.bodyType << "\n";
    os << "Color: "<< car.color << "\n";
    os << "Year of Fabrication: " << car.productionYear << "\n";
    os << "VIN: " << car.VIN << "\n";
    os << "Mileage: " << car.kmsDriven << "\n";
    os << "Fuel Type: " << car.fuelType << "\n";
    os << "Transmission: " << car.transmissionType << "\n";
    os << "Drivetrain: " << car.drivetrain << "\n";
    os << "Capacity: " << car.motorSize << "\n";
    os << "Horse Power: " << car.horsePower;

    return os;
}

std::string Car::getStatus()
{
    return "Available";
}

int Car::GetHP()
{
    return this -> horsePower;
}

