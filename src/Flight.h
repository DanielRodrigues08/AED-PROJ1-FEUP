//
// Created by pedro on 29/11/2021.
//

#ifndef AED_PROJ1_FLIGHT_H
#define AED_PROJ1_FLIGHT_H


class Flight {
    static int number;
    string departureDate, duration, origin, destination;

public:
    //getters
    int getNumber();
    string getDepartureDate();
    string getDuration();
    string getOrigin();
    string getDestination();
    //setters, mainly used by the Airplane class to delay and alter flight characteristics
    void setDepartureDate();

    bool operator<(Flight &flight);
    bool operator==(Flight &flight);

};


#endif //AED_PROJ1_FLIGHT_H
