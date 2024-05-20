//
// Created by Erwin on 5/11/2024.
//

#ifndef CHECHECI_CAR_LEASING_DISPLAY_H
#define CHECHECI_CAR_LEASING_DISPLAY_H


class Display {
public:
    void LoginDisplay();
    void Logo();
    void MainPage();
    static void WelcomeProfile();

    char DisplayAccountPanel();
    char DisplayShopInterface();

    void DisplayWithColor(std::string, int colorCode);
    void DisplayWithColor(int, int colorCode);

    static void PrintBodyTypes();
    static void PrintFuelTypes();
    static void PrintTransmissionTypes();
    static void PrintDrivetrains();

    void PressAnyKey();
    void ResetScreen();
    void DisplayError(const std::string& errorMessage);
};


#endif //CHECHECI_CAR_LEASING_DISPLAY_H