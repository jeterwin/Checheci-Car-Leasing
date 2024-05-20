//
// Created by Erwin on 5/10/2024.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <windows.h>

#include "CarFactory.h"
#include "Display.h"
#include "main.h"
#include "FileHandler.h"

static Display display;
static MainClass mainClass;

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

void CarFactory::DisplayRentedOrLeasedCars(std::vector<Car> carVector, std::string carOwner, int option)
{
    display.ResetScreen();
    // Option 0 = Rented, option 1 = leased
    // We need to initialize two strings in order to compare it to the user we're logged in
    std::string carInfo, renterFirstName = "a", renterLastName = "a";

    // The counter is needed in order to keep track of who rented the car (first and second strings
    // represent the person that rented it)
    int counter = 0;

    std::cout << "These are all the cars you have ";
    option == 0 ? std::cout << "rented " : std::cout << "leased ";
    std::cout << "so far\n";
    display.DisplayWithColor("----------------------------------------------\n\n", 2);

    for(int i = 0; i < carVector.size(); i++)
    {
        counter = 0;

        short wordCharLength = carInfo.length();
        char* cString = new char[wordCharLength];
        strcpy(cString, carInfo.c_str());

        char *p = strtok(cString, " ");
        while(p)
        {
            if(counter == 0)
            {
                renterFirstName = p;
            }
            if(counter == 1)
            {
                renterLastName = p;
            }
            if(counter > 1)
                break;
            p = strtok(nullptr, " ");
            counter++;
        }

        if(renterFirstName + " " + renterLastName == carOwner)
        {
            while(p)
            {
                display.DisplayWithColor(p, 1); std::cout << " ";
                p = strtok(nullptr, " ");
            }

            std::cout << "\n";
        }

    }

    carFile.close();
    display.PressAnyKey();
    mainClass.MenuOptions();
}

// TODO this function
void CarFactory::DisplaySoldCars(std::vector<Car> cars, std::string carOwner)
{
    display.ResetScreen();
    // Option 0 = Rented, option 1 = leased
    // We need to initialize two strings in order to compare it to the user we're logged in
    std::string carInfo, renterFirstName = "a", renterLastName = "a";

    std::ifstream carFile;
    carFile.open(FileHandler::GetSoldCars());
    // The counter is needed in order to keep track of who rented the car (first and second strings
    // represent the person that rented it)
    int counter = 0;

    std::cout << "These are all the cars you have sold so far\n";
    std::cout << "<Owner of the car> <Car information>\n\n";
    display.DisplayWithColor("----------------------------------------------\n\n", 2);

    while(std::getline(carFile, carInfo))
    {
        counter = 0;

        short wordCharLength = carInfo.length();
        char* cString = new char[wordCharLength];
        strcpy(cString, carInfo.c_str());

        char *p = strtok(cString, " ");
        while(p)
        {
            if(counter == 0)
            {
                renterFirstName = p;
            }
            if(counter == 1)
            {
                renterLastName = p;
            }
            if(counter > 1)
                break;
            p = strtok(nullptr, " ");
            counter++;
        }

        if(renterFirstName + " " + renterLastName == carOwner)
        {
            while(p)
            {
                if(counter == 4)
                {
                    std::cout << "--> ";
                }
                display.DisplayWithColor(p, 1);
                std::cout << " ";
                p = strtok(nullptr, " ");
                counter++;
            }
            std::cout << "\n";
        }
    }

    carFile.close();
    display.PressAnyKey();
    mainClass.MenuOptions();
}

void CarFactory::UpdateCarListing(std::string carOwner)
{
    display.ResetScreen();

    display.PressAnyKey();
    mainClass.MenuOptions();
}

void CarFactory::DisplayAvailableCars(std::vector<Car> cars, int displayedCarsPerPage = 5)
{
    display.ResetScreen();
    int maxCarsPerPage = 10;

    std::cout << "These are all the available cars in Checheci Leasing Automobile:\n\n";
    display.DisplayWithColor("----------------------------------------------\n\n", 2);

    std::string carInformation;
    for(int i = 0; i < cars.size(); i++)
    {
        std::cout << cars[i] << "\n";
    }

    display.PressAnyKey();
    mainClass.MenuOptions();
}


