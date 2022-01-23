#ifndef AED_PROJ1_LOCATION_H
#define AED_PROJ1_LOCATION_H

#include <string>
#include "Station.h"
#include "BST.h"
using namespace std;
/**
 * every location for a airport or station is more than a string and should be represented as a Location Object
 *
 * holds a BST of all the nearby stations and a string with name of the city
 */
class Location {
    friend istream& operator>>(istream& is,Location& l);
private:
    string location;
    BST<Station> nearbyStations;
public:
    /**
     * main constructor
     * @param location
     */
    Location(string location);
    /**
     * default constructor
     */
    Location();
    /**
     * offers a partial listing of the stations where the limit is the distance range
     * @param distance1 min distance the station must be from the city
     * @param distance2 max distance the station must be from the city
     * @return list of all the stations that fit the range
     */
    list<Station> getStation(float distance1, float distance2) const;
    /**
     * getter
     * @return the attribute location as a string
     */
    string getStr() const;
    /**
     * adds a station to the BST nearbyStations
     * @param s1 station to be added
     */
    void addStation(Station s1);
    /**
     * remove a station that is at a certain distance of the city in the BST nearbyStations
     * @param distance the distance of the station
     */
    void removeStation(float distance);
    /**
     * getter
     * @param distance
     * @return the station that is at a certain distance
     */
    Station getStation(float distance);
    Station getStation(Station &s);
    void showStation() const;
};

class ErrorInvalidStation{
public:
    ErrorInvalidStation(){};
};
#endif //AED_PROJ1_LOCATION_H
