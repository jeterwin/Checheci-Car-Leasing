
//
// Created by Erwin on 5/10/2024.
//

#include <iostream>

#include "CarFactory.h"
#include "RentingCar.h"
#include "LeasingCar.h"
#include "Car.h"
#include "LoginHandler.h"
#include "Display.h"
#include "FileHandler.h"
#include "main.h"

#include <string>
#include <vector>
#include <windows.h>

void UpdatePersonalInformation();

std::string loggedUserName;

static Display display;
static FileHandler fileHandler;
static LoginHandler loginHandler;
static CarFactory carFactory;
static MainClass mainClass;

void MenuOptions();

int main()
{
    std::string deleteline;

    std::ifstream fin;
    fin.open("Files/SoldCars.txt");
    //std::ofstream test; wtf?????????

    //std::cin >> deleteline;

    std::string line;
    while(std::getline(fin, line))
    {
        std::cout << line << "\n";
    }
    fin.close();

    //remove("Files/SoldCars.txt");
    //rename("Files/temp.txt","Files/SoldCars.txt");
    while(1 == 1)
    {

    }
    display.Logo();

    loginHandler.Login(&loggedUserName);

    std::cout << "Successfully logged in, welcome " << loggedUserName << "!" << std::endl;
    Sleep(2000);

    mainClass.MenuOptions();
}

void MainClass::MenuOptions()
{
    display.MainPage();

    char menuChoice;
    std::cin >> menuChoice;

    switch(menuChoice)
    {
        case '1':
            switch (display.DisplayAccountPanel())
            {
                case '1':
                    carFactory.DisplayRentedOrLeasedCars(loggedUserName, 0);
                    break;
                case '2':
                    carFactory.DisplayRentedOrLeasedCars(loggedUserName, 1);
                    break;
                case '3':
                    carFactory.DisplaySoldCars(loggedUserName);
                    break;
                case '4':
                    carFactory.UpdateCarListing(loggedUserName);
                    break;
                case '5':
                    mainClass.MenuOptions();
                    break;
                default:
                    display.DisplayError("Invalid menu choice!");
                    mainClass.MenuOptions();
            }
            break;
        case '2':
            switch(display.DisplayShopInterface())
            {
                case '1':
                    carFactory.DisplayAvailableCars(5);
                    break;
                case '2':
                    carFactory.DisplayCarsForRentOrLease(5, 0);
                    break;
                case '3':
                    carFactory.DisplayCarsForRentOrLease(5, 1);
                    break;
                case '4':
                    carFactory.SearchForCar(loggedUserName);
                    break;
                case '5':
                    mainClass.MenuOptions();
                default:
                    display.DisplayError("Invalid menu choice!");
                    mainClass.MenuOptions();
            }
            break;
        default:
            display.DisplayWithColor("Goodbye and have a nice day!", 4);
            display.DisplayError("");
            return;
    }
}
