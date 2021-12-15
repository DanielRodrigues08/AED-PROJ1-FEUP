#ifndef AED_PROJ1_TRANSPORTCART_H
#define AED_PROJ1_TRANSPORTCART_H

#include <queue>
#include <list>

#include "Carriage.h"
#include "Flight"

class TransportCar{
    static unsigned idAux;
    unsigned id;
    list<Carriage> carriages;
    Flight flight;
    bool available;
public:
    TransportCar(unsigned numCarriages, unsigned maxNumSuitcases, unsigned maxNumStacks);
    void setFlight(Flight flight);
    bool loadTransportCart(stack<CheckedSuitcase>& luggage);
    list<CheckedSuitcase> unloadTransportCart();
    bool isAvailable() const;
};

#endif //AED_PROJ1_TRANSPORTCART_H
