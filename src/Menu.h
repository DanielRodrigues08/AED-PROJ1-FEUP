//
// Created by pedro on 01/12/2021.
//
#ifndef AED_PROJ1_MENU_H
#define AED_PROJ1_MENU_H

#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <set>
#include "Person.h"
#include "Plane.h"
#include <Windows.h>
#include "Input.h"
#include "CheckIn.h"
#include "Treadmill.h"
#include "Populate.h"
#include "Save.h"
#include "BST.h"
#include <algorithm>

using namespace std;
/**
 * a Menu that bases its implementation on a stack
 *
 * Every menu has two methods:
 * show() - responsible for the "view" in the console, provides useful messages to the user or important info in text form
 * getNextMenu() - responsible for the behaviour aspect of the program, receives inputs and return the new path in form of a pointer
 */

class Menu{
protected:
    static set<Passenger*> users;
    static set<Person*> admins;
    static vector<Person*> staff;
    static vector<Location*> locations;
    static vector<Plane*> planes;
    static Treadmill treadmill;
    static CheckIn checkIn;

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

/**
 * Displays all possible paths from login in to partial listings of flights andd transports
 */
class MainMenu : public Menu {
public:
    explicit MainMenu();
    ~MainMenu() override;
    void show() override;
    Menu * getNextMenu() override;
};

class RegisterPassengerMenu : public Menu{
public:
    explicit RegisterPassengerMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class RegisterStaffMenu : public Menu{
public:
    explicit RegisterStaffMenu();
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

class LoginAdminMenu : public Menu{

public:
    explicit LoginAdminMenu();
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

class CancelMenu : public Menu{
    Passenger * passenger;
public:
    explicit CancelMenu(Passenger * passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class FlightMenu : public Menu{

    Passenger * passenger ;
    bool loggedIn;
public:
    FlightMenu(Passenger* passenger);
    FlightMenu(bool loggedIn);
    void show() override;
    Menu * getNextMenu() override;
};


class BuyMenu : public Menu{
    Passenger* passenger;
public:
    BuyMenu(Passenger* passenger);
    void show() override;
    Menu * getNextMenu() override;
};


class TransportsMenu : public Menu{

public:
    TransportsMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class TicketsMenu : public Menu{

    Passenger* passenger;
public:
    TicketsMenu(Passenger* passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class CheckInMenu : public Menu{
    Passenger * passenger;
public:
    CheckInMenu(Passenger * passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class SuitcaseMenu : public Menu{
    Passenger * passenger;
public:
    SuitcaseMenu(Passenger * passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class RegisterSuitcaseMenu : public Menu{
    Passenger * passenger;
public:
    RegisterSuitcaseMenu(Passenger * passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class ShowSuitcasesMenu : public Menu{
    Passenger* passenger;
public:
    ShowSuitcasesMenu(Passenger* passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class DeleteSuitcaseMenu : public Menu{
    Passenger * passenger;
public:
    DeleteSuitcaseMenu(Passenger * passenger);
    void show() override;
    Menu * getNextMenu() override;
};

class UpdateSuitcasesMenu : public Menu{
    Passenger * passenger;
public:
    UpdateSuitcasesMenu(Passenger * passenger);
    void show() override;
    Menu * getNextMenu() override;
};


// ========================== Admin Menu ========================
/**
 * the menu that is shown to the admin with all the CRUD capabilities
 */
class AdminMenu : public Menu{

public:
    AdminMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class AdminFlightMenu : public Menu{

public:
    AdminFlightMenu();
    void show() override;
    Menu * getNextMenu() override;
};


class AdminServiceMenu : public Menu{

public:
    AdminServiceMenu();
    void show() override;
    Menu * getNextMenu() override;
};


class AdminTransportMenu : public Menu{

public:
    AdminTransportMenu();
    void show() override;
    Menu * getNextMenu() override;
};


class CreateFlightMenu : public Menu{

public:
    CreateFlightMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class EditFlightMenu : public Menu{

public:
    EditFlightMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class CancelFlightMenu : public Menu{

public:
    CancelFlightMenu();
    void show() override;
    Menu * getNextMenu() override;
};


class CreateServiceMenu : public Menu{

public:
    CreateServiceMenu();
    void show() override;
    Menu * getNextMenu() override;
};


class CreateStationMenu : public Menu{

public:
    CreateStationMenu();
    void show() override;
    Menu * getNextMenu() override;
};


class CreateTransportMenu : public Menu{

public:
    CreateTransportMenu();
    void show() override;
    Menu * getNextMenu() override;
};


class DeleteTransportMenu : public Menu{

public:
    DeleteTransportMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class CreateScheduleMenu : public Menu{

public:
    CreateScheduleMenu();
    void show() override;
    Menu * getNextMenu() override;
};


class StartFlightMenu : public Menu{

public:
    StartFlightMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class ShowPassengersMenu : public Menu{

public:
    ShowPassengersMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class ShowCargoHold : public Menu{

public:
    ShowCargoHold();
    void show() override;
    Menu * getNextMenu() override;
};

class CreatePlaneMenu : public Menu{
public:
    CreatePlaneMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class DeletePlaneMenu : public Menu{
public:
    DeletePlaneMenu();
    void show() override;
    Menu * getNextMenu() override;
};

class DoServiceMenu: public Menu{
public:
    DoServiceMenu();
    void show() override;
    Menu* getNextMenu() override;
};

class ShowPlanes: public Menu{
public:
    ShowPlanes();
    void show() override;
    Menu* getNextMenu() override;
};

class ShowServiceDone: public Menu{
public:
    ShowServiceDone();
    void show() override;
    Menu* getNextMenu() override;
};

class DeleteStationMenu: public Menu{
public:
    DeleteStationMenu();
    void show() override;
    Menu* getNextMenu() override;
};

class DeleteScheduleMenu: public Menu{
public:
    DeleteScheduleMenu();
    void show() override;
    Menu* getNextMenu() override;
};


class CreateTransportCar: public Menu{
public:
    CreateTransportCar();
    void show() override;
    Menu* getNextMenu() override;
};

class DeleteTransportCar: public Menu{
public:
    DeleteTransportCar();
    void show() override;
    Menu* getNextMenu() override;
};

class ShowTransportCar: public Menu{
public:
    ShowTransportCar();
    void show() override;
    Menu* getNextMenu() override;
};


#endif //AED_PROJ1_MENU_H