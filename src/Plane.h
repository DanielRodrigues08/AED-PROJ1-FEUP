#ifndef AED_PROJ1_PLANE_H
#define AED_PROJ1_PLANE_H
#include <string>
#include "Flight"
using namespace std;


class Plane{
    unsigned numSeatsFirst;
    unsigned numSeatsExecutive;
    unsigned numSeatsEconomic;
    string plate;
    string model;
    list<Flight>;
};

#endif //AED_PROJ1_PLANE_H
