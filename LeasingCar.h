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
        LeasingCar(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
               enum FuelType fuelType, enum TransmissionType transmissionType, enum BodyType bodyType,
                       enum Drivetrain drivetrain, std::string VIN, std::string color,
               std::string make, std::string model, int leasingPrice, int leasingPeriod);
        void print();
        std::string getStatus();

};


#endif //CHECHECI_CAR_LEASING_LEASINGCAR_H
