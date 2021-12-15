//
// Created by pedro on 29/11/2021.
//

#include "Flight.h"

Flight::Flight(int number,string origin,string destination,string departureDate,string duration){
    this->number = number;
    this->origin = origin;
    this->destination = destination;
    this->departureDate= departureDate;
    this->duration = duration;
}


int Flight::getNumber(){
    return this->number;
}

bool Flight::operator<(Flight &flight) {
    if(origin < flight.getOrigin()){
        return destination < flight.getDestination();
    }
    return origin < flight.getOrigin();
}

bool Flight::operator==(Flight &flight) {return this->number < flight.number;}

string Flight::getDepartureDate() {
    return departureDate;
}

string Flight::getDuration() {
    return duration;
}

string Flight::getOrigin() {
    return origin;
}

string Flight::getDestination() {
    return destination;
}

void Flight::setDepartureDate(string newDepartureDate) {
    departureDate = newDepartureDate;
}

void Flight::incrementBookedSeats() {
   bookedSeats++;
}
