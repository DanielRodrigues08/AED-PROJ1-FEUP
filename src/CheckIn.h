#ifndef AED_PROJ1_CHECKIN_H
#define AED_PROJ1_CHECKIN_H

#include "Treadmill.h"
#include "Suitcase.h"
#include "Flight.h"
#include "Ticket.h"
#include <list>

class CheckIn {
    static unsigned idAux;
    unsigned id;
    Treadmill treadmill;
public:
    CheckIn(Treadmill treadmill);
    float checkInPassenger(Passenger passenger, Ticket ticket);
};


#endif //AED_PROJ1_CHECKIN_H
