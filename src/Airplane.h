//
// Created by pedro on 29/11/2021.
//
#include <queue>

#ifndef AED_PROJ1_AIRPLANE_H
#define AED_PROJ1_AIRPLANE_H
#include "Flight.h"
#include "Service.h"
#include <list>

using namespace std;

class Airplane {
    const string licensePlate, type;
    int capacity;
    int seatsReserved;
    list<Flight> flights;
    queue<Service> scheduledServices;

public:

    Airplane(string licensePlate,string type,int capacity);
    //flight related methods
    int availableSeats();
    void assignFlight(Flight &flight);
    void delayFlight(Flight &flight);
    //service related methods
    void scheduleService(Service &service);
};


#endif //AED_PROJ1_AIRPLANE_H
