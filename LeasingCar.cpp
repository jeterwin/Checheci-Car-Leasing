//
// Created by Erwin on 5/10/2024.
//

#include "LeasingCar.h"

LeasingCar::LeasingCar()
{
    leasingPeriod = 0;
    leasingPrice = 0;
}

LeasingCar::LeasingCar(int leasingPrice, int leasingPeriod)
{
    this -> leasingPeriod = leasingPeriod;
    this -> leasingPrice = leasingPrice;
}