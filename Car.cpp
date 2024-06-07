//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <windows.h>

#include "CarFactory.h"
#include "Car.h"
#include "main.h"
#include "FileHandler.h"
#include "Display.h"

Car::Car()
{
    horsePower = carPrice = productionYear = kmsDriven = motorSize = 0;
    fuelType = Electric;
    transmissionType = Manual;
    bodyType = Coupe;
    drivetrain = AWD;
    carOwner = VIN = color = make = model = "";
}

Car::Car(std::string carOwner, std::string make, std::string model, int carPrice, enum BodyType bodyType, std::string color,
         int productionYear, std::string VIN, int kmsDriven, enum FuelType fuelType,
         enum TransmissionType transmissionType, enum Drivetrain drivetrain, int motorSize, int horsePower)
        : carOwner(carOwner), make(make), model(model), carPrice(carPrice), bodyType(bodyType), color(color), productionYear(productionYear),
          VIN(VIN), kmsDriven(kmsDriven), fuelType(fuelType), transmissionType(transmissionType), drivetrain(drivetrain),
          motorSize(motorSize), horsePower(horsePower) {}

std::string Car::getMake()
{
    return this->make;
}

std::string Car::getModel()
{
    return this->model;
}

int Car::getPrice()
{
    return this->carPrice;
}

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

void Car::writeToFile(std::string filename)
{
    std::fstream myFile (filename, std::ios_base::app);

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

}

std::string Car::ObjectToString()
{
    std::string str_object;
    str_object+=carOwner+","+make+","+model+","+std::to_string(carPrice)+","+ stringBodyType(bodyType)+","+color+","+
            std::to_string(productionYear)+","+VIN+","+std::to_string(kmsDriven)+","+stringFuelType(fuelType)+","+
            stringTransmissionType(transmissionType)+","+ stringDrivetrain(drivetrain)+","+std::to_string(motorSize)+
            +","+std::to_string(horsePower);
    return str_object;
}

