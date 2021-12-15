//
// Created by pedro on 29/11/2021.
//

#include "Airplane.h"

Airplane::Airplane(const string licensePlate, const string type, int capacity) : licensePlate(licensePlate), type(type), capacity(capacity) {
}

void Airplane::assignFlight(Flight &flight) {
    flights.push_back(flight);
    flights.sort();
}

void Airplane::removeFlight(Flight &flight) {
    flights.remove(flight);
}

void Airplane::scheduleService(Service &service){
    shceduledServices.push(service);
}

int Airplane::availableSeats() {
    return capacity - seatsReserved;
}
