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
        void DisplayMainOptions();

        char DisplayAccountPanel();
        char DisplayShopInterface();

        void ResetScreen();
        void DisplayError(const std::string& errorMessage);
};


#endif //CHECHECI_CAR_LEASING_DISPLAY_H
