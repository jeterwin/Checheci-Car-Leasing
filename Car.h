//
// Created by Erwin on 5/19/2024.
//

#ifndef CHECHECI_CAR_LEASING_CAR_H
#define CHECHECI_CAR_LEASING_CAR_H

#include <string>
#include <sstream>
#include <vector>

enum FuelType
{
    Diesel = 0,
    Electric,
    Hybrid,
    Gasoline,
    LPG // GPL ( Gaz petrolier lichefiat )
};

enum TransmissionType
{
    Automatic = 0,
    Manual
};

enum BodyType
{
    SUV = 0,
    Coupe,
    Compact,
    Convertible,
    Wagon,
    Sedan,
    Van,
    Transporter,
};

enum Drivetrain
{
    AWD = 0,
    FourWD,
    RWD,
    FWD,
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
    BodyType bodyType;
    Drivetrain drivetrain;

    std::string VIN;
    std::string color = "White";
    std::string make;
    std::string model;
    std::string carOwner;

public:

    virtual std::string getMake();
    virtual std::string getModel();
    virtual
    int getPrice();

    Car();
    Car(std::string carOwner, std::string make, std::string model, int carPrice, enum BodyType, std::string color,
        int productionYear, std::string VIN, int kmsDriven, enum FuelType,
        enum TransmissionType, enum Drivetrain, int motorSize, int horsePower);




    friend std::ostream& operator<< (std::ostream& os, const Car&);
    friend std::fstream& operator<< (std::fstream& os, const Car&);


    virtual std::string ObjectToString();

    virtual std::string getStatus();

    virtual void writeToFile(std::string filename);
    virtual void deleteFromFile();


    static void ValidateChoiceBodyType(int &userChoice, int userTries=0);
    static void ValidateChoiceFuelType(int &userChoice, int userTries=0);
    static void ValidateChoiceTransmissionType(int &userChoice, int userTries=0);
    static void ValidateChoiceDrivetrain(int &userChoice, int userTries=0);

    virtual std::string GetCarOwnerName();
    static std::string stringFuelType(enum FuelType x);
    static std::string stringTransmissionType(enum TransmissionType x);
    static std::string stringBodyType(enum BodyType x);
    static std::string stringDrivetrain(enum Drivetrain x);


    static int stringToIntTransmissionType(const std::string& transmissionType);
    static int stringToIntFuelType(const std::string& fuelType);
    static int stringToIntBodyType(const std::string& bodyType);
    static int stringToIntDrivetrain(const std::string& drivetrain);


    static void searchCars(std::string filename, std::vector<Car> cars, const std::string& make,
                           const std::string& model, const std::string& color, const std::string& transmissionType,
                           const std::string& fuelType, const std::string& drivetrainType, int maxKilometers, int motorSize,
                           int horsePower, int maxPrice, int minYear);

    static void displayCars(std::vector<Car> cars, const std::string& make,
                            const std::string& model, const std::string& color, const std::string& transmissionType,
                            const std::string& fuelType, const std::string& drivetrainType, int maxKilometers, int motorSize,
                            int horsePower, int maxPrice, int minYear);


    static int FindCarIndexInFile(const std::vector<Car>& cars, const std::string &make, const std::string &model,
                                  const std::string &color, const std::string& transmissionType, const std::string& fuelType,
                                  const std::string& drivetrainType, int maxKilometers, int motorSize, int horsePower, int maxPrice,
                                  int minYear);

    friend std::vector<Car> UpdateAvailableCars();
};

#endif //CHECHECI_CAR_LEASING_CAR_H