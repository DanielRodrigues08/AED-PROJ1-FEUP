 //
// Created by pedro on 14/12/2021.
//

#include "Ticket.h"

int Ticket::TicketIDAux = 0;

int Ticket::getTicketID() {
    return TicketID;
}

void Ticket::show() {
    cout << "[ID] " << TicketID << endl;
    if(type == first){
        cout << "[Type] First" << endl;
    }else if(type == executive){
        cout << "[Type] Executive" << type << endl;
    }
    else{
        cout << "[Type] Economic" << type << endl;
    }
    cout << "[Seat] " << seat << endl;
    cout << "[Max Luggage] " << maxLuggage << "Kg" << endl;
    cout << "[Flight ID] " << flight.getIdFlight() << endl;
    cout << "[Origin]" << flight.getOrigin().getStr() << endl;
    cout << "[Destination] " << flight.getDestination().getStr() << endl;
    cout << "[Date] "<< flight.getDepartureDate() << " " << flight.getDepartureTime() << endl;
    cout << "[Duration] " << flight.getDuration()<< endl;
}

TypeTicket Ticket::getTypeTicket(){
    return type;
}

unsigned Ticket::getFlightID() {
    return flight.getIdFlight();
}

Flight Ticket::getFlight(){
    return flight;
}

string Ticket::getSeat(){
    return seat;
}

 Ticket::Ticket(TypeTicket type, string seat, Flight flight):type(type), flight(flight), seat(seat) {
     switch(type){
         case first: maxLuggage = 40;
         case executive: maxLuggage = 15;
         case economic: maxLuggage = 5;
     }

    TicketID=TicketIDAux;
    TicketIDAux++;

 }

 int Ticket::getMaxLuggage() {
     return maxLuggage;
 }

 bool Ticket::operator==(const Ticket &t1) const {
    return t1.TicketID == TicketID;
}
