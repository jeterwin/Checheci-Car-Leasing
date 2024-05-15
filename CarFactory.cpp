//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include <cstring>

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
    display.PressAnyKey();
    mainClass.MenuOptions();
}

void CarFactory::DisplayAvailableCars()
{
    std::ifstream carFile;
    carFile.open(FileHandler::GetAvailableCars());
    /*int horsePower, carPrice, productionYear, kmsDriven, motorSize;
    FuelType fuelType;
    TransmissionType transmissionType;
    Drivetrain driveTrain;
    std::string VIN, color, make, model;*/
    std::cout << "These are all the available cars in Checheci Leasing Automobile:\n\n";

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

void CarFactory::DisplayCarsForRent()
{

}

void CarFactory::DisplayCarsForLease()
{

}

void CarFactory::SearchForCar(std::string personName)
{

}
