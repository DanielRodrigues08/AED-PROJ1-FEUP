#include "Station.h"
#include <algorithm>

Station::Station(float distance) {
    this->distance = distance;
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

Transport& Station::getTransport(string destination, Type type) {
    auto it = find(transports.begin(),transports.end(),Transport(destination,type));
    if(it != transports.end())
        return (*it);
    throw ErrorInexistentTransport();
}