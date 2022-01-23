#include <algorithm>
#include "Plane.h"

using namespace std;



Plane::Plane(unsigned int numSeatsFirst, unsigned int numSeatsExecutive, unsigned int numSeatsEconomic, int licensePlate,string model) {
    this->numSeatsFirst = numSeatsFirst;
    this->numSeatsExecutive = numSeatsExecutive;
    this->numSeatsEconomic = numSeatsEconomic;
    this->licensePlate = licensePlate;
    this->model = model;
}

Plane::Plane() {
}
int Plane::getLicensePlate() const{
    return licensePlate;
};

unsigned Plane::getNumSeatsFirst() const {
    return numSeatsFirst;
}

unsigned Plane::getNumSeatsExecutive() const {
    return numSeatsExecutive;
}

unsigned Plane::getNumSeatsEconomic() const {
    return numSeatsEconomic;
}

string Plane::getModel() const{
    return model;
}
void Plane::addGroupSuitcaseCargo(list<CheckedSuitcase> c1) {
    cargoHold.insert(cargoHold.end(),c1.begin(),c1.end());
}


void Plane::addFlight(Flight *f1) {
    flightPlan.push_back(f1);
    sort(flightPlan.begin(),flightPlan.end(),  [] (Flight const* f1, Flight const* f2)
    {
        if (f1->getDepartureDate() == f2->getDepartureDate())
            return f1->getDepartureTime() < f2->getDepartureTime();
        return f1->getDepartureDate() < f2->getDepartureDate();
    });
}

void Plane::updateFlight(unsigned id, Date departureDate, Time departureTime, Time duration, Location destination, Location origin){
    bool check = true;
    for(auto flight: flightPlan){
        if(flight->getIdFlight() == id){
            flight->changeDepartureDate(departureDate);
            flight->changeDepartureTime(departureTime);
            flight->changeDestination(destination);
            flight->changeDuration(duration);
            flight->changeOrigin(origin);
            sort(flightPlan.begin(),flightPlan.end(),  [] (Flight const* f1, Flight const* f2)
            {
                if (f1->getDepartureDate() == f2->getDepartureDate())
                    return f1->getDepartureTime() < f2->getDepartureTime();
                return f1->getDepartureDate() < f2->getDepartureDate();
            });
            check= false;
            break;
        }
    }
    if(check){
        throw ErrorNoFlight();
    }
}

bool Plane::removeFlight(unsigned id) {
    for(auto it = flightPlan.begin(); it != flightPlan.end(); it++){
        if((*it)->getIdFlight() == id) {
            flightPlan.erase(it);
            return true;
        }
    }
    return false;
}

vector<Flight*> Plane::getFlightPlan(){
    return flightPlan;
}

unsigned Plane::getNumFlights() const{
    return flightPlan.size();
}

void Plane::unloadSuitcases(){
    cargoHold.clear();
}

void Plane::addPassenger(Passenger* p1) {
    passengers.push_back(p1);
}


void Plane::unloadPassenger() {
    for(auto idx: passengers)
        idx->clearSuitcases();
    passengers.clear();
}


void Plane::addService(Service s1) {
    servicesToDo.push(s1);
}

void Plane::doService() {
    if(servicesToDo.size()!=0) {
        servicesDone.push_back(servicesToDo.front());
        servicesToDo.pop();
    }
}

vector<Flight> Plane::getFlight(const string& origin, const string& destination ) const{
    vector<Flight> result;
    for(auto flight: flightPlan){
        if(flight->getOrigin().getStr() == origin && flight->getDestination().getStr()==destination) {
            result.push_back(*flight);
        }
    }
    return result;
}

Flight* Plane::getFirstFlight(){
    if(flightPlan.size() == 0)
        throw ErrorNoFlight();
    return flightPlan[0];
}

unsigned Plane::getIDFirstFlight() {
    if(flightPlan.size() == 0)
        throw ErrorNoFlight();
    return flightPlan[0]->getIdFlight();
}

void Plane::setNextFlight() {
    if(pastFlights.size()!=0){
        unloadPassenger();
        unloadSuitcases();
    }
    pastFlights.push(*flightPlan.begin());
    flightPlan.erase(flightPlan.begin());
}

void Plane::showAllPassengers() const {
    cout << "Passenger\tNIF" << endl;
    for (auto idx: passengers)
        cout << idx->getName() << "\t\t" << idx->getNif() << endl;
}



void Plane::showCargoHold() const{
    cout << "Passenger\tID HoldSuitcase" << endl;
    for(auto idx: cargoHold){
        cout << idx.getPassenger().getName() << "\t\t" << idx.getSuitcase().getID() << endl;
    }
}

void Plane::show() const{
    cout << licensePlate << "\t" << model << endl;
}

void Plane::showService() const {
    cout << "IDStaff\tStaff\tDate\tTime" << endl;
    for (auto service: servicesDone) {
        service.show();
    }
}

list<Service> Plane::getNEliminateServicesToDo() {
    list<Service> serv;
    while(!servicesToDo.empty()){
        serv.push_back(servicesToDo.front());
        servicesToDo.pop();
    }
    return serv;
}

list<Service> Plane::getServicesDone() {
    return servicesDone;
}

void Plane::addServiceDone(Service s1) {
    servicesDone.push_back(s1);
};



