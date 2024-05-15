//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include <cstring>

#include "CarFactory.h"

#include "FileHandler.h"

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

void CarFactory::DisplayRentedCars(std::string carOwner)
{
    std::string carInfo, renterFirstName, renterLastName;

    std::ifstream carFile;
    carFile.open(FileHandler::GetRentedCars());


    while(std::getline(carFile, carInfo))
    {
        int counter = 0;

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
            p = strtok(NULL, " ");
            counter++;
        }

        if(renterFirstName + " " + renterLastName == carOwner)
        {
            std::cout <<  p << "\n";
        }

    }

    carFile.close();
    while(1 == 1)
    {

    }
}

void CarFactory::DisplayLoanedCars(std::string carOwner)
{

}

void CarFactory::DisplaySoldCars(std::string carOwner)
{

}

void CarFactory::UpdateCarListing(std::string carOwner)
{

}

void CarFactory::DisplayAvailableCars()
{
    std::ifstream file;
    file.open(FileHandler::GetAvailableCars());
    /*int horsePower, carPrice, productionYear, kmsDriven, motorSize;
    FuelType fuelType;
    TransmissionType transmissionType;
    Drivetrain driveTrain;
    std::string VIN, color, make, model;*/
    std::cout << "These are all the available cars in Checheci® Leasing Automobiles:\n\n";

    std::string carInformation;
    while(std::getline(file, carInformation))
    {
        std::cout << carInformation << std::endl;
    }
    file.close();

    while(1 == 1)
    {

    }
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