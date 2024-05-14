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
        static std::string GetRentedCars();
        static std::string GetLeasedCars();
        static std::string GetAvailableCars();

        bool is_empty(std::fstream& pFile) const;
};


#endif //CHECHECI_CAR_LEASING_FILEHANDLER_H
