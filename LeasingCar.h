//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_LEASINGCAR_H
#define CHECHECI_CAR_LEASING_LEASINGCAR_H

#include "Car.h"
#include <string>

class LeasingCar : public Car {

    protected:
        int leasingPrice;
        int leasingPeriod; // In days

    public:
        LeasingCar();
        ~LeasingCar() = default;
        LeasingCar(int leasingPrice, int leasingPeriod);
        LeasingCar(int leasingPrice, int leasingPeriod, std::string make, std::string model, int carPrice, enum BodyType, std::string color,
               int productionYear, std::string VIN, int kmsDriven, enum FuelType,
               enum TransmissionType, enum Drivetrain, int motorSize, int horsePower);
        void print();
        std::string getStatus();
        void writeToFile();

};


#endif //CHECHECI_CAR_LEASING_LEASINGCAR_H
