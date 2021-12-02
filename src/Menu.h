//
// Created by pedro on 01/12/2021.
//

#ifndef AED_PROJ1_MENU_H
#define AED_PROJ1_MENU_H

#include <iostream>
#include <map>
#include <functional>

#define CLR_SCREEN "\033[2J\033[1;1H"
#define BLUE "\u001b[36m"
#define RED "\u001b[31m"
#define GREEN "\u001b[32m"
#define RESET "\u001b[0m"

namespace screen{
    const unsigned WIDTH = 40;
    const unsigned HEIGHT = 10;
    const std::string image[10][40] = {{RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET},
                                       {RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET},
                                       {RESET, RESET, GREEN,  GREEN , GREEN , GREEN , RESET, RESET, GREEN,  GREEN,  GREEN , GREEN , GREEN , RESET, RESET, GREEN , GREEN,  GREEN , GREEN,  RESET, RESET, RESET, GREEN , GREEN , GREEN , GREEN , RESET, RESET, RESET, GREEN , GREEN , RESET, RESET, RESET, GREEN , RESET, RESET, RESET, GREEN, RESET},
                                       {RESET, RESET, GREEN,  RESET, RESET, RESET, RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, RESET, RESET, RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, RESET, GREEN , GREEN,  RESET, GREEN , GREEN, RESET},
                                       {RESET, RESET, GREEN , RESET, RESET, RESET, RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, GREEN , RESET, RESET, GREEN,  RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, GREEN, RESET, GREEN, RESET},
                                       {RESET, RESET, GREEN,  GREEN,  GREEN,  GREEN,  RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, GREEN , GREEN , GREEN , RESET, RESET, RESET, RESET, GREEN , GREEN , GREEN , GREEN , RESET, RESET, GREEN , GREEN , GREEN , GREEN , RESET, RESET, GREEN , RESET, RESET, RESET, GREEN, RESET},
                                       {RESET, RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, GREEN , RESET, GREEN , RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, RESET, RESET, GREEN, RESET},
                                       {RESET, RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, GREEN , RESET, RESET ,GREEN , RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, RESET, RESET, GREEN, RESET},
                                       {RESET, RESET, GREEN,  GREEN,  GREEN,  GREEN , RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, RESET, GREEN , RESET, RESET, RESET, GREEN , RESET, RESET, GREEN , GREEN , GREEN , GREEN , RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, RESET, GREEN , RESET, RESET, RESET, GREEN, RESET},
                                       {RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET, RESET}};
    void showScreenLine(const std::string &code);
    void showScreen();
}


class Menu{
protected:
    std::vector<Passenger *> clients;
    Menu * invalidOption();
public:
    explicit Menu();
    virtual ~Menu() = default;
    /**
     * Show information associated with the menu
     */
    virtual void show() = 0;
    /**
     * Return a pointer to the next menu ('nullptr' and 'this' can also be returned)
     * nullptr -> Return to previous menu
     * this -> Don't change the menu
     * @return Menu * to next menu
     */
    virtual Menu * getNextMenu() = 0;
};

class MainMenu : public Menu {
public:
    explicit MainMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class LoginPassengerMenu : public Menu{
    bool logged_in = false;
public:
    explicit LoginPassengerMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class BookingMenu : public Menu{
    Passenger * passenger;
public:
    BookingMenu(Passenger * passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class PlaneMenu : public Menu{
    std::vector<Plane *> availablePlanes;
public:
    PlaneMenu();
    void show() override;
    Menu * getNextMenu() override;
};






#endif //AED_PROJ1_MENU_H
