//
// Created by Erwin on 5/11/2024.
//

#include "FileHandler.h"

bool FileHandler::is_empty(std::fstream & pFile) const
{
    return pFile.peek() == std::fstream::traits_type::eof();
}

std::string FileHandler::GetUsersFile()
{
    return "Users.txt";
}

std::string FileHandler::GetAvailableCarsFileName()
{
    return "AvailableCars.txt";
}

std::string FileHandler::GetLeasedCarsFileName()
{
    return "LeasedCars.txt";
}

std::string FileHandler::GetRentedCarsFileName()
{
    return "RentedCars.txt";
}

std::string FileHandler::GetSoldCars()
{
    return "SoldCars.txt";
}

std::string FileHandler::GetAvailableRentingCars() {
    return "RentingCars.txt";
}

std::string FileHandler::GetAvailableLeasingCars() {
    return "LeasingCars.txt";
}
