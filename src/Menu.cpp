//
// Created by pedro on 01/12/2021.
//


#include "Input.h"
#include "Input.cpp"
#include "Passenger.cpp"
#include "Flight.cpp"

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
        case 3: return new FlightMenu(false);
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


    passengers.push_back(new Passenger(userid,birth_date,name));
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
    std::cout << "[" << option++ << "] Cancel Flight" << std::endl;
    std::cout << "[" << option++ << "] Tickets" << std::endl;
    std::cout << "[" << option++ << "] Check-In" << std::endl;


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
            case 2: return new CancelMenu(passenger);
            case 3: return new TicketsMenu(passenger);
            case 4: return new CheckInMenu();
        }
    }
    return invalidOption();
}


// --------------- Cancel Menu ---------------
CancelMenu::CancelMenu(Passenger * passenger) : Menu(),passenger(passenger) {}
void CancelMenu::show() {
    system("cls");

    cout << "Which ticket do you desire to cancel? [TICKET ID]" << endl;
}

Menu * CancelMenu::getNextMenu() {
    int ticketID;
    if(!input::get(ticketID)){
        return invalidOption();
    }

    if(passenger->getTicket(ticketID)== nullptr){
        return invalidOption();
    }

    passenger->getTicket(ticketID)->show();


    cout << "\n PRESS [1] If you wish to cancel your ticket " << endl;
    cout << "PRESS [0] TO GO TO PREVIOUS MENU" << endl;

    int option;
    if(!input::get(option))
        return invalidOption();
    if(option == 0){
        return nullptr;
    }
    else if(option == 1){
        passenger->cancelTicket(ticketID);
        input::waitEnter();
        return nullptr;
    }


    return invalidOption();
}


// ---------------  Flight Menu ---------------
FlightMenu::FlightMenu(Passenger* passenger)  : Menu(),passenger(passenger){}

FlightMenu::FlightMenu(bool loggedIn) : Menu(),loggedIn(loggedIn){}


void FlightMenu::show() {
    system("cls");
    string origin, destination;

    cout << "Input your desired destination and origin" << endl;
    cout << "To return press 0" << endl;

}
Menu * FlightMenu::getNextMenu() {
    //ask your passenger where he wants to go
    string origin, destination;
    cout << "From: "; origin = input::getRaw();

    if(!input::validateFlight(origin)){
        return invalidOption();
    }

    cout << "To: "; destination = input::getRaw();
    if(!input::validateFlight(destination)){
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
            input::waitEnter();
            return this;
        }
    }
    if(loggedIn){
        return new BuyMenu(passenger);
    }
    return nullptr;
}

// --------------- Buy Menu ---------------
BuyMenu::BuyMenu(Passenger* passenger): Menu(),passenger(passenger){}
void BuyMenu::show() {}

Menu * BuyMenu::getNextMenu() {

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
        string userid,birth_date, name,classe;

        cout << "(" << i << "/" << numOfTickets << ")" << endl;
        cout << " ===========================================" << endl;

        cout << "ID number\n ";
        if(!input::get(userid) || !input::validateID(userid)){
            return invalidOption();
        }
        cout << "Name\n "; name = input::getRaw();
        if(!input::validateName(name)){
            return invalidOption();
        }
        cout << "birth date\n ";
        if(!input::get(birth_date) || !input::validateBirthDate(birth_date)){
            return invalidOption();
        }

        cout << "Class\n ";  classe = input::getRaw();
        if(!input::validateClass(classe)){
            return invalidOption();
        }

        if(passenger->canBuyTicket()){
            passengers.push_back(new Passenger(userid,birth_date,name));
            passenger->buyTicket();
        }
        else{
            cout << "Unfortunately is was not possible to buy your ticket" << endl;
            return this;
        }
    }
    cout << "THE PROCESS IS COMPLETE" << endl;
    input::waitEnter();
    return new TicketsMenu(passenger);
}

// --------------- Transports Menu ---------------
TransportsMenu::TransportsMenu(): Menu() {}
void TransportsMenu::show() {
    system("cls");

}

Menu * TransportsMenu::getNextMenu() {

    input::waitEnter();
    return nullptr;
}

// ---------------  Ticket Menu ---------------
TicketsMenu ::TicketsMenu (Passenger* passenger):Menu(), passenger(passenger) {}
void TicketsMenu ::show() {
    system("cls");

}

Menu * TicketsMenu ::getNextMenu() {

    return nullptr;
}

// --------------- Check-in Menu ---------------

CheckInMenu ::CheckInMenu():Menu() {}
void CheckInMenu ::show() {
    system("cls");

}
Menu * CheckInMenu::getNextMenu() {

    return nullptr;
}