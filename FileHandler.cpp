//
// Created by Erwin on 5/11/2024.
//

#include "FileHandler.h"

std::ofstream OpenWriteFile(std::string filename)
{
    return std::ofstream(filename);
}

std::ifstream OpenReadFile(std::string filename)
{
    return std::ifstream(filename);
}
