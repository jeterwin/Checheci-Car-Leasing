//
// Created by Erwin on 5/10/2024.
//

#ifndef CHECHECI_CAR_LEASING_LEASINGCAR_H
#define CHECHECI_CAR_LEASING_LEASINGCAR_H

#include "Car.h"

class LeasingCar : public Car {

    protected:
        int leasingPrice;
        int leasingPeriod; // In days

    public:
        LeasingCar();
        ~LeasingCar() = default;
        LeasingCar(int leasingPrice, int leasingPeriod);

};


#endif //CHECHECI_CAR_LEASING_LEASINGCAR_H
