//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <string>

#include "CarFactory.h"
#include "Display.h"
#include "main.h"
#include "FileHandler.h"

static Display display;
static MainClass mainClass;

CarFactory::CarFactory()
{
    availableCarsNr = givenCarsNr = 0;
}

CarFactory::CarFactory(Car * car)
{
    availableCarsNr = givenCarsNr = 0;
    availableCars[availableCarsNr] = car;
    availableCarsNr++;
}

void CarFactory::DisplayRentedOrLeasedCars(std::string carOwner, int option)
{
    display.ResetScreen();
    // Option 0 = Rented, option 1 = leased
    // We need to initialize two strings in order to compare it to the user we're logged in
    std::string carInfo, renterFirstName = "a", renterLastName = "a";

    std::ifstream carFile;
    carFile.open(option == 0 ? FileHandler::GetRentedCars() : FileHandler::GetLeasedCars());
    // The counter is needed in order to keep track of who rented the car (first and second strings
    // represent the person that rented it)
    int counter = 0;

    std::cout << "These are all the cars you have ";
    option == 0 ? std::cout << "rented " : std::cout << "leased ";
    std::cout << "so far\n";
    display.DisplayWithColor("----------------------------------------------\n\n", 2);

    while(std::getline(carFile, carInfo))
    {
        counter = 0;

        short wordCharLength = carInfo.length();
        char* cString = new char[wordCharLength];
        strcpy(cString, carInfo.c_str());

        char *p = strtok(cString, " ");
        while(p)
        {
            if(counter == 0)
            {
                renterFirstName = p;
            }
            if(counter == 1)
            {
                renterLastName = p;
            }
            if(counter > 1)
                break;
            p = strtok(nullptr, " ");
            counter++;
        }

        if(renterFirstName + " " + renterLastName == carOwner)
        {
            while(p)
            {
                display.DisplayWithColor(p, 1); std::cout << " ";
                p = strtok(nullptr, " ");
            }

            std::cout << "\n";
        }

    }

    carFile.close();
    display.PressAnyKey();
    mainClass.MenuOptions();
}

void CarFactory::DisplaySoldCars(std::string carOwner)
{
    display.ResetScreen();
    // Option 0 = Rented, option 1 = leased
    // We need to initialize two strings in order to compare it to the user we're logged in
    std::string carInfo, renterFirstName = "a", renterLastName = "a";

    std::ifstream carFile;
    carFile.open(FileHandler::GetSoldCars());
    // The counter is needed in order to keep track of who rented the car (first and second strings
    // represent the person that rented it)
    int counter = 0;

    std::cout << "These are all the cars you have sold so far\n";
    std::cout << "<Owner of the car> <Car information>\n\n";
    display.DisplayWithColor("----------------------------------------------\n\n", 2);

    while(std::getline(carFile, carInfo))
    {
        counter = 0;

        short wordCharLength = carInfo.length();
        char* cString = new char[wordCharLength];
        strcpy(cString, carInfo.c_str());

        char *p = strtok(cString, " ");
        while(p)
        {
            if(counter == 0)
            {
                renterFirstName = p;
            }
            if(counter == 1)
            {
                renterLastName = p;
            }
            if(counter > 1)
                break;
            p = strtok(nullptr, " ");
            counter++;
        }

        if(renterFirstName + " " + renterLastName == carOwner)
        {
            while(p)
            {
                if(counter == 4)
                {
                    std::cout << "--> ";
                }
                display.DisplayWithColor(p, 1);
                std::cout << " ";
                p = strtok(nullptr, " ");
                counter++;
            }
            std::cout << "\n";
        }
    }

    carFile.close();
    display.PressAnyKey();
    mainClass.MenuOptions();
}

void CarFactory::UpdateCarListing(std::string carOwner)
{
    display.ResetScreen();

    display.PressAnyKey();
    mainClass.MenuOptions();
}

void CarFactory::DisplayAvailableCars(int displayedCarsPerPage = 5)
{
    display.ResetScreen();
    int maxCarsPerPage = 10;

    std::ifstream carFile;
    carFile.open(FileHandler::GetAvailableCars());
    /*int horsePower, carPrice, productionYear, kmsDriven, motorSize;
    FuelType fuelType;
    TransmissionType transmissionType;
    Drivetrain driveTrain;
    std::string VIN, color, make, model;*/
    std::cout << "These are all the available cars in Checheci Leasing Automobile:\n\n";
    display.DisplayWithColor("----------------------------------------------\n\n", 2);

    std::string carInformation;
    while(std::getline(carFile, carInformation))
    {
        std::cout << carInformation << std::endl;
    }
    carFile.close();

    display.PressAnyKey();
    mainClass.MenuOptions();
}


