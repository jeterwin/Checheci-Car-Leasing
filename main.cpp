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

#include <string>
#include <windows.h>

void UpdatePersonalInformation();

std::string loggedUserName;

Display display;
FileHandler fileHandler;
LoginHandler loginHandler;
CarFactory carFactory;

int main()
{
    display.Logo();

    loginHandler.Login(&loggedUserName);

    std::cout << "Successfully logged in, welcome " << loggedUserName << "!" << std::endl;
    Sleep(2000);

    display.MainPage();
    display.DisplayMainOptions();

    char menuChoice;
    std::cin >> menuChoice;

    switch(menuChoice)
    {
        case '1':
            switch (display.DisplayAccountPanel())
            {
                case '1':
                    carFactory.DisplayRentedCars(loggedUserName);
                    break;
                case '2':
                    carFactory.DisplayLoanedCars(loggedUserName);
                    break;
                case '3':
                    carFactory.DisplaySoldCars(loggedUserName);
                    break;
                case '4':
                    carFactory.UpdateCarListing(loggedUserName);
                    break;
                case '5':
                    UpdatePersonalInformation();
                    break;
                case '6':
                    display.MainPage();
                    break;
                default:
                    display.DisplayError("Invalid menu choice!");
                    display.MainPage();
            }
            break;
        case '2':
            switch(display.DisplayShopInterface())
            {
                case '1':
                    carFactory.DisplayAvailableCars();
                    break;
                case '2':
                    carFactory.DisplayAvailableCars();
                    break;
                case '3':
                    carFactory.DisplayAvailableCars();
                    break;
                case '4':
                    display.MainPage();
                default:
                    display.DisplayError("Invalid menu choice!");
                    display.MainPage();
            }
            break;
        default:
            display.DisplayError("Invalid menu choice!");
            display.MainPage();
            break;
    }
}

void UpdatePersonalInformation()
{

}