#ifndef AED_PROJ1_TRANSPORTCAR_H
#define AED_PROJ1_TRANSPORTCAR_H

#include <queue>
#include <list>

#include "Carriage.h"
#include "Flight.h"
#include "CheckedSuitcase.h"

class TransportCar{
    static unsigned idAux;
    unsigned id;
    list<Carriage*> carriages;
    Flight flight;
    bool available;
public:
    TransportCar(unsigned numCarriages, unsigned maxNumSuitcases, unsigned maxNumStacks);
    TransportCar(unsigned id);
    bool loadTransportCart(stack<CheckedSuitcase>& luggage);
    list<CheckedSuitcase> unloadTransportCart();
    bool isAvailable() const;
    bool operator==(const TransportCar& t1) const;
    unsigned getFlightID() const;
    unsigned getNumCarriages() const;

};

#endif //AED_PROJ1_TRANSPORTCAR_H
