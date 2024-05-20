
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

std::string loggedUserName;

static Display display;
static LoginHandler loginHandler;
static CarFactory carFactory;
static MainClass mainClass;

std::vector<Car> userAvailableCars;
std::vector<RentingCar> userRentingCars;
std::vector<LeasingCar> userLeasingCars;

std::vector<Car> UpdateAvailableCars(const std::string& filename);
std::vector<LeasingCar> UpdateLeasingCars(const std::string& filename);
std::vector<RentingCar> UpdateRentingCars(const std::string& filename);

std::vector<Car> UpdateAvailableCars(const std::string &filename)
{
    std::vector<Car> cars;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return cars;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::string ownerName;
        std::istringstream iss(line);
        std::string token;
        Car car;
        FuelType fuelType;
        BodyType bodyType;
        TransmissionType transmissionType;
        Drivetrain drivetrain;

        std::getline(iss, ownerName, ',');
        if (ownerName == MainClass::GetUsername() ) {
            std::getline(iss, car.make, ',');
            std::getline(iss, car.model, ',');

            std::getline(iss, token, ',');
            car.carPrice = std::stoi(token);

            std::getline(iss, token, ',');
            car.bodyType = static_cast<BodyType>(Car::stringToIntBodyType(token));

            std::getline(iss, car.color, ',');

            std::getline(iss, token, ',');
            car.productionYear = std::stoi(token);

            std::getline(iss, car.VIN, ',');

            std::getline(iss, token, ',');
            car.kmsDriven = std::stoi(token);

            std::getline(iss, token, ',');
            car.fuelType = static_cast<FuelType>(Car::stringToIntFuelType(token));

            std::getline(iss, token, ',');
            car.transmissionType = static_cast<TransmissionType>(Car::stringToIntTransmissionType(token));

            std::getline(iss, token, ',');
            car.drivetrain = static_cast<Drivetrain>(Car::stringToIntDrivetrain(token));

            std::getline(iss, token, ',');
            car.motorSize = std::stoi(token);

            std::getline(iss, token, ',');
            car.horsePower = std::stoi(token);

            cars.push_back(car);
        }
    }

    file.close();
    return cars;
}

std::vector<LeasingCar> UpdateLeasingCars(const std::string &filename)
{
    // Renter name, Car owner name, car specs, last 2 data will be renting amount and renting time
    std::vector<LeasingCar> cars;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return cars;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::string ownerName, renterName;
        std::string token;
        std::istringstream iss(line);
        LeasingCar car;
        FuelType fuelType;
        BodyType bodyType;
        TransmissionType transmissionType;
        Drivetrain drivetrain;

        std::getline(iss, renterName, ',');
        if (renterName == MainClass::GetUsername())
        {
            std::getline(iss, ownerName, ',');

            std::getline(iss, car.make, ',');
            std::getline(iss, car.model, ',');

            std::getline(iss, token, ',');
            car.carPrice = std::stoi(token);

            std::getline(iss, token, ',');
            car.bodyType = static_cast<BodyType>(Car::stringToIntBodyType(token));

            std::getline(iss, car.color, ',');

            std::getline(iss, token, ',');
            car.productionYear = std::stoi(token);

            std::getline(iss, car.VIN, ',');

            std::getline(iss, token, ',');
            car.kmsDriven = std::stoi(token);

            std::getline(iss, token, ',');
            car.fuelType = static_cast<FuelType>(Car::stringToIntFuelType(token));

            std::getline(iss, token, ',');
            car.transmissionType = static_cast<TransmissionType>(Car::stringToIntTransmissionType(token));

            std::getline(iss, token, ',');
            car.drivetrain = static_cast<Drivetrain>(Car::stringToIntDrivetrain(token));

            std::getline(iss, token, ',');
            car.motorSize = std::stoi(token);

            std::getline(iss, token, ',');
            car.horsePower = std::stoi(token);

            std::getline(iss, token, ',');
            car.leasingPeriod = std::stoi(token);

            std::getline(iss, token, ',');
            car.leasingPrice = std::stoi(token);

            cars.push_back(car);
        }
    }

    file.close();
    return cars;
}

std::vector<RentingCar> UpdateRentingCars(const std::string &filename)
{
    // Renter name, Car owner name, car specs, last 2 data will be renting amount and renting time
    std::vector<RentingCar> cars;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return cars;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::string renterName, ownerName;
        std::istringstream iss(line);
        std::string token;
        RentingCar car;
        FuelType fuelType;
        BodyType bodyType;
        TransmissionType transmissionType;
        Drivetrain drivetrain;

        std::getline(iss, renterName, ',');
        if (renterName == MainClass::GetUsername())
        {
            std::getline(iss, ownerName, ',');

            std::getline(iss, car.make, ',');
            std::getline(iss, car.model, ',');

            std::getline(iss, token, ',');
            car.carPrice = std::stoi(token);

            std::getline(iss, token, ',');
            car.bodyType = static_cast<BodyType>(Car::stringToIntBodyType(token));

            std::getline(iss, car.color, ',');

            std::getline(iss, token, ',');
            car.productionYear = std::stoi(token);

            std::getline(iss, car.VIN, ',');

            std::getline(iss, token, ',');
            car.kmsDriven = std::stoi(token);

            std::getline(iss, token, ',');
            car.fuelType = static_cast<FuelType>(Car::stringToIntFuelType(token));

            std::getline(iss, token, ',');
            car.transmissionType = static_cast<TransmissionType>(Car::stringToIntTransmissionType(token));

            std::getline(iss, token, ',');
            car.drivetrain = static_cast<Drivetrain>(Car::stringToIntDrivetrain(token));

            std::getline(iss, token, ',');
            car.motorSize = std::stoi(token);

            std::getline(iss, token, ',');
            car.horsePower = std::stoi(token);

            std::getline(iss, token, ',');
            car.rentingPeriod = std::stoi(token);
            std::getline(iss, token, ',');
            car.rentingPrice = std::stoi(token);

            cars.push_back(car);
        }
    }

    file.close();
    return cars;
}
void MenuOptions();

int main()
{
    display.Logo();

    loginHandler.Login(&loggedUserName);

    // Get the cars owned by the logged in user
    userAvailableCars = UpdateAvailableCars(FileHandler::GetAvailableCarsFileName());
    userRentingCars = UpdateRentingCars(FileHandler::GetAvailableRentingCars());
    userLeasingCars = UpdateLeasingCars(FileHandler::GetAvailableLeasingCars());

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
                    carFactory.SearchForCar(userAvailableCars, loggedUserName);
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
            Sleep(2000);
            return;
    }
}

std::string MainClass::GetUsername()
{
    // Make sure it isn't null or something lmao
    return loggedUserName;
}
