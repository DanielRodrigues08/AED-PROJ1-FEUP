#include "Treadmill.h"
#include <queue>
#include <list>
#include "Suitcase.h"
#include "TransportCart.h"
#include <algorithm>
#include "Flight.h"

using namespace std;

unsigned  Treadmill::idAux = 1;

Treadmill::Treadmill() {
    id = idAux;
    id++;
}

void Treadmill::addTransportCart(TransportCar c1) {
    cars.push_back(c1);
}

void Treadmill::addSuitcase(CheckedSuitcase c1){
    bool check = true;
    for(auto it: suitcasesContainers){
        if(it.top().getFlight() == c1.getFlight()) {
            it.push(c1);
            check = false;
            break;
        }
    }
    if(check){
        stack<CheckedSuitcase> temp;
        temp.push(c1);
        suitcasesContainers.push_back(temp);
    }
}

int Treadmill::getNumCarsAvailable() const{
    unsigned counter = 0;
    for(auto idx: cars){
        if(idx.isAvailable())
            counter++;
    }
    return counter;
}

bool Treadmill::containersEmpty() const {
    for(auto idx: suitcasesContainers){
        if(idx.size()!=0)
            return true;
    }
    return true;
}

bool myFind(const TransportCar& c1){
    return c1.isAvailable();
}

void Treadmill::loadTransportCart() {
    while(!containersEmpty() || getNumCarsAvailable()!=0){
        auto it = find_if(cars.begin(), cars.end(), myFind);
        auto itSuitcases = suitcasesContainers.begin();
        it->loadTransportCart(*itSuitcases);
        if(itSuitcases->size() == 0)
            suitcasesContainers.erase(itSuitcases);
    }
}