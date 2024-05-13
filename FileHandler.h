//
// Created by Erwin on 5/11/2024.
//

#ifndef CHECHECI_CAR_LEASING_FILEHANDLER_H
#define CHECHECI_CAR_LEASING_FILEHANDLER_H

#include <fstream>


class FileHandler {
    private:


    public:
        std::ofstream OpenWriteFile(std::string fileName);
        std::ifstream OpenReadFile(std::string fileName);

};


#endif //CHECHECI_CAR_LEASING_FILEHANDLER_H
