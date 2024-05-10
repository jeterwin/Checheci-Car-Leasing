//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_CAR_H
#define CHECHECI_CAR_LEASING_CAR_H

#include <string>

using namespace std;

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

        string color = "White";
        string brand;
        string model;
        string carName;

    public:
        Car();
        Car(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
            enum FuelType, enum TransmissionType, string color, string brand, string model, string carName);
        int GetHP();
};


#endif //CHECHECI_CAR_LEASING_CAR_H
