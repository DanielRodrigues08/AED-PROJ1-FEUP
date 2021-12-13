#ifndef AED_PROJ1_TRANSPORTCART_H
#define AED_PROJ1_TRANSPORTCART_H

#include <queue>
#include <list>

#include "Carriage.h"
#include "Flight"

class TransportCar{
    list<Carriage> carriages;
    Flight flight;
public:
    TransportCar(unsigned numCarriages, unsigned maxNumSuitcases, unsigned maxNumStacks);
    void setFlight(Flight flight);
    bool loadTransportCart(queue<CheckedSuitcase>& luggage);
    list<CheckedSuitcase> unloadTransportCart();
};

#endif //AED_PROJ1_TRANSPORTCART_H
