#include "Station.h"
#include <algorithm>


Station::Station(float distance): distance(distance) {
}

void Station::addTransport(Transport t1) {
    transports.push_back(t1);
}

bool Station::removeTransport(Transport t1) {
    auto it = find(transports.begin(), transports.end(), t1);
    if(it != transports.end()){
        transports.erase(it);
        return true;
    }
    return false;
}

Transport Station::getTransport(string destination, TypeTransport type) {
    auto it = find(transports.begin(),transports.end(),Transport(destination,type));
    if(it != transports.end())
        return (*it);
    throw ErrorInexistentTransport();
}

Transport& Station::getTransport(Transport& t1) {
    auto it = find(transports.begin(),transports.end(),t1);
    if(it != transports.end())
        return (*it);
    throw ErrorInexistentTransport();
}


float Station::getDistance() const {
    return distance;
}


bool Station::operator==(const Station &s1) const {
    return distance == s1.distance;
}

bool Station::operator<(const Station &s1) const {
    return distance < s1.distance;
}

bool Station::operator<(const Station *s1) const {
    return distance < s1->distance;
}

void Station::show() const {
    cout << "Distance: " << distance << endl;
    for(auto idx: transports){
        idx.show();
    }
}

list<Transport> Station::getTransports() const {
    return transports;
}


