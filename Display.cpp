//
// Created by Erwin on 5/11/2024.
//

#include <iostream>
#include <windows.h>
#include "Display.h"
#include "color.hpp"

void Display::ResetScreen()
{
    system("cls");
    fflush(stdin);
}

void Display::Logo()
{
    std::cout << dye::black_on_bright_white("/////////////////////////////////////////") << std::endl;
    std::cout << dye::black_on_white("/////////       Welcome to      /////////") << std::endl;
    std::cout << dye::black_on_bright_white("////// Checheci Leasing Automobile //////") << std::endl;
    std::cout << dye::black_on_white("/////////////////////////////////////////") << std::endl << std::endl << std::endl;
}

void Display::LoginDisplay()
{
    std::cout << "Login using the following parameters:\n";
    std::cout << "login <FIRST NAME> <LAST NAME>\n";
    std::cout << "You must provide both your first and last name in order to login into your account!\n\n";
}

void Display::MainPage()
{
    ResetScreen();

    std::cout << dye::black_on_bright_white("//////////////////////////////////////////\n");
    std::cout << dye::black_on_white("//////     Welcome, dear client!    //////\n");
    std::cout << dye::black_on_bright_white("////  Type the number of the command  ////\n");
    std::cout << dye::black_on_white("/////    That is of most interest!   /////\n");
    std::cout << dye::black_on_bright_white("//////////////////////////////////////////\n\n");

    std::cout << "Please enter a number between 1-3 representing the interface you are interested in accessing.";
    std::cout << std::endl;
    std::cout << dye::light_aqua("1. My account.\n"
                                 "2. Access Shop Interface.\n");
    std::cout << dye::red("3. Exit application.\n\n");
}

void Display::WelcomeProfile()
{
    std::cout <<dye::black_on_bright_white("////////////////////////////////////////////////////\n");
    std::cout << dye::black_on_white("///////////// Welcome to your profile! /////////////\n");
    std::cout << dye::black_on_bright_white("////////////////////////////////////////////////////\n\n");
}

char Display::DisplayAccountPanel()
{
    ResetScreen();

    Display::WelcomeProfile();

    std::cout << "Please enter a number between 1-6 representing the interface you are interested in accessing.";
    std::cout << std::endl << std::endl;

    std::cout << dye::light_aqua("1. View rented cars.\n"
                                 "2. View leased cars.\n"
                                 "3. View sold cars.\n"
                                 "4. Create, view or update car listings.\n"
                                 "5. Go back.\n\n");

    char menuChoice;
    std::cin >> menuChoice;

    return menuChoice;
}

void Display::DisplayError(const std::string& errorMessage)
{
    std::cout << errorMessage << std::endl;
    Sleep(3000);
}

char Display::DisplayShopInterface()
{
    ResetScreen();

    Display::WelcomeProfile();

    std::cout << "Please enter a number between 1-6 representing the interface you are interested in accessing.";
    std::cout << std::endl << std::endl;

    std::cout << dye::light_aqua("1. Display all available cars.\n"
                                 "2. Display cars for rent.\n"
                                 "3. Display cars for lease.\n"
                                 "4. Search for a car.\n"
                                 "5. Go back.\n\n");

    char menuChoice;
    std::cin >> menuChoice;

    return menuChoice;
}

void Display::PrintBodyTypes()
{
    std::cout << "0. SUV\n";
    std::cout << "1. Coupe\n";
    std::cout << "2. Compact\n";
    std::cout << "3. Convertible\n";
    std::cout << "4. Wagon\n";
    std::cout << "5. Sedan\n";
    std::cout << "6. Van\n";
    std::cout << "7. Transporter\n";
}

void Display::PrintFuelTypes()
{
    std::cout << "0. Diesel\n";
    std::cout << "1. Electric\n";
    std::cout << "2. Hybrid\n";
    std::cout << "3. Gasoline\n";
    std::cout << "4. LPG\n";
}

void Display::PrintTransmissionTypes()
{
    std::cout << "0. Automatic\n";
    std::cout << "1. Manual\n";
}

void Display::PrintDrivetrains()
{
    std::cout << "0. AWD\n";
    std::cout << "1. 4WD\n";
    std::cout << "2. RWD\n";
    std::cout << "3. FWD\n";
}

void Display::PressAnyKey()
{
    system("pause");
}

void Display::DisplayWithColor(int string, int colorCode)
{
    switch(colorCode)
    {
        case 1:
            std::cout << dye::aqua(string);
            break;
        case 2:
            std::cout << dye::green(string);
            break;
        case 3:
            std::cout << dye::yellow(string);
            break;
        case 4:
            std::cout << dye::light_aqua(string);
            break;
        case 5:
            std::cout << dye::red(string);
            break;
        case 6:
            std::cout << dye::black_on_bright_white(string);
            break;
        case 7:
            std::cout << dye::black_on_white(string);
            break;
        default:
            std::cout << dye::green(string);
            break;
    }
}

void Display::DisplayWithColor(std::string string, int colorCode)
{
    switch(colorCode)
    {
        case 1:
            std::cout << dye::aqua(string);
            break;
        case 2:
            std::cout << dye::green(string);
            break;
        case 3:
            std::cout << dye::yellow(string);
            break;
        case 4:
            std::cout << dye::light_aqua(string);
            break;
        case 5:
            std::cout << dye::red(string);
            break;
        case 6:
            std::cout << dye::black_on_bright_white(string);
            break;
        case 7:
            std::cout << dye::black_on_white(string);
            break;
        default:
            std::cout << dye::green(string);
            break;
    }
}
