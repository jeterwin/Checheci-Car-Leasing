//
// Created by Erwin on 5/11/2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "LoginHandler.h"
#include "FileHandler.h"
#include "Display.h"

void LoginHandler::Login(std::string * userName)
{
    Display display;
    FileHandler fileHandler;

    std::fstream usersFile;
    usersFile.open(FileHandler::GetUsersFile());

    if(fileHandler.is_empty(usersFile))
    {
        // Create new user and set current user as that one
        // after returning the writing point to the start
        usersFile.seekg(0, std::ios::beg);

        std::cout << "It seems as there are no users created in Checheci Leasing Automobile!\n";
        std::cout << "Enter your first and last name below in order to become the first user.\n\n";

        std::string parameters;
        getline(std::cin, parameters);

        short wordCharLength = parameters.length();

        char* cString = new char[wordCharLength];

        strcpy(cString, parameters.c_str());

        if(strlen(cString) == 0)
        {
            usersFile.close();
            display.DisplayError("You provided wrong login arguments!");
            display.ResetScreen();
            Login(userName);
            return;
        }

        char *p = strtok(cString, " ");

        int wordsInName = 0;

        while(p)
        {
            wordsInName++;
            p = strtok(NULL, " ");
        }

        // Error
        if(wordsInName != 2)
        {
            usersFile.close();
            display.DisplayError("You must insert two parameters in the following way:\n"
                                 "<FIRST NAME> <LAST NAME>");
            display.ResetScreen();
            Login(userName);
            return;
        }

        *userName = parameters;
        usersFile << parameters;
        usersFile.close();
        // Continue with the rest
    }
    else
    {
        // If the users file is not empty, let the human login normally
        display.LoginDisplay();

        std::string parameters;
        getline(std::cin, parameters);

        short wordCharLength = parameters.length();

        char* cString = new char[wordCharLength];

        strcpy(cString, parameters.c_str());

        if(strlen(cString) == 0)
        {
            usersFile.close();
            display.DisplayError("You provided wrong login arguments!");
            display.ResetScreen();
            Login(userName);
            return;
        }

        char *p = strtok(cString, " ");

        // Check if first word is "login"
        if(strcmp(p, "login") != 0)
        {
            display.DisplayError("You must input your first and last name as follows:\n"
                                 "login <FIRST NAME> <LAST NAME>\n\n");
            display.ResetScreen();
            Login(userName);
            return;
        }

        int wordsInName = 0;

        while(p)
        {
            wordsInName++;
            p = strtok(NULL, " ");
        }

        // Not in the right format because there are 2 or less words
        if(wordsInName != 3)
        {
            display.DisplayError("You must input your first and last name as follows:\n"
                                 "login <FIRST NAME> <LAST NAME>\n\n");
            display.ResetScreen();
            Login(userName);
            return;
        }
        std::string UserName;
        parameters = parameters.substr(6, parameters.length());
        while(std::getline(usersFile, UserName))
        {
            // We found a user with the same name as parameters given by user
            if(parameters == UserName)
            {
                *userName = parameters;
                return;
            }
        }

        // We did not find such a user
        display.DisplayError("There was no user found called " + parameters + ". Try again!\n");
        display.ResetScreen();
        Login(userName);
        return;
    }
}