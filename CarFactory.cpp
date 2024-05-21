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

// TODO this function
void CarFactory::DisplaySoldCars(std::vector<Car> cars)
{
    Display::ResetScreen();
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
    Display::DisplayWithColor("----------------------------------------------\n\n", 2);

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

        if(renterFirstName + " " + renterLastName == MainClass::GetUsername())
        {
            while(p)
            {
                if(counter == 4)
                {
                    std::cout << "--> ";
                }
                Display::DisplayWithColor(p, 1);
                std::cout << " ";
                p = strtok(nullptr, " ");
                counter++;
            }
            std::cout << "\n";
        }
    }

    carFile.close();
    Display::PressAnyKey();
    MainClass::MenuOptions();
}

void CarFactory::UpdateExistingListing(std::vector<Car> carVector)
{
    Display::DisplayWithColor("Below will be presented all of the cars that are currently in your"
                              " 'available' category. Please enter the index of the listing which you want to modify.", 6);

    int displayedCarsPerPage = 5, multiplier = 1,i = 0,counter = 0,
            numberOfPages = std::ceil((float)carVector.size() / (float)displayedCarsPerPage), chosenCar;
    std::string ch;

    while(1 == 1)
    {
        for(counter = (multiplier - 1) * displayedCarsPerPage; counter < multiplier * displayedCarsPerPage; i++)
        {
            if(counter >= carVector.size() || i >= carVector.size()) { break; }

            // Then we own the listing created
            if(carVector[i].GetCarOwnerName() == MainClass::GetUsername())
            {
                Display::DisplayWithColor(counter + 1, 4);
                Display::DisplayWithColor(". ", 4);
                std::cout << carVector[i] << "\n\n";
                counter++;
            }
        }
        std::cout << "Type 'next' if you wish to see the next page of cars and 'back' in order "
                     "to go the the previous car page.\n\n";
        Display::DisplayWithColor("You are currently viewing page ", 4);
        Display::DisplayWithColor(multiplier, 4);
        Display::DisplayWithColor("/", 4);
        Display::DisplayWithColor(numberOfPages, 4);
        std::cout << "\n\n";

        std::cin >> ch;
        chosenCar = std::stoi(ch);
        if(ch == "Next" || ch == "next")
        {
            multiplier++;
            if(multiplier > numberOfPages)
                multiplier = numberOfPages;
        }
        else if(ch == "back" || ch == "Back")
        {
            multiplier++;
            if(multiplier > numberOfPages)
                multiplier = numberOfPages;
        }
        else if(chosenCar >= 0 && chosenCar < carVector.size())
        {
            chosenCar -= 1;
            break;
        }
        Display::ResetScreen();
    }

    Display::DisplayWithColor("You have successfully chosen listing number: ", 8);
    Display::DisplayWithColor(chosenCar, 8);
    std::cout << "\n\nNow, type '1' if you wish to make the car available for rent and '2' "
                 "in order to make the car available for leasing.";

    while(ch != "1" && ch != "2")
    {
        Display::ResetScreen();
        Display::DisplayError("Invalid input, you must enter 1 or 2.\n\n");
        std::cout << "\n\nNow, type '1' if you wish to make the car available for rent and '2' "
                     "in order to make the car available for leasing.";
    }

    std::string filename = ch == "1" ? FileHandler::GetRentedCarsFileName() : FileHandler::GetLeasedCarsFileName();
    carVector[chosenCar].deleteFromFile();
    carVector[chosenCar].writeToFile(filename);


    Display::DisplayWithColor("Congratulations! Your car is now available for ", 4);
    Display::DisplayWithColor(ch == "1" ? "renting!\n\n" : "leasing!\n\n", 4);

    Sleep(2000);
    MainClass::MenuOptions();
}

void CarFactory::UpdateCarListing(std::vector<Car> carVector)
{
    Display::ResetScreen();

    std::cout << "Welcome to the car listing update screen!\n";
    std::cout << "Input your desired choice:\n\n";
    Display::DisplayWithColor("1. Create a new listing, will be added in the 'available' category.\n"
                              "2. Move an existing listing into the 'renting' or 'leasing' category.\n"
                              "3. Update the info of an existing available listing.\n"
                              "4. Remove an existing listing from any category.\n"
                              "5. Go back.\n\n", 4);

    char choice;
    std::cin >> choice;

    switch(choice)
    {
        case '1':
            CreateAvailableListing();
            break;
        case '2':
            UpdateExistingListing(carVector);
            break;
        case '3':
            // TODO create this function
            //RemoveExistingListing();
            break;
        case '4':
            RemoveExistingListing();
            break;
        case '5':
            MainClass::MenuOptions();
            break;
        default:
            Display::DisplayError("Invalid menu choice!");
            MainClass::MenuOptions();
    }

    Display::PressAnyKey();
    MainClass::MenuOptions();
}

