
//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

#include "CarFactory.h"
#include "RentingCar.h"
#include "LeasingCar.h"
#include "Car.h"
#include "LoginHandler.h"
#include "Display.h"
#include "FileHandler.h"
#include "main.h"

void UpdatePersonalInformation();

std::string loggedUserName;

static Display display;
static FileHandler fileHandler;
static LoginHandler loginHandler;
static CarFactory carFactory;
static MainClass mainClass;

std::vector<Car> userAvailableCars;
std::vector<RentingCar> userRentingCars;
std::vector<LeasingCar> userLeasingCars;

void MenuOptions();

int main()
{
    display.Logo();

    loginHandler.Login(&loggedUserName);
    userAvailableCars = Car::readCarsFromFile(FileHandler::GetAvailableCars(),"debug marian");
    for(int i = 0; i < userAvailableCars.size(); i++)
        std::cout << userAvailableCars[i] << "\n\n\n";

    std::cout << "Successfully logged in, welcome " << loggedUserName << "!" << std::endl;
    std::cout << "DEBUG" << " LOGGED USER: " << loggedUserName << "\n";
    CarFactory debugCarFactory{};

    int choice;
    std::cin >> choice;
    switch (choice)
    {
        case 1: {

            std::string make, model, color, VIN;
            int carPrice, choiceBody = -1, kmsDriven, choiceFuel = -1, choiceTransmission=-1, choiceDrivetrain=-1,
            productionYear, motorSize, horsePower;
            // -1 IF USER RUNS OUT OF TRIES WHEN MAKING A CHOICE
            BodyType bodyType;
            FuelType fuelType;
            TransmissionType transmissionType;
            Drivetrain drivetrain;
            std::cin.clear();
            std::cin.sync();

            std::cout << "ADD CAR TO AVAILABLE CARS\n";

            std::cout << "What's the name of the car's make?: ";
            std::getline(std::cin, make);

            std::cout << "\nWhat's the name of the car's model?: ";
            std::getline(std::cin, model);

            std::cout << "\nFor how much does your car sell?: ";
            std::cin >> carPrice;

            std::cout << "\nPick the body type that matches your car:\n";
            Car::PrintBodyTypes();
            Car::ValidateChoiceBodyType(choiceBody);
            if (choiceBody == -1) {
                std::cout << "YOU RAN OUT OF TRIES!!!!!";
                // RETURN; IN FUNCTION OR SMTH
            } else {
                bodyType = static_cast<BodyType>(choiceBody);
                std::cout << "You chose: " << Car::stringBodyType(bodyType) << "\n";
            }

            std::cout << "\nWhat's the color of your car?: ";
            std::getline(std::cin >> std::ws, color);

            std::cout << "\nWhen was your car produced?: ";
            std::cin >> productionYear;

            //TODO: FUNCTION THAT CHECKS IF USER'S INPUT VIN IS ALREADY IN USE
            std::cout << "\nWhat's your Vehicle Identification Number (VIN) ?: ";
            std::getline(std::cin >> std::ws, VIN);

            std::cout << "\nWhat's your car mileage (kilometers)?: ";
            std::cin >> kmsDriven;

            std::cout << "\nPick the fuel type that matches your car:\n";
            Car::PrintFuelTypes();
            Car::ValidateChoiceFuelType(choiceFuel);
            if (choiceFuel == -1) {
                std::cout << "YOU RAN OUT OF TRIES!!!!!";
                // RETURN; IN FUNCTION OR SMTH
            } else {
                fuelType = static_cast<FuelType>(choiceFuel);
                std::cout << "You chose: " << Car::stringFuelType(fuelType) << "\n";
            }

            std::cout << "\nPick the transmission type that matches your car:\n";
            Car::PrintTransmissionTypes();
            Car::ValidateChoiceTransmissionType(choiceTransmission);
            if (choiceTransmission == -1) {
                std::cout << "YOU RAN OUT OF TRIES!!!!!";
                // RETURN; IN FUNCTION OR SMTH
            } else {
                transmissionType = static_cast<TransmissionType>(choiceTransmission);
                std::cout << "You chose: " << Car::stringTransmissionType(transmissionType) << "\n";
            }

            std::cout << "\nPick the drivetrain that matches your car:\n";
            Car::PrintDrivetrains();
            Car::ValidateChoiceDrivetrain(choiceDrivetrain);
            if (choiceDrivetrain == -1) {
                std::cout << "YOU RAN OUT OF TRIES!!!!!";
                // RETURN; IN FUNCTION OR SMTH
            } else {
                drivetrain = static_cast<Drivetrain>(choiceDrivetrain);
                std::cout << "You chose: " << Car::stringDrivetrain(drivetrain) << "\n";
            }

            std::cout << "\nWhat's your car's engine size?: ";
            std::cin >> motorSize;

            std::cout << "\nWhat's your car's horsepower?: ";
            std::cin >> horsePower;


            std::cout << "\nUSER ENTRIES:\n";
            std::cout << make << "\n" << model << "\n" << carPrice << "\n" << Car::stringBodyType(bodyType)
                      << "\n" << color << "\n" << productionYear << "\n" << VIN << "\n" << kmsDriven << "\n"
                      << Car::stringFuelType(fuelType) << "\n" << Car::stringTransmissionType(transmissionType) << "\n"
                      << Car::stringDrivetrain(drivetrain) << "\n" << motorSize << "\n" << horsePower;

            Car x{make, model, carPrice, bodyType, color, productionYear, VIN, kmsDriven, fuelType, transmissionType,
                  drivetrain, motorSize, horsePower};
            x.writeToFile(FileHandler::GetAvailableCars(), loggedUserName);
            //add it to the vector
            userAvailableCars.push_back(x);
            break;
        }

        case 2: {
            std::cout << "\nADD ONE OF USER'S CAR TO RENTING\n";
//            std::vector<Car> cars=Car::readCarsFromFile(FileHandler::GetAvailableCars());
//            for(int i=0;i<cars.size();i++)
//                std::cout<<"\n\n\n"<<"CAR: "<<i<<"\n"<<cars[i]<< "\n\n\n";

        }

    }


//    Sleep(2000);

//    mainClass.MenuOptions();
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

std::string MainClass::GetUsername()
{
    // Make sure it isn't null or something lmao
    return loggedUserName;
}
