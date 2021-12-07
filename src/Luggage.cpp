#include "Luggage.h"
#include "Passenger.h"
#include "Flight.h"

Luggage::Luggage(Passenger passenger, Flight flight, int weight){
    this->passenger=passenger;
    this->flight=flight;
    this->weight=weight;
}

void Luggage::setPassenger(const Passenger &passenger) {
    this->passenger = passenger;
}

void Luggage::setFlight(const Flight &flight) {
    this -> flight = flight;
}

void Luggage::setWeight(int weight) {
    this->weight=weight;
}

Passenger Luggage::getPassenger() {
    return Passenger();
}

Flight Luggage::getFlight() {
    return Flight();
}

int Luggage::getWeight() {
    return weight;
}
