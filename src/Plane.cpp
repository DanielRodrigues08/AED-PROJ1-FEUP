#include <list>
#include "Flight.h"
#include "Suitcase.h"
#include "Plane.h"



Plane::Plane(unsigned int numSeatsFirst, unsigned int numSeatsExecutive, unsigned int numSeatsEconomic, string plate,string model) {
    this->numSeatsFirst = numSeatsFirst;
    this->numSeatsExecutive = numSeatsExecutive;
    this->numSeatsEconomic = numSeatsEconomic;
    this->plate = plate;
    this->model = model;
}

unsigned Plane::getNumSeats() const {
    return numSeatsEconomic  + numSeatsExecutive + numSeatsFirst;
}

unsigned Plane::getNumSeatsFirst() const {
    return numSeatsFirst;
}

unsigned Plane::getNumSeatsExecutive() const {
    return numSeatsExecutive;
}

unsigned Plane::getNumSeatsEconomic() const {
    return numSeatsEconomic;
}

void Plane::changeNumSeatsFirst(unsigned int num) {
    numSeatsFirst = num;
}

void Plane::changeNumSeatsExecutive(unsigned int num) {
    numSeatsExecutive = num;
}

void Plane::changeNumSeatsEconomic(unsigned int num) {
    numSeatsEconomic = num;
}

void Plane::changePlate(string plate) {
    this->plate = plate;
}

void Plane::addGroupSuitcaseCargo(list<CheckedSuitcase> c1) {
    cargoHold.merge(c1);
}

void Plane::addSuitcaseCargo(CheckedSuitcase c1) {
    cargoHold.push_back(c1);
}

void Plane::addFlight(Flight *f1) {
    flightPlan.push_back(f1);
}

bool Plane::removeFlight(unsigned id) {
    for(auto it = flightPlan.begin(); it != flightPlan.end(); it++){
        if((*it)->getIdFlight() == id) {
            flightPlan.erase(it);
            return true;
        }
    }
    return false;
}

list<CheckedSuitcase> Plane::unloadSuitcases(){
    list<CheckedSuitcase> temp = cargoHold;
    cargoHold.clear();
    return temp;
}