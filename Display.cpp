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
    std::cout << "/////////////////////////////////////////" << std::endl;
    std::cout << "/////////       Welcome to      /////////" << std::endl;
    std::cout << "//////" << dye::aqua(" Checheci Leasing Automobile ") << "//////" << std::endl;
    std::cout << "/////////////////////////////////////////" << std::endl << std::endl << std::endl;
}

void Display::LoginDisplay()
{
    std::cout << "Login using the following parameters:" << std::endl;
    std::cout << "login <FIRST NAME> <LAST NAME>" << std::endl;
    std::cout << "You must provide both your first and last name in order to login into your account!" << std::endl << std::endl;
}

void Display::MainPage()
{
    ResetScreen();

    std::cout << dye::yellow("//////////////////////////////////////////") << std::endl;
    std::cout << dye::yellow("//////     Welcome, dear client!    //////") << std::endl;
    std::cout << dye::yellow("////  Type the number of the command  ////") << std::endl;
    std::cout << dye::yellow("/////    That is of most interest!   /////") << std::endl;
    std::cout << dye::yellow("//////////////////////////////////////////") << std::endl << std::endl;
}

void Display::DisplayMainOptions()
{
    std::cout << "Please enter a number between 1-3 representing the interface you are interested in accessing.";
    std::cout << std::endl;
    std::cout << dye::aqua("1. My account.") << std::endl;
    std::cout << dye::aqua("2. Access Shop Interface.") << std::endl;
    std:: cout << dye::red("3. Exit application.") << std::endl << std::endl;
}

char Display::DisplayAccountPanel()
{
    ResetScreen();

    std::cout << dye::yellow("////////////////////////////////////////////////////") << std::endl;
    std::cout << dye::yellow("///////////// Welcome to your profile! /////////////") << std::endl;
    std::cout << dye::yellow("////////////////////////////////////////////////////") << std::endl << std::endl;

    std::cout << "Please enter a number between 1-6 representing the interface you are interested in accessing.";
    std::cout << std::endl << std::endl;

    std::cout << dye::aqua("1. View rented cars.\n"
            "2. View loaned cars.\n"
            "3. View cars for sale.\n"
            "4. View sold cars.\n"
            "5. Update or create car listing.\n"
            "6. Update personal information.\n"
            "7. Go back.") << std::endl << std::endl;

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

    std::cout << "////////////////////////////////////////////////////" << std::endl;
    std::cout << "///////////// Welcome to your profile! /////////////" << std::endl;
    std::cout << "////////////////////////////////////////////////////" << std::endl << std::endl;

    std::cout << "Please enter a number between 1-6 representing the interface you are interested in accessing.";
    std::cout << std::endl << std::endl;

    std::cout << "1. Display all available cars.\n"
                 "2. Display cars for rent.\n"
                 "3. Display cars for lease.\n"
                 "4. Go back.\n" << std::endl << std::endl;

    char menuChoice;
    std::cin >> menuChoice;

    return menuChoice;
}