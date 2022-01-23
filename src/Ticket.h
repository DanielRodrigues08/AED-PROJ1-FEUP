//
// Created by pedro on 14/12/2021.
//
#include "Flight.h"

#ifndef AED_PROJ1_TICKET_H
#define AED_PROJ1_TICKET_H
using namespace std;
/**
 * To check in and get into a plane o you'll need a ticket
 *
 * a ticket holds the information to your seat, maximum luggage, the flight you'll be boarding and even in which class you'll be travelling
 */
enum TypeTicket {first,executive, economic };

class Ticket {
    TypeTicket type;
    static int TicketIDAux;
    int TicketID;
    string seat;
    int maxLuggage;
    Flight flight;

public:
    /**
     * main constructor, populates every attribute and increments the id;
     * @param type
     * @param seat
     * @param flight
     */
    Ticket(TypeTicket type,string seat, Flight flight);
    Ticket(int id): TicketID(id){};
    /**
     * shows every single attribute
     */
    void show();
    int getTicketID();
    int getMaxLuggage();
    string getSeat();
    TypeTicket getTypeTicket() ;
    unsigned getFlightID() ;
    Flight getFlight() ;
    bool operator==(const Ticket& t1) const;
};


#endif //AED_PROJ1_TICKET_H
