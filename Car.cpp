//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include <fstream>
#include <map>
#include <regex>

#include "CarFactory.h"
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

void Car::writeToFile(std::string fileToWriteInto, std::string carOwner)
{
    std::fstream myFile (fileToWriteInto, std::ios_base::app);

    if(!carOwner.empty())
    {
        // Error opening file
        if(!myFile.is_open()) { return; }

        myFile << carOwner << ",";
    }

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
    std::string filePath = FileHandler::GetAvailableCars();
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

void Car::searchCars(std::vector<Car> cars, const std::string &make, const std::string &model,
const std::string &color, const std::string& transmissionType, const std::string& fuelType,
const std::string& drivetrainType, int maxKilometers, int motorSize, int horsePower, int maxPrice,
int minYear)
{
    display.DisplayWithColor("\nThese are all the cars that fit in the criteria given:\n\n", 4);
    int currentCar = 0, interestedCars = 0;
    //std::vector<Car> foundCars;
    std::map<int, int> carDictionary = { };

    for (const auto& car: cars)
    {
        if ((car.make == make || make.empty()) && (model.empty() || car.model == model)
        && (color.empty() || car.color == color)
        && car.carPrice <= maxPrice && car.productionYear >= minYear
        && car.kmsDriven <= maxKilometers)
        {
            carDictionary.insert(std::pair<int, int>(interestedCars, currentCar));
            //foundCars[currentCar] = car;
            std::cout << interestedCars + 1 <<". Make: " << car.make << ", Model: " << car.model <<
            ", Price: " << car.carPrice << ", Production Year: " << car.productionYear << std::endl;
            interestedCars++;
        }
        currentCar++;
    }
    MainClass mainClass;
    // There were no cars found
    if(interestedCars == 0)
    {
        display.DisplayWithColor("There were no cars found given the parameters given by you, try"
                                 " a broader search!", 4);

        mainClass.MenuOptions();
    }
    // At least one car was found
    else
    {
        display.DisplayWithColor("\nPlease enter the index of the car you are interested in.\n", 4);
        int ch;
        // What if he introduces a character? xd
        std::cin >> ch;
        while(ch > interestedCars || ch < 0)
        {
            std::cout << "Nuh-uh, pick a correct number you fa~\n";
            std::cin >> ch;
        }

        display.DisplayWithColor("You have successfully chosen car number ", 2);
        display.DisplayWithColor(ch, 2);
        std::cout << "\n";
        display.DisplayWithColor("Now, would you like to rent or lease the car? (type rent | lease)\n\n", 4);

        std::cin.ignore();
        std::string option;
        std::getline(std::cin, option);

        //std::regex rentPattern("([rR]ent)\\w*");
        //std::regex leasePattern("([lL]ease)\\w*");

        //while(!std::regex_match(option, rentPattern) || !std::regex_match(option, leasePattern))
        //{
            //std::cout << "Bro can't you read, type rent or lease ffs.\n";
            //std::getline(std::cin, option);
        //}

        // Write in rent or lease file depending on our option
        //cars[0].writeToFile(std::regex_match(option, rentPattern)
        //? FileHandler::GetRentedCars() : FileHandler::GetLeasedCars());
        cars[carDictionary[ch - 1]].writeToFile(option == "rent"
        ? FileHandler::GetRentedCars() : FileHandler::GetLeasedCars(), MainClass::GetUsername());

        CarFactory::DeleteCarFromFile(FileHandler::GetAvailableCars(), carDictionary[ch - 1]);

        display.DisplayError("");
        mainClass.MenuOptions();
    }
}