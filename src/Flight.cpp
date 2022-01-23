#include "Flight.h"
#include <string>
#include "Time.h"
#include "Date.h"

using namespace std;

Flight::Flight(unsigned int idFlight, Date departureDate, Time departureTime, Time duration, Location origin,Location destination) {
    this->idFlight = idFlight;
    this->departureDate = departureDate;
    this->departureTime = departureTime;
    this->duration = duration;
    this->origin = origin;
    this->destination = destination;
}

Flight::Flight() {
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

Location Flight::getOrigin() const {
    return origin;
}

Location Flight::getDestination() const {
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

bool Flight::operator==(const Flight &f1) const{
    return idFlight == f1.idFlight;
}

bool Flight::operator==(const Flight *f1) const{
    return idFlight == f1->idFlight;
}

void Flight::show() const {
    cout << idFlight << "\t\t" << departureDate<< "\t"  << departureTime<< "\t" << duration << "\t" << origin.getStr()<< "\t" << destination.getStr()<<endl;
}

bool Flight::operator<(const Flight *f1) const{
    if (departureDate == departureDate)
        return !(departureTime < f1->departureTime);
    return !(departureDate < f1->departureDate);
}

void Flight::changeDestination(Location dest) {
    destination = dest;
}

void Flight::changeDuration(Time &duration) {
    this->duration = duration;
}

void Flight::changeOrigin(Location origin) {
    this->origin = origin;
}
