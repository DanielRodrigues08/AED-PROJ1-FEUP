//
// Created by pedro on 29/11/2021.
//

#include "Flight.h"

Flight::Flight(){}


int Flight::getNumber(){
    return this.number;
}
bool Flight::operator<(Flight &flight) {return this->departureDate < flight.departureDate;}

bool Flight::operator==(Flight &flight) {return this->number < flight.number;}