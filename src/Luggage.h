#ifndef AED_PROJ1_LUGGAGE_H
#define AED_PROJ1_LUGGAGE_H

#include "Flight.h"

class Luggage{
private:
    Passenger passenger;
    Flight flight;
    int weight;
public:
    Luggage(Passenger passenger, Flight flight, int weight);
    void setPassenger (const Passenger& passenger);
    void setFlight (const Flight& flight);
    void setWeight (int weight);
    Passenger getPassenger();
    Flight getFlight();
    int getWeight();

};


#endif //AED_PROJ1_LUGGAGE_H
