//
// Created by pedro on 14/12/2021.
//
#include "Flight.h"

#ifndef AED_PROJ1_TICKET_H
#define AED_PROJ1_TICKET_H
using namespace std;

enum Type { economic, business, first };

class Ticket {
    Type type;
    static int TicketID;
    string seat;
    int maxLuggage;
    Flight flight;

public:
    Ticket(Type type,string seat, Flight flight);
    void show();
    int getTicketID();
};


#endif //AED_PROJ1_TICKET_H
