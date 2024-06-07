
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

// Without the logged in user's
std::vector<Car> UsersAvailableCars;
std::vector<Car> AvailableCars;

// Without the logged in user's
std::vector<RentingCar> AvailableRentingCars;
// ONLY CONTAINS THE USER'S RENTING CARS
std::vector<RentingCar> UsersRentingCars;
std::vector<RentingCar> UserRentedCars;

// Without the logged in user's
std::vector<LeasingCar> AvailableLeasingCars;
std::vector<LeasingCar> UsersLeasingCars;
std::vector<LeasingCar> UserLeasedCars;


std::vector<Car> UpdateAvailableCars()
{
    UsersAvailableCars.clear();
    // Renter name, Car owner name, car specs, last 2 data will be renting amount and renting time
    std::vector<Car> cars;
    std::string filename = FileHandler::GetAvailableCarsFileName();;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return cars;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::string token;
        std::istringstream iss(line);
        LeasingCar car;

        std::getline(iss, car.carOwner, ',');

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

        // This is our car
        if(car.carOwner != loggedUserName)
        {
            cars.push_back(car);
        }
        else // Not our car, it is available for the user to borrow
        {
            UsersAvailableCars.push_back(car);
        }
    }

    file.close();
    return cars;
}

std::vector<LeasingCar> UpdateLeasedCars()
{
    // Renter name, Car owner name, car specs, last 2 data will be renting amount and renting time
    std::vector<LeasingCar> cars;
    std::string filename = FileHandler::GetLeasedCarsFileName();;
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

        std::getline(iss, renterName, ',');
        if (renterName == loggedUserName)
        {
            std::getline(iss, car.carOwner, ',');

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

std::vector<LeasingCar> UpdateLeasingCars()
{
    UsersLeasingCars.clear();
    // Renter name, Car owner name, car specs, last 2 data will be renting amount and renting time
    std::vector<LeasingCar> cars;
    std::string filename = FileHandler::GetAvailableLeasingCars();;
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
        std::string token;
        std::istringstream iss(line);
        LeasingCar car;

        std::getline(iss, ownerName, ',');
        car.carOwner = ownerName;

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

        if (ownerName != loggedUserName)
        {
            cars.push_back(car);
        }
        else
        {
            UsersLeasingCars.push_back(car);
        }
    }


    file.close();
    return cars;
}

std::string LeasingCar::GetCarOwnerName()
{
    return this -> carOwner;
}

std::vector<RentingCar> UpdateRentingCars()
{
    UsersRentingCars.clear();
    // Renter name, Car owner name, car specs, last 2 data will be renting amount and renting time
    std::vector<RentingCar> cars;
    std::string filename = FileHandler::GetAvailableRentingCars();
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
        RentingCar car;

        std::getline(iss, ownerName, ',');
        car.carOwner = ownerName;

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


        if (ownerName != loggedUserName)
        {
            cars.push_back(car);
        }
        else
        {
            UsersRentingCars.push_back(car);
        }

    }

    file.close();
    return cars;
}

std::vector<RentingCar> UpdateRentedCars()
{
    // Renter name, Car owner name, car specs, last 2 data will be renting amount and renting time
    std::vector<RentingCar> cars;
    std::string filename = FileHandler::GetRentedCarsFileName();
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
        std::istringstream iss(line);
        std::string token;
        RentingCar car;

        std::getline(iss, renterName, ',');
        if (renterName == loggedUserName)
        {
            std::getline(iss, car.carOwner, ',');

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
    Display::Logo();

    loginHandler.Login(&loggedUserName);

    // Get the cars owned by the logged in user
    AvailableCars = UpdateAvailableCars();
    AvailableRentingCars = UpdateRentingCars();
    AvailableLeasingCars = UpdateLeasingCars();

    UserRentedCars = UpdateRentedCars();
    UserLeasedCars = UpdateLeasedCars();

    Display::DisplayWithColor("Successfully logged in, welcome ", 8);
    Display::DisplayWithColor(loggedUserName, 8);
    Display::DisplayWithColor("!", 8);
    std::cout << std::endl;

    Sleep(2000);
    MainClass::MenuOptions();
}

void MainClass::MenuOptions()
{
    Display::MainPage();

    char menuChoice;
    std::cin >> menuChoice;

    // For updating vectors
    AvailableCars = UpdateAvailableCars();
    AvailableRentingCars = UpdateRentingCars();
    AvailableLeasingCars = UpdateLeasingCars();

    UserRentedCars = UpdateRentedCars();
    UserLeasedCars = UpdateLeasedCars();

    switch(menuChoice)
    {
        case '1':
            switch (display.DisplayAccountPanel())
            {
                case '1':
                    carFactory.DisplayRentedOrLeasedCars(UserRentedCars);
                    break;
                case '2':
                    carFactory.DisplayRentedOrLeasedCars(UserLeasedCars);
                    break;
                case '3':
                    carFactory.UpdateCarListing(UsersAvailableCars);
                    break;
                case '4':
                    MainClass::MenuOptions();
                    break;
                default:
                    Display::DisplayError("Invalid menu choice!");
                    MainClass::MenuOptions();
            }
            break;
        case '2':
            switch(display.DisplayShopInterface())
            {
                case '1':
                    carFactory.DisplayAvailableCars(AvailableCars);
                    break;
                case '2':
                    carFactory.DisplayCarsForRentOrLease(AvailableRentingCars);
                    break;
                case '3':
                    carFactory.DisplayCarsForRentOrLease(AvailableLeasingCars);
                    break;
                case '4':
                    carFactory.SearchForCar(AvailableCars);
                    break;
                case '5':
                    MainClass::MenuOptions();
                default:
                    Display::DisplayError("Invalid menu choice!");
                    MainClass::MenuOptions();
            }
            break;
        default:
            Display::DisplayWithColor("Goodbye and have a nice day!", 4);
            Sleep(2000);
            return;
    }
}

std::string MainClass::GetUsername()
{
    // Make sure it isn't null or something lmao
    return loggedUserName;
}

void MainClass::CallUpdAvailableCars()
{
    AvailableCars = UpdateAvailableCars();
}

void MainClass::CallUpdLeasingCars()
{
    AvailableLeasingCars = UpdateLeasingCars();
}

void MainClass::CallUpdRentingCars()
{
    AvailableRentingCars = UpdateRentingCars();
}

void MainClass::CallUpdLeasedCars()
{
    UserLeasedCars = UpdateLeasedCars();
}

void MainClass::CallUpdRentedCars()
{
    UserRentedCars = UpdateRentedCars();
}

std::vector<Car> MainClass::GetAvailableCars()
{
    return AvailableCars;
}

std::vector<LeasingCar> MainClass::GetLeasingCars()
{
    return AvailableLeasingCars;
}

std::vector<RentingCar> MainClass::GetRentingCars()
{
    return AvailableRentingCars;
}

std::vector<Car> MainClass::GetUsersAvailableCars() {
    return UsersAvailableCars;
}

std::vector<LeasingCar> MainClass::GetUsersLeasingCars() {
    return UsersLeasingCars;
}

std::vector<RentingCar> MainClass::GetUsersRentingCars() {
    return UsersRentingCars;
}
