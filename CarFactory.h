//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_CARFACTORY_H
#define CHECHECI_CAR_LEASING_CARFACTORY_H

#include <map>
#include <vector>
#include <typeinfo>
#include <cmath>

#include "LeasingCar.h"
#include "RentingCar.h"
#include "Display.h"
#include "main.h"

#define RENT_MULTIPLIER 0.001
#define LEASE_MULTIPLIER 0.00080

void RentingPeriod (int *choice);
void LeasingPeriod (int *choice);


class CarFactory {

protected:
    Car * availableCars[1000];
    Car * givenCars[1000];

    int availableCarsNr;
    int givenCarsNr;

public:
    CarFactory();
    CarFactory(Car * leasingCar);

    void WriteCarStringInFile(std::string fileName, std::string car_string);

    void SearchForCar(std::vector<RentingCar>);
    void SearchForCar(std::vector<LeasingCar>);

    void displayCars(std::vector<RentingCar> cars, const std::string &make, const std::string &model, int maxPrice, const std::string &color, int minYear);

    void displayCars(std::vector<LeasingCar> cars, const std::string &make, const std::string &model, int maxPrice, const std::string &color, int minYear);

    static void DeleteCarFromFile(std::string fileName, int lineToBeDeleted);

    template<class T>
    void DisplayCarsForRentOrLease(std::vector<T>);

    template<class T>
    void DisplayRentedOrLeasedCars(std::vector<T>);

    void DisplayAvailableCars(std::vector<Car>);
    void DisplaySoldCars(std::vector<Car>);

    void UpdateCarListing(std::vector<Car> carVector);

    int SearchCarInFile(std::string fileName, std::string objectSearched);

    void UpdateExistingListing(std::vector<Car> carVector);

    void RemoveExistingListing();

    void CreateAvailableListing();

    void DeleteAvailableCar();
    void DeleteRentingCar();
    void DeleteLeasingCar();
};

template<class T>
void CarFactory::DisplayRentedOrLeasedCars(std::vector<T> carVector)
{
    Display::ResetScreen();
    // We need to initialize two strings in order to compare it to the user we're logged in
    int displayedCarsPerPage = 5, multiplier = 1,i,
            numberOfPages = std::ceil((float)carVector.size() / (float)displayedCarsPerPage);
    std::string ch;

    std::cout << "These are all the cars you have ";
    strcmp(typeid(carVector).name(), "class std::vector<class RentingCar,class std::allocator<class RentingCar> >") == 0 ? std::cout << "rented " : std::cout << "leased ";
    std::cout << "so far\n";
    Display::DisplayWithColor("----------------------------------------------\n\n", 2);

    while(1 == 1)
    {
        for(i = (multiplier - 1) * displayedCarsPerPage; i < multiplier * displayedCarsPerPage; i++)
        {
            if(i >= carVector.size()) { break; }

            Display::DisplayWithColor(i + 1, 4);
            Display::DisplayWithColor(". ", 4);
            std::cout << carVector[i] << "\n\n";
        }
        std::cout << "Type 'Exit' if you wish to stop being displayed any cars, 'next' if you wish"
                     " to see the next page of cars and 'back' in order to go the the previous car page.\n\n";
        Display::DisplayWithColor("You are currently viewing page ", 4);
        Display::DisplayWithColor(multiplier, 4);
        Display::DisplayWithColor("/", 4);
        Display::DisplayWithColor(numberOfPages, 4);
        std::cout << "\n\n";

        std::cin >> ch;

        if(ch == "exit" || ch == "Exit")
        {
            break;
        }
        else if(ch == "Next" || ch == "next")
        {
            multiplier++;
            if(multiplier > numberOfPages)
                multiplier = numberOfPages;
        }
        else
        {
            multiplier--;
            if(multiplier < 1)
                multiplier = 1;
        }
        Display::ResetScreen();
    }

    Display::PressAnyKey();
    MainClass::MenuOptions();
}

template<class T>
void CarFactory::DisplayCarsForRentOrLease(std::vector<T> carVector)
{
    Display::ResetScreen();
    std::string ch;
    int displayedCarsPerPage = 5, multiplier = 1, i = 0,
            numberOfPages = std::ceil((float)carVector.size() / (float)displayedCarsPerPage);

    // Option = 0 => renting cars, Option = 1 => leasing cars
    std::cout << "These are all the cars that can be ";

    strcmp(typeid(carVector).name(), "class std::vector<class RentingCar,class std::allocator<class RentingCar> >") == 0 ?
    std::cout << "rented " : std::cout << "leased ";
    std::cout << "from Checheci Leasing Automobile\n\n";

    Display::DisplayWithColor("----------------------------------------------\n\n", 2);

    while(1 == 1)
    {
        Display::ResetScreen();
        for(i = (multiplier - 1) * displayedCarsPerPage; i < multiplier * displayedCarsPerPage; i++)
        {
            if(i >= carVector.size()) { break; }

            Display::DisplayWithColor(i + 1, 4);
            Display::DisplayWithColor(". ", 4);
            std::cout << carVector[i] << "\n\n";
        }
        std::cout << "Type 'Exit' if you wish to stop being displayed any cars, 'next' if you wish"
                     " to see the next page of cars and 'back' in order to go the the previous car page.\n\n";
        Display::DisplayWithColor("You are currently viewing page ", 4);
        Display::DisplayWithColor(multiplier, 4);
        Display::DisplayWithColor("/", 4);
        Display::DisplayWithColor(numberOfPages, 4);
        std::cout << "\n\n";

        std::cin >> ch;

        if(ch == "exit" || ch == "Exit")
        {
            break;
        }
        else if(ch == "Next" || ch == "next")
        {
            multiplier++;
            if(multiplier > numberOfPages)
                multiplier = numberOfPages;
        }
        else
        {
            multiplier--;
            if(multiplier < 1)
                multiplier = 1;
        }
        Display::ResetScreen();
    }

    Display::PressAnyKey();
    MainClass::MenuOptions();
}
#endif //CHECHECI_CAR_LEASING_CARFACTORY_H