//
// Created by pedro on 15/12/2021.
//

#include "Person.h"
#include "Ticket.cpp"

Passenger::Passenger(string id, string birthdate, string name) {
    this->name = name;
    this->id = id;
    this->birthdate=birthdate;
}


void Passenger::buyTicket() {

}

string Passenger::getID(){
    return id;
}

list<Ticket> Passenger::getAllTickets() {
    for (auto i : tickets) {
        i.show();
        cout << "\n   =============================== " << endl;
    }
}


Ticket* Passenger::getTicket(int ticketID) {

    for (auto i : tickets) {
        if (i.getTicketID() == ticketID) {
            return &i;
        }
    }
    return nullptr;

}

void Passenger::cancelTicket(int ticketID) {

    for (auto i : tickets) {
        if (i.getTicketID() == ticketID) {
            tickets.remove(i);
        }
    }

    cout << "You're flight has been successfully canceled" << endl;

}

