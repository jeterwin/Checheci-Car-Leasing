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
        RentingCar();
        ~RentingCar() = default;
        RentingCar(int horsePower, int carPrice, int productionYear, int kmsDriven, int motorSize,
        enum FuelType fuelType, enum TransmissionType transmissionType, std::string color, std::string brand,
                   std::string model, std::string carName, int rentingPrice, int rentingPeriod);
};


#endif //CHECHECI_CAR_LEASING_RENTINGCAR_H
