#include "Location.h"

Location::Location(): nearbyStations(Station(-1)) {}

Location::Location(string location) :nearbyStations(Station(-1)), location(location){}

string Location::getStr() const{
    return location;
}
void Location::addStation(Station s1) {
    nearbyStations.insert(s1);
}

void Location::removeStation(float distance){
    nearbyStations.remove(Station(distance));
}

Station Location::getStation(float distance) {
    Station result = nearbyStations.find(Station(distance));
    if(result == Station(-1)){
        throw ErrorInvalidStation();
    }

    return result;
}


Station Location::getStation(Station &s){
    Station result = nearbyStations.find(s);
    if(result == Station(-1)){
        throw ErrorInvalidStation();
    }

    return result;

}

list<Station> Location::getStation(float distance1, float distance2) const{
    list<Station> result;
    BSTItrIn<Station> it(nearbyStations);

    while (!it.isAtEnd()){
        if(distance2 < it.retrieve().getDistance())
            break;
        if(it.retrieve().getDistance() < distance1)
            continue;
        result.push_back(it.retrieve());
        it.advance();
    }
    return result;
}

istream& operator>>(istream& is, Location& l){
    string location;
    if (is >> location)
    {
        if (true)
            l = Location(location);
        else
            is.setstate(ios::failbit);
    }
    return is;
}

void Location::showStation() const {
    BSTItrIn<Station> it(nearbyStations);
    while(!it.isAtEnd()){
        it.retrieve().show();
        it.advance();
    }
}