void CarFactory::AddCar(int addingChoice, std::vector<Car>& carVectorToBeAdded)
{
    // 0 = Add to available, 1 = Add to rent, 2 = Add to lease
    FileHandler::GetAvailableCarsFileName();
    switch (addingChoice)
    {
        case 1: {
            std::string make, model, color, VIN;
            int carPrice, choiceBody = -1, kmsDriven, choiceFuel = -1, choiceTransmission = -1, choiceDrivetrain = -1,
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
            Display::PrintBodyTypes();
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
            Display::PrintFuelTypes();
            Car::ValidateChoiceFuelType(choiceFuel);
            if (choiceFuel == -1) {
                std::cout << "YOU RAN OUT OF TRIES!!!!!";
                // RETURN; IN FUNCTION OR SMTH
            } else {
                fuelType = static_cast<FuelType>(choiceFuel);
                std::cout << "You chose: " << Car::stringFuelType(fuelType) << "\n";
            }

            std::cout << "\nPick the transmission type that matches your car:\n";
            Display::PrintTransmissionTypes();
            Car::ValidateChoiceTransmissionType(choiceTransmission);
            if (choiceTransmission == -1) {
                std::cout << "YOU RAN OUT OF TRIES!!!!!";
                // RETURN; IN FUNCTION OR SMTH
            } else {
                transmissionType = static_cast<TransmissionType>(choiceTransmission);
                std::cout << "You chose: " << Car::stringTransmissionType(transmissionType) << "\n";
            }

            std::cout << "\nPick the drivetrain that matches your car:\n";
            Display::PrintDrivetrains();
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

            Car x{MainClass::GetUsername(),make, model, carPrice, bodyType, color, productionYear, VIN, kmsDriven, fuelType, transmissionType,
                  drivetrain, motorSize, horsePower};
            x.writeToFile(MainClass::GetUsername());
            //add it to the vector
            carVectorToBeAdded.push_back(x);
            break;
        }

        case 2: {
            std::cout << "\nADD ONE OF USER'S CAR TO RENTING\n";
//            std::vector<Car> cars=Car::readCarsFromFile(FileHandler::GetAvailableCarsFileName());
//            for(int i=0;i<cars.size();i++)
//                std::cout<<"\n\n\n"<<"CAR: "<<i<<"\n"<<cars[i]<< "\n\n\n";

        }
    }
}

void CarFactory::DisplayCarsForRentOrLease(std::vector<Car> carVector, int displayedCars, int option)
{
    display.ResetScreen();
    int maxCarsPerPage = 10;

    // Option = 0 => renting cars, Option = 1 => leasing cars
    std::cout << "These are all the cars that can be ";
    option == 0 ? std::cout << "rented " : std::cout << "leased ";
    std::cout << "from Checheci Leasing Automobile\n\n";

    display.DisplayWithColor("----------------------------------------------\n\n", 2);

    std::string carInformation;
    for(int i = 0; i < carVector.size(); i++)
    {
        std::cout << carVector[i] << "\n";
    }

    display.PressAnyKey();
    mainClass.MenuOptions();
}

void CarFactory::DeleteCarFromFile(std::string fileName, int lineToBeDeleted)
{
    std::ifstream inputFile(fileName);
    if (!inputFile)
    {
        // Error
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    int i = 0;
    while (std::getline(inputFile, line))
    {
        if (i != lineToBeDeleted)
        {
            lines.push_back(line);
        }
        i++;
    }

    inputFile.close();

    std::ofstream outputFile(fileName);
    if (!outputFile)
    {
        std::cerr << "Error opening file for writing: " << fileName << std::endl;
        // Error
        return;
    }

    for (const std::string& l : lines)
    {
        outputFile << l << std::endl;
    }

    outputFile.close();
}

void CarFactory::SearchForCar(std::vector<Car> cars, std::string personName)
{
    display.ResetScreen();

    display.DisplayWithColor("Welcome to our advanced car search engine!\n", 6);
    display.DisplayWithColor("You will be asked to provide certain details about "
                             "the car you are looking for!", 6);
    Sleep(2000);

    int horsePower, carPrice, productionYear, kmsDriven, motorSize;
    FuelType fuelType;
    TransmissionType transmissionType;
    Drivetrain driveTrain;
    std::string VIN, color, make, model;

    // Equivalent to fflush(stdin) from C
    std::cin.ignore();
    std::cout << "What is the make (car brand) of your desired car? (leave blank to not specify)\n";
    std::getline(std::cin, make);

    std::cout << "What is the model of your desired car? (leave blank to not specify)\n";
    std::getline(std::cin, model);

    std::cout << "What is the color of your desired car? (leave blank to not specify)\n";
    std::getline(std::cin, color);

    // We could add a range (cool idea)
    std::cout << "What is the minimum production year of your desired car?\n";
    std::cin >> productionYear;

    // Could add a range too
    std::cout << "What is the horse power of your desired car? (leave blank to not specify)\n";
    std::cin >> horsePower;

    // Should add a range
    std::cout << "What is the motor size (in cc) of your desired car? (leave blank to not specify)\n";
    std::cin >> motorSize;

    std::cout << "What is the transmission type of your desired car? (0 for Automatic, 1 for Manual)  (leave blank to not specify)\n";
    int transmissionInput;

    std::cin >> transmissionInput;
    transmissionType = static_cast<TransmissionType>(transmissionInput);

    std::cout << "What is the fuel type of your desired car? (0 for Diesel, 1 for Electric, 2 for Hybrid, 3 for Gasoline) (leave blank to not specify)\n";
    int fuelInput;

    std::cin >> fuelInput;
    fuelType = static_cast<FuelType>(fuelInput);

    std::cout << "What is the drivetrain type of your desired car? (0 for AWD, 1 for 4WD, 2 for RWD, 3 for FWD) (leave blank to not specify)\n";
    int drivetrainInput;

    std::cin >> drivetrainInput;
    driveTrain = static_cast<Drivetrain>(drivetrainInput);
    // Range
    std::cout << "What is the maximum price of your desired car?\n";
    std::cin >> carPrice;

    // Range
    std::cout << "How many maximum driven kilometers do you wish the car to have? (leave blank to not specify)\n";
    std::cin >> kmsDriven;

    Car::searchCars(cars, make, model, color, Car::stringTransmissionType(transmissionType),
                    Car::stringFuelType(fuelType), Car::stringDrivetrain(driveTrain),
                    kmsDriven, motorSize, horsePower, carPrice, productionYear);
}
