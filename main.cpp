//
// Created by Erwin on 5/10/2024.
//

#include <iostream>


#include "CarFactory.cpp"
#include "RentingCar.cpp"
#include "LeasingCar.cpp"
#include "Car.cpp"
#include "LoginHandler.cpp"
#include "Display.cpp"

#include <string>
#include <windows.h>

void UpdatePersonalInformation();

std::string loggedUserName;

int main()
{
    Logo();
    LoginDisplay();
    if(Login(&loggedUserName) == 1) { return 1; }

    std::cout << "Successfully logged in, welcome " << loggedUserName << "!" << std::endl;
    Sleep(2000);

    MainPage();
    DisplayMainOptions();

    char menuChoice;
    std::cin >> menuChoice;

    switch(menuChoice)
    {
        case '1':
            switch (DisplayAccountPanel())
            {
                case '1':
                    DisplayRentedCars();
                    break;
                case '2':
                    DisplayLoanedCars();
                    break;
                case '3':
                    DisplaySoldCars();
                    break;
                case '4':
                    UpdateCarListing();
                    break;
                case '6':
                    UpdatePersonalInformation();
                    break;
                default:
                    DisplayError("Bye bye.");
            }
            break;
        case '2':
            switch(DisplayShopInterface())
            {
                case '1':

                break;
                case '2':

                break;
                default:
                    DisplayError("Bye bye.");
                    break;
            }
            break;
        default:
            DisplayError("Bye bye.");
            break;
    }


    // CarFactory carFactory { };

    // RentingCar car{425, 80000, 2010, 200000, 3999, Diesel, Manual, "Black", "Mercedes-Benz", "AMG", "idk", 100, 10};
//    LeasingCar car1{200, 7, 2000, 300, "Dodge Mustang"};;
//
//    carFactory.AddCar(&car);
//    cout << carFactory.GetAvailableCars()[0]->GetHP() << endl;
//    cout << carFactory.GetAvailableCars()[0]->GetHP() << endl;
}

void UpdatePersonalInformation()
{

}