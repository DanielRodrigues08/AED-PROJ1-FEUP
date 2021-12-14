#ifndef AED_PROJ1_STATION_H
#define AED_PROJ1_STATION_H
#include "Transport.h"
#include <list>
#include <exception>

class Station {
float distance;
list<Transport> transports;
public:
    Station(float distance);
    void addTransport(Transport t1);
    bool removeTransport(Transport t1);

};

#endif //AED_PROJ1_STATION_H
