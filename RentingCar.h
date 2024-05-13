//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_RENTINGCAR_H
#define CHECHECI_CAR_LEASING_RENTINGCAR_H

#include "Car.h"

class RentingCar : public Car {

    protected:
        int rentingPrice;
        int rentingPeriod; // In days

    public:
        void print();
        RentingCar();
        ~RentingCar() = default;
        RentingCar(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
                   enum FuelType fuelType, enum TransmissionType transmissionType, enum BodyType bodyType, enum Drivetrain drivetrain, std::string VIN, std::string color,
                           std::string make, std::string model, int rentingPrice, int rentingPeriod);
        std::string getStatus();
};


#endif //CHECHECI_CAR_LEASING_RENTINGCAR_H
