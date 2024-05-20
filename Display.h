//
// Created by Erwin on 5/11/2024.
//

#ifndef CHECHECI_CAR_LEASING_DISPLAY_H
#define CHECHECI_CAR_LEASING_DISPLAY_H


class Display {
public:
    static void LoginDisplay();
    static void Logo();
    static void MainPage();
    static void WelcomeProfile();

    char DisplayAccountPanel();
    char DisplayShopInterface();

    static void DisplayWithColor(std::string, int colorCode);
    static void DisplayWithColor(int, int colorCode);

    static void PrintBodyTypes();
    static void PrintFuelTypes();
    static void PrintTransmissionTypes();
    static void PrintDrivetrains();

    static void PressAnyKey();
    static void ResetScreen();
    static void DisplayError(const std::string& errorMessage);
};


#endif //CHECHECI_CAR_LEASING_DISPLAY_H