#include "TransportCar.h"
#include <queue>
#include <list>

unsigned TransportCar::idAux = 1;

TransportCar::TransportCar(unsigned int numCarriages, unsigned int maxNumSuitcases, unsigned int maxNumStacks) {
    available = true;
    for(unsigned i = 0; i < numCarriages; i++){
        carriages.push_back(new Carriage(maxNumSuitcases,maxNumStacks));
    }
    id = idAux;
    idAux++;
}



bool TransportCar::loadTransportCart(stack<CheckedSuitcase> &luggage) {
    available = false;
    for(auto idx: carriages){
        if(luggage.size()==0)
            break;
        idx->loadSuitcases(luggage);

    }
    if(luggage.size() != 0)
        return false;
    return true;
}

list<CheckedSuitcase> TransportCar::unloadTransportCart() {
    available = true;
    list<CheckedSuitcase> result;
    for(auto idx: carriages) {
        list<CheckedSuitcase> temp = idx->unloadCarriage();
        result.insert(result.begin(), temp.begin(),temp.end());
    }
    return result;
}

bool TransportCar::isAvailable() const {
    return available;
}

bool TransportCar::operator==(const TransportCar& t1) const {
    return id == t1.id;
}

TransportCar::TransportCar(unsigned int id):id(id) {
}

unsigned TransportCar::getFlightID() const {
    return getFlightID();
}

unsigned TransportCar::getNumCarriages() const {
    return carriages.size();
}