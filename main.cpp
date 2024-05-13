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
        case 1:
            switch(DisplayAccountPanel())
            {
                case 1:
                    DisplayRentedCars();
                case 2:
                    DisplayLoanedCars();
                case 3:
                    DisplaySoldCars();
                case 4:
                    UpdateCarListing();
                case 6:
                    UpdatePersonalInformation();
                case 7:
                    MainPage();
                default:
                    std::cout << "Error";
            }
        case 2:
            switch(DisplayShopInterface())
            {
                case 1:

                case 2:

                default:
                    std::cout << "Error";
            }
        default:
            std::cout << "Error";
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