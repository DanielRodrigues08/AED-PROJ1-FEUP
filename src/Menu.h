//
// Created by pedro on 01/12/2021.
//

#ifndef AED_PROJ1_MENU_H
#define AED_PROJ1_MENU_H

#include <iostream>
#include <map>
#include <functional>
#include "passenger.h"
#include "Airplane.h"
#include <Windows.h>


using namespace std;

class Menu{
protected:
    static vector<Passenger*> passengers;
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

class RegisterPassengerMenu : public Menu{
public:
    explicit RegisterPassengerMenu();
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
    explicit BookingMenu(Passenger * passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class FlightMenu : public Menu{

    vector < vector<Flight>* > flights;
    Passenger * passenger;
public:
    FlightMenu(Passenger* passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class TransportsMenu : public Menu{


public:
    FlightMenu(Passenger* passenger);
    void show() override;
    Menu * getNextMenu() override;
};



#endif //AED_PROJ1_MENU_H
