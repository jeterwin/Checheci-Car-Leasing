//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_RENTINGCAR_H
#define CHECHECI_CAR_LEASING_RENTINGCAR_H

#include "Car.h"
#include <string>

class RentingCar : public Car {

    protected:
        int rentingPrice;
        int rentingPeriod; // In days

    public:
        void print();
        RentingCar();
        ~RentingCar() = default;
        RentingCar(int rentingPrice, int rentingPeriod, std::string make, std::string model, int carPrice, enum BodyType, std::string color,
                int productionYear, std::string VIN, int kmsDriven, enum FuelType,
                enum TransmissionType, enum Drivetrain, int motorSize, int horsePower);
        void writeToFile();

        std::string getStatus();
};


#endif //CHECHECI_CAR_LEASING_RENTINGCAR_H
