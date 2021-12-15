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

float CheckIn::checkInPassenger(Passenger passenger, Ticket ticket) {
    int counter = 0;
    for(auto it = passenger.getLuggage().begin(); it != passenger.getLuggage().end(); it++){
        if(!(*it)->isAllowedDimensions()){
            it = passenger.getLuggage().erase(it);
            it--;
        }
        else if((*it)->overwight != 0){
            counter+=(*it)->overwight;
        }
        if(dynamic_cast<HoldSuitcase*>(*it)){
            treadmill.addSuitcase(CheckedSuitcase(*(*it),passenger,ticket.getFlight()));
            it = passenger.getLuggage().erase(it);
            it--;
        }
    }
    return counter;
}