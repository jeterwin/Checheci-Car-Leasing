//
// Created by Erwin on 5/10/2024.
//

#include <iostream>

#include "FileHandler.cpp"

#include "CarFactory.h"
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

void DisplayRentedCars()
{
    std::ifstream file = OpenReadFile("test.txt");
    std::string a,b;
    while(file >> a >> b)
    {
        std::cout << a << " " << b;
    }

    while(1 == 1)
    {

    }
}

void DisplayLoanedCars()
{

}

void DisplaySoldCars()
{

}
void UpdateCarListing()
{

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