#include "CheckIn.h"
#include "Treadmill.h"
#include "Suitcase.h"
#include "Flight.h"
#include "Ticket.h"
#include <list>

unsigned CheckIn::idAux = 1;

CheckIn::CheckIn(Treadmill treadmill):treadmill(treadmill) {
    id = idAux;
    idAux++;
}

float CheckIn::checkInPassenger(Passenger* passenger, Ticket ticket) {
    int counter = 0;
    for(auto it = passenger->getLuggage().begin(); it != passenger->getLuggage().end(); it++){
        if((*it)->overweight() != 0){
            counter+=(*it)->overweight();
        }
        if((*it)->getType()=="HoldSuitcase"){
            cout << "CHECK IN HOLD SUIT CASE" << endl;
            treadmill.addSuitcase(CheckedSuitcase(*passenger,ticket.getFlight(),*(dynamic_cast<HoldSuitcase*>(*it))));
            it = passenger->getLuggage().erase(it);
            it--;
        }
    }
    return counter;
}