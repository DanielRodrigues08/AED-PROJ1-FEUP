//
// Created by pedro on 01/12/2021.
//
#pragma once
#include "Menu.h"
#include "Input.h"
#include "Input.cpp"
#include "passenger.h"
#include "passenger.cpp"
#include "Populate.h"
#include "Populate.cpp"
#include <Windows.h>


using namespace std;

vector<Passenger*> Menu::passengers = {};
Menu::Menu() {
}

Menu * Menu::invalidOption() {
    std::cout << "Invalid option" << std::endl;
    input::waitEnter();
    return this;
}
// --------------- Main Menu ---------------
MainMenu::MainMenu():Menu(){}

void MainMenu::show() {
    unsigned int options = 0;

    system("cmd /c cls");
    std::cout << "Main Menu:\n\n";
    std::cout << "[" << ++options << "] " << "Passenger Login\n";
    std::cout << "[" << ++options << "] " << "Passenger Register\n";
    std::cout << "[" << ++options << "] " << "Admin Login\n";
    std::cout << "[" << ++options << "] " << "Show Flights\n";
    std::cout << "[" << ++options << "] " << "Show Transports\n";
    std::cout << "[0] Exit\n";
}


Menu * MainMenu::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }
    switch(option){
        case 0: return nullptr;
        case 1: return new LoginPassengerMenu();
        case 2: return new RegisterPassengerMenu();
    }
    return invalidOption();
}

// --------------- Register Passenger Menu ---------------
RegisterPassengerMenu::RegisterPassengerMenu() : Menu() {}
void RegisterPassengerMenu::show() {
    system("cls");
    cout << "Information required: ID number, name, birthdate\n";
}
Menu * RegisterPassengerMenu::getNextMenu() {

    string userid,birth_date, name;

    cout << "ID number\n ";
    if(!input::get(userid) || !input::validateID(userid)){
        return invalidOption();
    }
    cout << "name\n "; name = input::getRaw();
    if(!input::validateName(name)){
        return invalidOption();
    }
    cout << "birth date\n ";
    if(!input::get(birth_date) || !input::validateBirthDate(birth_date)){
        return invalidOption();
    }

    Passenger p1(userid,birth_date,name);
    passengers.push_back(&p1);
    cout << " \n You've registered with success" << endl;
    input::waitEnter();
    return nullptr;
}

// --------------- Passenger Login Menu ---------------
LoginPassengerMenu::LoginPassengerMenu() : Menu() {}
void LoginPassengerMenu::show() {
    system("cmd /c cls");
    if(!logged_in){
        cout << "Please login to experience the full potential of our program \n \n " << endl;
    }
    else
        cout << "You're already logged in \n \n Go ahead and enjoy our program" << endl;
}
Menu * LoginPassengerMenu::getNextMenu() {

    if(!logged_in){
        //check for the existence of said passenger
        bool passengerExists = false;
        if(!passengerExists){
            cout << "ID number ";
            string idNumber;
            if(!input::get(idNumber)) {
                return invalidOption();
            }

            cout << passengers.size();
            for(Passenger* passenger: passengers){
                cout << passenger->getID() << endl;
                if(passenger->getID() == idNumber){
                    cout << "CONGRATS YOU'RE NOW LOGGED IN " << endl;
                    input::waitEnter();
                    return new BookingMenu(passenger);
                }
            }
            cout << "Id number " << idNumber << " does not exist in our database" << std::endl;
            input::waitEnter();
        }
    }

    return nullptr;
}

// --------------- Booking Menu ---------------
BookingMenu::BookingMenu(Passenger * passenger) : passenger(passenger) {}
void BookingMenu::show() {
    system("cls");
    unsigned int option = 1;

    std::cout << "[" << option++ << "] Book Flight" << std::endl;
    //std::cout << "[" << option++ << "] Book a Plane" << std::endl;
    std::cout << "[" << option++ << "] Cancel Flight" << std::endl;

    std::cout << "[0] Exit" << std::endl;
}
Menu * BookingMenu::getNextMenu() {
    int option;
    if(!input::get(option))
        return invalidOption();
    if(option == 0){
        return nullptr;
    }

    else{
        unsigned int id, pos;
        switch(option){
            case 1: return new FlightMenu(passenger);
            //case 2 in STAN-BY still thinking what is the best option 1-Create a menu 2-Create a method in plane
            //case 2: passenger.; return this;
            //should i create ANOTHER menu??
            case 3: passenger->cancelFlight(); return this;
        }
    }
    return invalidOption();
}

// --------------- Show Flight Menu ---------------
FlightMenu::FlightMenu(Passenger* passenger)  : passenger(passenger)  {
    populate::populateFlights(flights);
}

void FlightMenu::show() {
    system("cls");
    string origin, destination;

    cout << "Input your desired destination and origin" << endl;
    cout << "To return press 0" << endl;

}
Menu * FlightMenu::getNextMenu() {
    //ask your passenger where he wants to go
    int option;
    string origin, destination;
    cout << "From: "; origin = input::getRaw();
    if(!input::validateName(origin)){
        return invalidOption();
    }
    cout << "To: "; destination = input::getRaw();
    if(!input::validateName(destination)){
        return invalidOption();
    }
    input::waitEnter();
    for(auto q : flights) {
        if(q->at(0).getOrigin() ==  origin && q->at(0).getDestination()==destination){
            system("cls");
            cout << "number" << "From" << "To" << "Departure Date" << "Duration" << endl;
            for (Flight flight: *q) {
                cout << flight.getNumber() << flight.getOrigin() << flight.getDestination() << flight.getDepartureDate() << flight.getDuration() << endl;
            }
        }
        else{
            cout << "Sorry, at the moment we don't have flights for your desired location" << endl;
            return this;
        }
    }

    int desiredFlightNumber,numOfTickets;
    cout << "Flight Number: ";
    if(!input::get(desiredFlightNumber)){
        return invalidOption();
    }

    cout << "Number of tickets: ";
    if(!input::get(numOfTickets)){
        return invalidOption();
    }

    for(int i=1;i <= numOfTickets; i++){
        system("cls");
        string userid,birth_date, name;
        cout << "(" << i << "/" << numOfTickets << ")" << endl;
        cout << " ===========================================" << endl;

        cout << "ID number\n ";
        if(!input::get(userid) || !input::validateID(userid)){
            return invalidOption();
        }
        cout << "name\n "; name = input::getRaw();
        if(!input::validateName(name)){
            return invalidOption();
        }
        cout << "birth date\n ";
        if(!input::get(birth_date) || !input::validateBirthDate(birth_date)){
            return invalidOption();
        }

        passenger->buyTicket();
    }


    return nullptr;
}

// --------------- Show Transports Menu ---------------

