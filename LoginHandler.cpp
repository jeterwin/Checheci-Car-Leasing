//
// Created by Erwin on 5/11/2024.
//

#include "LoginHandler.h"
#include <cstring>
#include <iostream>
#include <string>

int Login(std::string * userName)
{
    std::string parameters;
    getline(std::cin, parameters);

    short wordCharLength = parameters.length();

    char* cString = new char[wordCharLength];

    strcpy(cString, parameters.c_str());

    if(strlen(cString) == 0) { return 1; }

    char *p = strtok(cString, " ");

    // Error
    // Check if first word is "login"
    if(strcmp(p, "login") != 0) { return 1; }

    int wordsInName = 0;

    while(p)
    {
        wordsInName++;
        p = strtok(NULL, " ");
    }

    // Error
    if(wordsInName != 3) { return 1; }

    *userName = parameters.substr(6, wordCharLength);
    return 0;
}