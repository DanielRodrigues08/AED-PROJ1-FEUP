#ifndef AED_PROJ1_FLIGHT_H
#define AED_PROJ1_FLIGHT_H
#include <string>
#include "Time.h"
#include "Date.h"

using namespace std;

class Flight {
    unsigned idFlight;
    Date departureDate;
    Time departureTime;
    Time duration;
    string origin;
    string destination;
};


#endif