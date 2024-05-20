//
// Created by Erwin on 5/11/2024.
//

#ifndef CHECHECI_CAR_LEASING_FILEHANDLER_H
#define CHECHECI_CAR_LEASING_FILEHANDLER_H

#include <fstream>
#include <string>

class FileHandler {
protected:


public:
    static std::string GetUsersFile();

    static std::string GetRentedCarsFileName();
    static std::string GetLeasedCarsFileName();

    static std::string GetAvailableCarsFileName();
    static std::string GetAvailableRentingCars();
    static std::string GetAvailableLeasingCars();

    static std::string GetSoldCars();

    bool is_empty(std::fstream& pFile) const;
};


#endif //CHECHECI_CAR_LEASING_FILEHANDLER_H