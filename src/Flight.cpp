#include "Flight.h"
#include <string>
#include "Time.h"
#include "Date.h"

using namespace std;

Flight::Flight(unsigned int idFlight, Date departureDate, Time departureTime, Time duration, string origin,string destination) {
    this->idFlight = idFlight;
    this->departureDate = departureDate;
    this->departureTime = departureTime;
    this->duration = duration;
    this->origin = origin;
    this->destination = destination;
}

unsigned Flight::getIdFlight() const{
    return idFlight;
}

Date Flight::getDepartureDate() const {
    return departureDate;
}

Time Flight::getDepartureTime() const {
    return departureTime;
}

string Flight::getOrigin() const {
    return origin;
}

string Flight::getDestination() const {
    return destination;
}

void Flight::changeDepartureDate(Date d1) {
    departureDate = d1;
}

void Flight::changeDepartureTime(Time t1) {
    departureTime = t1;
}

Time Flight::getDuration() const {
    return duration;
}

