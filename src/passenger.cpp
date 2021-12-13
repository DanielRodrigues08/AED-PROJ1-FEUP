#include "passenger.h"

Passenger::Passenger(string id, string birthdate, string name) {
    this->name=name;
    this->id = id;
    this->birthdate=birthdate;
}

bool Passenger::canBuyTicket() {
    return true;
}

void Passenger::buyTicket() {

}

string Passenger::getID(){
    return id;
}

void Passenger::cancelFlight() {
    cout << "You're flight has been canceled" << endl;
}