void CarFactory::DisplayAvailableCars(std::vector<Car> carVector)
{
    Display::ResetScreen();
    int displayedCarsPerPage = 5, multiplier = 1, i = 0,
    numberOfPages = std::ceil((float)carVector.size() / (float)displayedCarsPerPage);;

    std::cout << "These are all the available cars in Checheci Leasing Automobile:\n\n";
    Display::DisplayWithColor("----------------------------------------------\n\n", 2);

    std::string carInformation, ch;
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

void CarFactory::CreateAvailableListing()
{
    Display::ResetScreen();

    std::string make, model, color, VIN;
    int carPrice, choiceBody = -1, kmsDriven, choiceFuel = -1, choiceTransmission = -1, choiceDrivetrain = -1,
            productionYear, motorSize, horsePower;
    // -1 IF USER RUNS OUT OF TRIES WHEN MAKING A CHOICE
    BodyType bodyType;
    FuelType fuelType;
    TransmissionType transmissionType;
    Drivetrain drivetrain;
    //std::cin.clear();
    //std::cin.sync();
    std::cin.ignore();
    std::cout << "What's the name of the car's make?: ";
    std::getline(std::cin, make);

    std::cout << "\nWhat's the name of the car's model?: ";
    std::getline(std::cin, model);

    std::cout << "\nFor how much does your car sell?: ";
    std::cin >> carPrice;

    std::cout << "\nPick the body type that matches your car:\n";
    Display::PrintBodyTypes();
    Car::ValidateChoiceBodyType(choiceBody);
    if (choiceBody == -1)
    {
        std::cout << "YOU RAN OUT OF TRIES!!!!!";
        // RETURN; IN FUNCTION OR SMTH
    }
    else
    {
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

    if (choiceFuel == -1)
    {
        std::cout << "YOU RAN OUT OF TRIES!!!!!";
        // RETURN; IN FUNCTION OR SMTH
    }
    else
    {
        fuelType = static_cast<FuelType>(choiceFuel);
        std::cout << "You chose: " << Car::stringFuelType(fuelType) << "\n";
    }

    std::cout << "\nPick the transmission type that matches your car:\n";
    Display::PrintTransmissionTypes();
    Car::ValidateChoiceTransmissionType(choiceTransmission);

    if (choiceTransmission == -1)
    {
        std::cout << "YOU RAN OUT OF TRIES!!!!!";
        // RETURN; IN FUNCTION OR SMTH
    }
    else
    {
        transmissionType = static_cast<TransmissionType>(choiceTransmission);
        std::cout << "You chose: " << Car::stringTransmissionType(transmissionType) << "\n";
    }

    std::cout << "\nPick the drivetrain that matches your car:\n";
    Display::PrintDrivetrains();
    Car::ValidateChoiceDrivetrain(choiceDrivetrain);

    if (choiceDrivetrain == -1)
    {
        std::cout << "YOU RAN OUT OF TRIES!!!!!";
        // RETURN; IN FUNCTION OR SMTH
    }
    else
    {
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

    Car x{MainClass::GetUsername(), make, model, carPrice, bodyType, color, productionYear, VIN, kmsDriven, fuelType, transmissionType,
          drivetrain, motorSize, horsePower};
    x.writeToFile(FileHandler::GetAvailableCarsFileName());

    // Update the car vector afterward
    MainClass::CallUpdAvailableCars();
}

void CarFactory::RemoveExistingListing()
{

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

void CarFactory::SearchForCar(std::vector<Car> cars)
{
    Display::ResetScreen();

    Display::DisplayWithColor("Welcome to our advanced car search engine!\n", 6);
    Display::DisplayWithColor("You will be asked to provide certain details about "
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

    Car::displayCars(cars, make, model, color, Car::stringTransmissionType(transmissionType),
Car::stringFuelType(fuelType), Car::stringDrivetrain(driveTrain),
kmsDriven, motorSize, horsePower, carPrice, productionYear);
}
