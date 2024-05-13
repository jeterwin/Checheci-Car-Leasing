//
// Created by Erwin on 5/11/2024.
//

#ifndef CHECHECI_CAR_LEASING_FILEHANDLER_H
#define CHECHECI_CAR_LEASING_FILEHANDLER_H

#include <fstream>


class FileHandler {
    protected:
        std::string

    public:
        std::ofstream OpenWriteFile(const std::string&);
        std::ifstream OpenReadFile(const std::string&);

};


#endif //CHECHECI_CAR_LEASING_FILEHANDLER_H
