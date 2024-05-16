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
    return "Files/Users.txt";
}

std::string FileHandler::GetAvailableCars()
{
    return "Files/AvailableCars.txt";
}

std::string FileHandler::GetLeasedCars()
{
    return "Files/LeasedCars.txt";
}

std::string FileHandler::GetRentedCars()
{
    return "Files/RentedCars.txt";
}

std::string FileHandler::GetSoldCars()
{
    return "Files/SoldCars.txt";
}

std::string FileHandler::GetAvailableRentingCars() {
    return "Files/LeasingCars.txt";
}

std::string FileHandler::GetAvailableLeasingCars() {
    return "Files/RentingCars.txt";
}
