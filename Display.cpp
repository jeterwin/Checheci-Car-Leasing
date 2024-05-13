//
// Created by Erwin on 5/11/2024.
//

#include <iostream>
#include "Display.h"
#include <windows.h>

void ResetScreen()
{
    system("cls");
    fflush(stdin);
}

void Logo()
{
    std::cout << "/////////////////////////////////////////" << std::endl;
    std::cout << "/////////       Welcome to      /////////" << std::endl;
    std::cout << "////// Checheci Leasing Automobile //////" << std::endl;
    std::cout << "/////////////////////////////////////////" << std::endl << std::endl << std::endl;
}

void LoginDisplay()
{
    std::cout << "Login using the following parameters:" << std::endl;
    std::cout << "login <FIRST NAME> <LAST NAME>" << std::endl;
    std::cout << "You must provide both your first and last name in order to login into your account!" << std::endl << std::endl;
}

void MainPage()
{
    ResetScreen();

    std::cout << "//////////////////////////////////////////" << std::endl;
    std::cout << "//////     Welcome, dear client!    //////" << std::endl;
    std::cout << "////  Type the number of the command  ////" << std::endl;
    std::cout << "/////    That is of most interest!   /////" << std::endl;
    std::cout << "//////////////////////////////////////////" << std::endl << std::endl;
}

void DisplayMainOptions()
{
    std::cout << "Please enter a number between 1-3 representing the interface you are interested in accessing.";
    std::cout << std::endl;
    std::cout << "1. My account." << std::endl;
    std::cout << "2. Access Shop Interface." << std::endl;
    std:: cout << "3. Exit application." << std::endl << std::endl;
}

char DisplayAccountPanel()
{
    ResetScreen();

    std::cout << "////////////////////////////////////////////////////" << std::endl;
    std::cout << "///////////// Welcome to your profile! /////////////" << std::endl;
    std::cout << "////////////////////////////////////////////////////" << std::endl << std::endl;

    std::cout << "Please enter a number between 1-6 representing the interface you are interested in accessing.";
    std::cout << std::endl << std::endl;

    std::cout << "1. View rented cars.\n"
            "2. View loaned cars.\n"
            "3. View cars for sale.\n"
            "4. View sold cars.\n"
            "5. Update or create car listing.\n"
            "6. Update personal information." << std::endl << std::endl;

    char menuChoice;
    std::cin >> menuChoice;

    return menuChoice;
}

void DisplayError(const std::string& errorMessage)
{
    std::cout << "An error has occurred: " + errorMessage << std::endl;
    Sleep(3000);
}

char DisplayShopInterface()
{
    ResetScreen();

    return 0;
}