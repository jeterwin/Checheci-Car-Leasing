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

std::string FileHandler::GetAvailableCarsFileName()
{
    return "Files/AvailableCars.txt";
}

std::string FileHandler::GetLeasedCarsFileName()
{
    return "Files/LeasedCars.txt";
}

std::string FileHandler::GetRentedCarsFileName()
{
    return "Files/RentedCars.txt";
}

std::string FileHandler::GetSoldCars()
{
    return "Files/SoldCars.txt";
}

std::string FileHandler::GetAvailableRentingCars() {
    return "Files/RentingCars.txt";
}

std::string FileHandler::GetAvailableLeasingCars() {
    return "Files/LeasingCars.txt";
}
