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
    LeasingCar(std::string carOwner, std::string make, std::string model, int carPrice, enum BodyType bodyType, std::string color,
               int productionYear, std::string VIN, int kmsDriven, enum FuelType fuelType,
               enum TransmissionType transmissionType, enum Drivetrain drivetrain, int motorSize, int horsePower,
               int leasingPrice, int leasingPeriod);

    void deleteFromFile() override;
    void writeToFile(std::string carOwner) override;

    void SearchByModel(std::vector<LeasingCar> *cars, std::string model);

    friend std::ostream& operator<< (std::ostream& os, const LeasingCar&);
    friend std::fstream& operator<< (std::fstream& os, const LeasingCar&);

    std::string getStatus();
    std::string GetCarOwnerName() override;

    friend std::vector<LeasingCar> UpdateLeasingCars();
    friend std::vector<LeasingCar> UpdateLeasedCars();
};


#endif //CHECHECI_CAR_LEASING_LEASINGCAR_H