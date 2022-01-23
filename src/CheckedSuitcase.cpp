#include "CheckedSuitcase.h"

CheckedSuitcase::CheckedSuitcase(Passenger passenger, Flight flight, HoldSuitcase suitcase): suitcase(suitcase), passenger(passenger), flight(flight) {}

Flight CheckedSuitcase::getFlight() const {
    return flight;
}

Passenger CheckedSuitcase::getPassenger() const {
    return passenger;
}

HoldSuitcase CheckedSuitcase::getSuitcase() {
    return suitcase;
}

