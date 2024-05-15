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

enum BodyType
{
    Suv = 0,
    Coupe,
    Sports,
};

enum Drivetrain
{
    AWD = 0,
    FourWD,
    RWD,
    FWD,
};

std::string stringFuelType(enum FuelType x);
std::string stringTransmissionType(enum TransmissionType x);
std::string stringBodyType(enum BodyType x);
std::string stringDrivetrain(enum Drivetrain x);

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
        BodyType bodyType;
        Drivetrain drivetrain;

        std::string VIN;
        std::string color = "White";
        std::string make;
        std::string model;

    public:
        Car();
        Car(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
            enum FuelType, enum TransmissionType, enum BodyType, enum Drivetrain, std::string VIN, std::string color, std::string make, std::string model);
        int GetHP();
        friend std::ostream& operator<< (std::ostream& os, const Car&);
        virtual std::string getStatus();
};


#endif //CHECHECI_CAR_LEASING_CAR_H
