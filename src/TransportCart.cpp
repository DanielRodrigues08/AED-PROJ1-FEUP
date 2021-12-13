#include "TransportCart.h"
#include <queue>
#include <list>

TransportCar::TransportCar(unsigned int numCarriages, unsigned int maxNumSuitcases, unsigned int maxNumStacks) {
    for(unsigned i = 0; i < numCarriages; i++){
        carriages.push_back(Carriage(maxNumSuitcases,maxNumStacks));
    }
}

void TransportCar::setFlight(int flight) {
    this->flight = flight;
}

bool TransportCar::loadTransportCart(queue<CheckedSuitcase> &luggage) {
    for(auto idx: carriages){
        idx.loadSuitcases(luggage);
    }
    if(luggage.size() != 0)
        return false;
    return true;
}

list<CheckedSuitcase> TransportCar::unloadTransportCart() {
    list<CheckedSuitcase> result;
    for(auto idx: carriages)
        result.merge(idx.unloadCarriage());
    return result;
}