std::string Car::getStatus()
{
    return "Available";
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

        case 4:
            return "LPG";
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
            return "SUV";
            break;

        case 1:
            return "Coupe";
            break;

        case 2:
            return "Compact";
            break;

        case 3:
            return "Convertible";
            break;

        case 4:
            return "Wagon";
            break;

        case 5:
            return "Sedan";
            break;

        case 6:
            return "Van";
            break;

        case 7:
            return "Transporter";
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

void Car::searchCars(std::string filename, std::vector<Car> cars, const std::string &make, const std::string &model,
                     const std::string &color, const std::string& transmissionType, const std::string& fuelType,
                     const std::string& drivetrainType, int maxKilometers, int motorSize, int horsePower, int maxPrice,
                     int minYear)
{
    Display::DisplayWithColor("\nThese are all the cars that fit in the criteria given:\n\n", 4);
    int currentCar = 0, interestedCars = 0;
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
    // There were no cars found
    if(interestedCars == 0)
    {
        Display::DisplayWithColor("There were no cars found given the parameters given by you, try"
                                  " a broader search!", 4);

        MainClass::MenuOptions();
    }
        // At least one car was found
    else
    {
        Display::DisplayWithColor("\nPlease enter the index of the car you are interested in.\n", 4);
        int ch;
        // What if he introduces a character? xd
        std::cin >> ch;
        while(ch > interestedCars || ch < 0)
        {
            std::cout << "Nuh-uh, pick a correct number you fa~\n";
            std::cin >> ch;
        }

        Display::DisplayWithColor("You have successfully chosen car number ", 2);
        Display::DisplayWithColor(ch, 2);
        std::cout << "\n";
        Display::DisplayWithColor("Now, would you like to rent or lease the car? (type rent | lease)\n\n", 4);

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
        //? FileHandler::GetRentedCarsFileName() : FileHandler::GetLeasedCarsFileName());

        cars[carDictionary[ch - 1]].writeToFile(filename);

        CarFactory::DeleteCarFromFile(FileHandler::GetAvailableCarsFileName(), carDictionary[ch - 1]);

        Sleep(2000);
        MainClass::MenuOptions();
    }
}

void Car::displayCars(std::vector<Car> cars, const std::string &make, const std::string &model,
                      const std::string &color, const std::string& transmissionType, const std::string& fuelType,
                      const std::string& drivetrainType, int maxKilometers, int motorSize, int horsePower, int maxPrice,
                      int minYear)
{
    Display::DisplayWithColor("\nThese are all the cars that fit in the criteria given:\n\n", 4);
    int interestedCars = 0;

    for (const auto& car: cars)
    {
        if ((car.make == make || make.empty()) && (model.empty() || car.model == model)
            && (color.empty() || car.color == color)
            && car.carPrice <= maxPrice && car.productionYear >= minYear
            && car.kmsDriven <= maxKilometers)
        {
            //foundCars[currentCar] = car;
            std::cout << interestedCars + 1 <<". Make: " << car.make << ", Model: " << car.model <<
                      ", Price: " << car.carPrice << ", Production Year: " << car.productionYear << std::endl;
            interestedCars++;
        }
    }
    // There were no cars found
    if(interestedCars == 0)
    {
        Display::DisplayWithColor("There were no cars found given the parameters given by you, try"
                                  " a broader search!", 4);
    }

    Display::PressAnyKey();
    MainClass::MenuOptions();
}

void Car::ValidateChoiceBodyType(int &userChoice, int userTries)
{
    std::cin>>userChoice;
    userTries++;

    while ( (userChoice<0 || userChoice > 7) && userTries <=5 )
    {
        std::cout << userChoice << " is not a valid choice!\n";
        std::cout << "Please, try again!\n";

        std::cin>>userChoice;
        userTries++;
    }

    if ( userTries > 5)
        userChoice=-1;

    return ;
}

void Car::ValidateChoiceFuelType(int &userChoice, int userTries)
{
    std::cin>>userChoice;
    userTries++;

    while ( (userChoice<0 || userChoice > 4) && userTries <=5 )
    {
        std::cout << userChoice << " is not a valid choice!\n";
        std::cout << "Please, try again!\n";

        std::cin>>userChoice;
        userTries++;
    }

    if ( userTries > 5)
        userChoice=-1;

    return ;
}

void Car::ValidateChoiceTransmissionType(int &userChoice, int userTries)
{
    std::cin>>userChoice;
    userTries++;

    while ( (userChoice<0 || userChoice > 1) && userTries <=5 )
    {
        std::cout << userChoice << " is not a valid choice!\n";
        std::cout << "Please, try again!\n";

        std::cin>>userChoice;
        userTries++;
    }

    if (userTries > 5)
        userChoice=-1;

    return ;
}

void Car::ValidateChoiceDrivetrain(int &userChoice, int userTries)
{
    std::cin>>userChoice;
    userTries++;

    while ( (userChoice<0 || userChoice > 3) && userTries <=5 )
    {
        std::cout << userChoice << " is not a valid choice!\n";
        std::cout << "Please, try again!\n";

        std::cin>>userChoice;
        userTries++;
    }

    if ( userTries > 5)
        userChoice=-1;

    return ;
}

std::string Car::GetCarOwnerName()
{
    return this -> carOwner;
}

int Car::FindCarIndexInFile(const std::vector<Car>& cars, const std::string &make, const std::string &model, const std::string &color,
                            const std::string &transmissionType, const std::string &fuelType, const std::string &drivetrainType,
                            int maxKilometers, int motorSize, int horsePower, int maxPrice, int minYear)
{
    int currentCarLine = 0;

    for (const auto& car: cars)
    {
        if ((car.make == make || make.empty()) && (model.empty() || car.model == model)
            && (color.empty() || car.color == color)
            && car.carPrice <= maxPrice && car.productionYear >= minYear
            && car.kmsDriven <= maxKilometers)
        {
            return currentCarLine;
        }
        currentCarLine++;
    }

    return -1;
}

int Car::stringToIntTransmissionType(const std::string& transmissionType)
{
    if ( transmissionType == "Automatic" )
        return 0;
    if ( transmissionType == "Manual" )
        return 1;

    return -1;
}

int Car::stringToIntDrivetrain(const std::string &drivetrain)
{
    if ( drivetrain == "AWD" )
        return 0;
    if ( drivetrain == "4WD" )
        return 1;
    if ( drivetrain == "RWD" )
        return 2;
    if ( drivetrain == "FWD" )
        return 3;

    return -1;
}

int Car::stringToIntBodyType(const std::string &bodyType)
{
    if ( bodyType == "SUV" )
        return 0;
    if ( bodyType == "Coupe" )
        return 1;
    if ( bodyType == "Compact" )
        return 2;
    if ( bodyType == "Convertible" )
        return 3;
    if ( bodyType == "Wagon" )
        return 4;
    if ( bodyType == "Sedan" )
        return 5;
    if ( bodyType == "Van" )
        return 6;
    if ( bodyType == "Transporter" )
        return 7;

    return -1;
}

int Car::stringToIntFuelType(const std::string &fuelType)
{
    if ( fuelType == "Diesel" )
        return 0;
    if ( fuelType == "Electric" )
        return 1;
    if ( fuelType == "Hybrid" )
        return 2;
    if ( fuelType == "Gasoline" )
        return 3;
    if ( fuelType == "LPG" )
        return 4;

    return -1;
}