#ifndef AED_PROJ1_STATION_H
#define AED_PROJ1_STATION_H
#include "Transport.h"
#include <list>
#include <exception>
#include <algorithm>

/**
 * Every location a certain number of station that are at a certain distance from that location
 *
 * A station has a never-ending amount of transports (metro,bus,train) that are stored in the list transports
 */
class Station {
private:
    float distance;
    list<Transport> transports;
public:
    Station(float distance);
    Station(){};
    /**
     * adds the transport t1 to the list of transports held in this station
     * @param t1 a transport object
     */
    void addTransport(Transport t1);
    bool removeTransport(Transport t1);
    Transport getTransport(string destination, TypeTransport type);
    Transport& getTransport(Transport& t1);
    float getDistance() const;
    /**
     * a getter that returns a list of all the transports in this station
     * @return list of transports
     */
    list<Transport> getTransports() const;
    bool operator<(const Station& s1) const;
    bool operator==(const Station& s1) const;
    bool operator<(const Station *s1) const;
    /**
     * a purely front-end method that return all the transports in the station and its distance
     */
    void show() const;
};

class ErrorInexistentTransport: public exception{
public:
    ErrorInexistentTransport(){};
};

#endif //AED_PROJ1_STATION_H
