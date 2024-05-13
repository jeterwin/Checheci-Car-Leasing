//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_CAR_H
#define CHECHECI_CAR_LEASING_CAR_H

#include <string>

enum FuelType
{
    Diesel = 0,
    Electric,
    Hybrid,
    Gasoline
};

enum TransmissionType
{
    Automatic = 0,
    Manual
};

enum ChassisType
{
    Suv = 0,
    Coupe,
    Sports,
};

class Car
{
    protected:
        int horsePower;
        int carPrice;
        int productionYear;
        int kmsDriven;
        int motorSize;

        FuelType fuelType;
        TransmissionType transmissionType;

    std::string color = "White";
    std::string brand;
    std::string model;
    std::string carName;

    public:
        Car();
        Car(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
            enum FuelType, enum TransmissionType, std::string color, std::string brand, std::string model, std::string carName);
        int GetHP();
};


#endif //CHECHECI_CAR_LEASING_CAR_H
