//
// Created by Erwin on 5/11/2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <direct.h>
#include<windows.h>


#include "LoginHandler.h"
#include "FileHandler.h"
#include "Display.h"

void LoginHandler::Login(std::string * userName)
{
    FileHandler fileHandler;

    std::fstream usersFile;

    usersFile.open(FileHandler::GetUsersFile(), std::ios::out | std::ios::app);
    usersFile.close();
    usersFile.open(FileHandler::GetUsersFile(), std::ios::in | std::ios::out | std::ios::app);


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
            Display::DisplayWithColor("You provided wrong login arguments!", 5);
            Display::ResetScreen();
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
            Display::DisplayWithColor("You must insert two parameters in the following way:\n", 5);
            Display::DisplayWithColor("<FIRST NAME> <LAST NAME>\n", 5);
            Sleep(2000);
            Display::ResetScreen();
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
        Display::LoginDisplay();

        std::string parameters;
        getline(std::cin, parameters);

        short wordCharLength = parameters.length();

        char* cString = new char[wordCharLength];

        strcpy(cString, parameters.c_str());

        if(strlen(cString) == 0)
        {
            usersFile.close();
            Display::DisplayWithColor("You provided wrong login arguments!", 5);
            Display::DisplayError("");
            Display::ResetScreen();
            Login(userName);
            return;
        }

        char *p = strtok(cString, " ");

        // Check if first word is "login"
        if(strcmp(p, "login") != 0)
        {
            std::cout << "You must input your first and last name as follows:\n";
            Display::DisplayWithColor("login <FIRST NAME> <LAST NAME>", 5);
            Display::DisplayError("");
            Display::ResetScreen();
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
            std::cout << "You must input your first and last name as follows:\n";
            Display::DisplayWithColor("login <FIRST NAME> <LAST NAME>", 5);
            Display::DisplayError("");
            Display::ResetScreen();
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
        Display::DisplayError("There was no user found called " + parameters + ". Try again!\n");
        Display::ResetScreen();
        Login(userName);
        return;
    }
}