#ifndef AED_PROJ1_PLANE_H
#define AED_PROJ1_PLANE_H
#include <string>
#include <list>
#include <vector>
#include "Flight.h"
#include "CheckedSuitcase.h"
#include "Services.h"
using namespace std;


class Plane{
    unsigned numSeatsFirst=20;
    unsigned numSeatsExecutive=30;
    unsigned numSeatsEconomic=100;
    int licensePlate;
    string model;
    list<CheckedSuitcase> cargoHold;
    list<Passenger*> passengers;
    vector<Flight*> flightPlan;
    queue<Service> servicesToDo;
    list<Service> servicesDone;
    stack<Flight*> pastFlights;
public:
    Plane(unsigned int numSeatsFirst, unsigned int numSeatsExecutive, unsigned int numSeatsEconomic, int licensePlate,string model);
    Plane();
    int getLicensePlate() const;
    unsigned getNumSeatsFirst() const;
    unsigned getNumSeatsExecutive() const;
    unsigned getNumSeatsEconomic() const;
    string getModel() const;
    vector<Flight*> getFlightPlan();
    void addGroupSuitcaseCargo(list<CheckedSuitcase> c1);
    void addFlight(Flight* f1);
    bool removeFlight(unsigned id);
    void addPassenger(Passenger* p1);
    void unloadSuitcases();
    void unloadPassenger();
    void addService(Service s1);
    void addServiceDone(Service s1); //for purposes of populating
    list<Service>getServicesDone();
    void doService();
    list<Service> getNEliminateServicesToDo();
    vector<Flight> getFlight(const string& origin, const string& destination ) const;
    Flight* getFirstFlight();
    unsigned getIDFirstFlight();
    void setNextFlight();
    void showAllPassengers() const;
    void showCargoHold() const;
    void show() const;
    void showService() const;
    unsigned getNumFlights() const;
    void updateFlight(unsigned id, Date departureDate, Time departureTime, Time duration, Location destination, Location Origin);
};


class ErrorNoFlight{
public:
    ErrorNoFlight(){};
};




#endif //AED_PROJ1_PLANE_H
