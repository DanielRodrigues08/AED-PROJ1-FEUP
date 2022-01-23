#include "Treadmill.h"
#include <queue>
#include <list>
#include "Suitcase.h"
#include "TransportCar.h"
#include <algorithm>
#include "Flight.h"

using namespace std;

list<stack<CheckedSuitcase>> Treadmill::suitcasesContainers;
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
        if(it.size()==0)
            continue;
        if(it.top().getFlight().getIdFlight() == c1.getFlight().getIdFlight()) {
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

void Treadmill::loadTransportPlane(const unsigned& idFlight, Plane* plane) {
    for(auto itSuits = suitcasesContainers.begin(); itSuits != suitcasesContainers.end(); itSuits++){
        if(idFlight == itSuits->top().getFlight().getIdFlight()){
            while (!itSuits->empty()) {
                auto it = find_if(cars.begin(), cars.end(), myFind);
                it->loadTransportCart(*itSuits);
                plane->addGroupSuitcaseCargo(it->unloadTransportCart());
            }
        }
    }
}


unsigned Treadmill::numTransportCars() const {
    return cars.size();
}

vector<TransportCar>* Treadmill::getCars(){
    return &cars;
}

void Treadmill::showCars() const {
    cout << "ID\tAvailable\tFlight\tNumCarriages" << endl;
    for(auto idx: cars){
        if(idx.isAvailable())
            cout << id << '\t' << "Yes" << "\t\t"  << "X\t" << idx.getNumCarriages() << endl;
        else
            cout << id << '\t' << "No" << "\t\t"  << idx.getFlightID()<<"\t"<< idx.getNumCarriages()<<endl;
    }
}