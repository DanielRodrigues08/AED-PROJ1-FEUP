#include "Treadmill.h"
#include <queue>
#include <list>
#include "Suitcase.h"
#include "TransportCart.h"
#include "Flight.h"


unsigned  Treadmill::idAux = 1;

Treadmill::Treadmill() {
    id = idAux;
    id++;
}

void Treadmill::addTransportCart(TransportCar c1) {
    cars.push_back(c1);
}

void Treadmill::addSuitcase(CheckedSuitcase c1){
    suitcases.push(c1);
}