#include "TransportCart.h"
#include <queue>
#include <list>

unsigned TransportCar::idAux = 1;

TransportCar::TransportCar(unsigned int numCarriages, unsigned int maxNumSuitcases, unsigned int maxNumStacks) {
    available = true;
    for(unsigned i = 0; i < numCarriages; i++){
        carriages.push_back(Carriage(maxNumSuitcases,maxNumStacks));
    }
    id = idAux;
    idAux++;
}

void TransportCar::setFlight(int flight) {
    this->flight = flight;
}

bool TransportCar::loadTransportCart(stack<CheckedSuitcase> &luggage) {
    available = false;
    for(auto idx: carriages){
        idx.loadSuitcases(luggage);
    }
    if(luggage.size() != 0)
        return false;
    return true;
}

list<CheckedSuitcase> TransportCar::unloadTransportCart() {
    available = true;
    list<CheckedSuitcase> result;
    for(auto idx: carriages)
        result.merge(idx.unloadCarriage());
    return result;
}

bool TransportCar::isAvailable() const {
    return available;
}