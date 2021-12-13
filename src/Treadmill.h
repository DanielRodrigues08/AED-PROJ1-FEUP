#ifndef AED_PROJ1_TREADMILL_H
#define AED_PROJ1_TREADMILL_H

#include <queue>
#include <list>
#include "Suitcase.h"
#include "TransportCart.h"
#include "Flight.h"

class Treadmill {
    static unsigned idAux;
    int id;
    list<stack<CheckedSuitcase>> suitcasesContainers;
    list<TransportCar> cars;
public:
    Treadmill();
    void addTransportCart(TransportCar c1);
    void addSuitcase(CheckedSuitcase c1);
    void loadTransportCart();
    int getNumCarsAvailable() const;
    bool containersEmpty() const;
};


#endif //AED_PROJ1_TREADMILL_H