int CarFactory::CurrentAvailableCarsNr()
{
    return this -> availableCarsNr;
}

int CarFactory::GivenCarsNr()
{
    return this -> givenCarsNr;
}

void CarFactory::AddCar(Car * car)
{
    availableCars[availableCarsNr] = car;
    availableCarsNr++;
}

Car** CarFactory::GetAvailableCars()
{
    return availableCars;
}

Car** CarFactory::GetGivenCars()
{
    return givenCars;
}

void CarFactory::DisplayCarsForRentOrLease(int displayedCars, int option)
{
    display.ResetScreen();
    int maxCarsPerPage = 10;

    /*int horsePower, carPrice, productionYear, kmsDriven, motorSize;
    FuelType fuelType;
    TransmissionType transmissionType;
    Drivetrain driveTrain;
    std::string VIN, color, make, model;*/

    // Option = 0 => renting cars, Option = 1 => leasing cars
    std::cout << "These are all the cars that can be ";
    option == 0 ? std::cout << "rented " : std::cout << "leased ";
    std::cout << "from Checheci Leasing Automobile\n\n";

    display.DisplayWithColor("----------------------------------------------\n\n", 2);

    std::string carInformation;
    std::ifstream carFile;
    carFile.open(option == 0 ? FileHandler::GetAvailableRentingCars() : FileHandler::GetAvailableLeasingCars());

    while(std::getline(carFile, carInformation))
    {
        std::cout << carInformation << std::endl;
    }
    carFile.close();

    display.PressAnyKey();
    mainClass.MenuOptions();
}

void CarFactory::SearchForCar(std::string personName)
{
    display.ResetScreen();

    display.DisplayWithColor("Welcome to our advanced car search engine!\n", 6);
    display.DisplayWithColor("You will be asked to provide certain details about "
    "the car you are looking for!", 6);
    display.DisplayError("\n\n");

    int horsePower, carPrice, productionYear, kmsDriven, motorSize;
    FuelType fuelType;
    TransmissionType transmissionType;
    Drivetrain driveTrain;
    std::string VIN, color, make, model;

    std::cout << "What is the make (car brand) of your desired car? (leave blank to not specify)\n";
    //std::cin >> make;
    std::cin.ignore();
    std::getline(std::cin, make);

    std::cout << "What is the model of your desired car? (leave blank to not specify)\n";
    std::cin >> model;

    std::cout << "What is the color of your desired car? (leave blank to not specify)\n";
    std::cin >> color;

    // We could add a range (cool idea)
    std::cout << "What is the minimum production year of your desired car?\n";
    std::cin >> productionYear;

    // Could add a range too
    std::cout << "What is the horse power of your desired car? (leave blank to not specify)\n";
    std::cin >> horsePower;

    // Should add a range
    std::cout << "What is the motor size (in cc) of your desired car? (leave blank to not specify)\n";
    std::cin >> motorSize;

    std::cout << "What is the transmission type of your desired car? (0 for Automatic, 1 for Manual)  (leave blank to not specify)\n";
    int transmissionInput;
    std::cin >> transmissionInput;
    transmissionType = static_cast<TransmissionType>(transmissionInput);

    std::cout << "What is the fuel type of your desired car? (0 for Diesel, 1 for Electric, 2 for Hybrid, 3 for Gasoline) (leave blank to not specify)\n";
    int fuelInput;
    std::cin >> fuelInput;
    fuelType = static_cast<FuelType>(fuelInput);

    std::cout << "What is the drivetrain type of your desired car? (0 for AWD, 1 for 4WD, 2 for RWD, 3 for FWD) (leave blank to not specify)\n";
    int drivetrainInput;
    std::cin >> drivetrainInput;
    driveTrain = static_cast<Drivetrain>(drivetrainInput);
    // Range
    std::cout << "What is the maximum price of your desired car?\n";
    std::cin >> carPrice;

    // Range
    std::cout << "How many kilometers has the car been driven?\n";
    std::cin >> kmsDriven;
    std::vector<Car> cars = Car::readCarsFromFile(FileHandler::GetAvailableCars());

    Car::searchCars(cars, make, model, color, Car::stringTransmissionType(transmissionType),
Car::stringFuelType(fuelType), Car::stringDrivetrain(driveTrain),
kmsDriven, motorSize, horsePower, carPrice, productionYear);
    while(1 == 1)
    {

    }
}
