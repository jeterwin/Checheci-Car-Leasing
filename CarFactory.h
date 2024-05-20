//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_CARFACTORY_H
#define CHECHECI_CAR_LEASING_CARFACTORY_H

#include <map>
#include <vector>

#include "LeasingCar.h"
#include "RentingCar.h"
#include "Display.h"
#include "main.h"


class CarFactory {

protected:
    Car * availableCars[1000];
    Car * givenCars[1000];

    int availableCarsNr;
    int givenCarsNr;

public:
    CarFactory();
    CarFactory(Car * leasingCar);

    void SearchForCar(std::vector<Car>, std::string personName);
    static void DeleteCarFromFile(std::string fileName, int lineToBeDeleted);

    template<class T>
    void DisplayCarsForRentOrLease(std::vector<T>);

    template<class T>
    void DisplayRentedOrLeasedCars(std::vector<T>);

    void DisplayAvailableCars(std::vector<Car>);
    void DisplaySoldCars(std::vector<Car>);

    void UpdateCarListing(std::string carOwner);

    void AddCar(int addingChoice, std::vector<Car>& carVectorToBeAdded);
};

template<class T>
void CarFactory::DisplayRentedOrLeasedCars(std::vector<T> carVector)
{
    Display::ResetScreen();
    // We need to initialize two strings in order to compare it to the user we're logged in
    int displayedCarsPerPage = 5, multiplier = 1, i = 0, counter = 1;
    std::string ch;

    std::cout << "These are all the cars you have ";
    strcmp(typeid(carVector).name(), "class std::vector<class RentingCar,class std::allocator<class RentingCar> >") == 0 ? std::cout << "rented " : std::cout << "leased ";
    std::cout << "so far\n";
    Display::DisplayWithColor("----------------------------------------------\n\n", 2);

    while(1 == 1)
    {
        for(i = 0; i < multiplier * displayedCarsPerPage; i++)
        {
            // Then we found our car
            if(i > carVector.size()) { break; }
            std::cout << counter << ". " << carVector[i] << "\n\n";
/*            if(carVector[i].GetCarOwnerName() == MainClass::GetUsername())
            {
                std::cout << counter << ". " << carVector[i] << "\n\n";
                counter++;
            }*/
        }
        std::cout << "Type 'Exit' if you wish to stop being displayed any cars.\n\n";
        std::cin >> ch;
        if(ch == "exit" || ch == "Exit")
        {
            break;
        }
        else if(ch == "Next" || ch == "next")
        {
            multiplier++;
        }
        else
        {
            multiplier--;
            if(multiplier < 1)
                multiplier = 1;
        }
    }

    Display::PressAnyKey();
    MainClass::MenuOptions();
}

template<class T>
void CarFactory::DisplayCarsForRentOrLease(std::vector<T> carVector)
{
    Display::ResetScreen();
    std::string ch;
    int displayedCarsPerPage = 5, multiplier = 1, i = 0;

    // Option = 0 => renting cars, Option = 1 => leasing cars
    std::cout << "These are all the cars that can be ";

    std::strcmp(typeid(carVector).name(), "class std::vector<class RentingCar,class std::allocator<class RentingCar> >") == 0 ?
    std::cout << "rented " : std::cout << "leased ";
    std::cout << "from Checheci Leasing Automobile\n\n";

    Display::DisplayWithColor("----------------------------------------------\n\n", 2);

    while(1 == 1)
    {
        std::cout << ch;
        for(i = 0; i < multiplier * displayedCarsPerPage; i++)
        {
            // Then we ok
            if(i < carVector.size())
            {
                std::cout << i + 1 << ". " << carVector[i] << "\n\n";
            }
        }
        std::cout << "Type 'Exit' if you wish to stop being displayed any cars.\n\n";
        std::cin >> ch;
        if(ch == "exit" || ch == "Exit")
        {
            break;
        }
        else if(ch == "Next" || ch == "next")
        {
            multiplier++;
        }
        else
        {
             multiplier--;
             if(multiplier < 1)
                 multiplier = 1;
        }
    }

    Display::PressAnyKey();
    MainClass::MenuOptions();
}
#endif //CHECHECI_CAR_LEASING_CARFACTORY_H