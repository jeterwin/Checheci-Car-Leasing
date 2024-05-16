//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include <fstream>

#include "Car.h"
#include "main.h"
#include "FileHandler.h"
#include "Display.h"

static Display display;

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

std::fstream& operator<<(std::fstream& file, const Car& car)
{
    file << car.make << " ";
    file << car.model << " ";
    file << car.carPrice << " ";
    file << Car::stringBodyType(car.bodyType) << " ";
    file << car.color << " ";
    file << car.productionYear << " ";
    file << car.VIN << " ";
    file << car.kmsDriven << " ";
    file << Car::stringFuelType(car.fuelType) << " ";
    file << Car::stringTransmissionType(car.transmissionType) << " ";
    file << Car::stringDrivetrain(car.drivetrain) << " ";
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



std::string Car::stringTransmissionType(enum TransmissionType x)
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

std::string Car::stringFuelType(enum FuelType x)
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

std::string Car::stringBodyType(enum BodyType x)
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

std::string Car::stringDrivetrain(enum Drivetrain x)
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

std::vector<Car> Car::readCarsFromFile(const std::string& filename)
{
    std::vector<Car> cars;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return cars;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        Car car;
        int t1, t2, t3;
        iss >> car.make >> car.model >> car.carPrice >> t1 >> t2 >> t3 >> car.color >> car.productionYear
            >> car.VIN >> car.kmsDriven;

        car.fuelType = static_cast<FuelType>(t1);
        car.transmissionType = static_cast<TransmissionType>(t2);
        car.drivetrain = static_cast<Drivetrain>(t3);;

        iss >> car.motorSize >> car.horsePower;

        cars.push_back(car);
    }

    file.close();
    return cars;
}

void Car::searchCars(const std::vector<Car> &cars, const std::string &make, const std::string &model,
const std::string &color, const std::string& transmissionType, const std::string& fuelType,
const std::string&  drivetrainType, int maxKilometers, int motorSize, int horsePower, int maxPrice,
int minYear)
{
    display.DisplayWithColor("\nThese are all the cars that fit in the criteria given:\n\n", 4);
    int currentCar = 0;
    std::vector<Car> foundCars;

    for (const auto& car: cars)
    {
        if ((car.make == make || make.empty()) && (model.empty() || car.model == model)
        && (color.empty() || car.color == color)
        && car.carPrice <= maxPrice && car.productionYear >= minYear
        && car.kmsDriven <= maxKilometers)
        {
            foundCars[currentCar] = car;
            std::cout << currentCar + 1 <<". Make: " << car.make << ", Model: " << car.model <<
            ", Price: " << car.carPrice << ", Production Year: " << car.productionYear << std::endl;
            currentCar++;
        }
    }
    MainClass mainClass;
    // There were no cars found
    if(currentCar == 0)
    {

        mainClass.MenuOptions();
    }
    // At least one car was found
    else
    {
        display.DisplayWithColor("There were no cars found given the parameters given by you, try"
         " a broader search!", 4);
        display.DisplayError("");
        mainClass.MenuOptions();
    }
}