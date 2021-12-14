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
public:
    Flight(unsigned idFlight, Date departureDate, Time departureTime, Time duration, string origin, string destination);
    unsigned getIdFlight() const;
    Date getDepartureDate() const;
    Time getDepartureTime() const;
    Time getDuration() const;
    string getOrigin() const;
    string getDestination() const;
    void changeDepartureDate(Date d1);
    void changeDepartureTime(Time t1);
};


#endif