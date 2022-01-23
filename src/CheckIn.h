#ifndef AED_PROJ1_CHECKIN_H
#define AED_PROJ1_CHECKIN_H

#include "Treadmill.h"
#include "CheckedSuitcase.h"
#include "Suitcase.h"
#include "Person.h"
#include "Flight.h"
#include "Ticket.h"
#include <list>

class CheckIn {
    static unsigned idAux;
    unsigned id;
    Treadmill treadmill;
public:
    /**
     * main constructor - baggage control sistem that allows to take the passenger's cargohold bag to the plain
     * @param treadmill
     */
    CheckIn(Treadmill treadmill);
    /**
     * checks in the passenger
     * @param passenger
     * @param ticket
     * @return
     */
    float checkInPassenger(Passenger* passenger, Ticket ticket);
};


#endif //AED_PROJ1_CHECKIN_H
