#include "Person.h"



Person::Person(string name, unsigned int age, unsigned int nif, string username, string password) {
    this->name=name;
    this->age = age;
    this->nif=nif;
    this->username=username;
    this->password=password;
}

Person::Person() {
}

void Person::changePassword(string password) {
    this->password=password;
}

void Person::changeUsername(string username) {
    this->username=username;
}

string Person::getUsername() const {
    return username;
}

string Person::getName() const {
    return name;
}
string Person::getPassword() const{
    return password;
}

unsigned Person::getAge() const {
    return age;
}

unsigned Person::getNif() const {
    return nif;
}

Passenger::Passenger(string name, unsigned int age, unsigned int nif, string username,string password): Person(name, age, nif, username, password) {}

Passenger::Passenger(): Person() {}

list<Ticket> Passenger::getAllTickets(){
    return tickets;
}

void Passenger::cancelTicket(int ticketID){
    auto it = find(tickets.begin(),tickets.end(),Ticket(ticketID));
    if(it == tickets.end())
        throw ErrorInvalidTicket();

    tickets.erase(it);
}

Ticket& Passenger::getTicket(int ticketID) {
    auto it = find(tickets.begin(),tickets.end(),Ticket(ticketID));
    if(it == tickets.end())
        throw ErrorInvalidTicket();
    return *it;
}



bool cmp ( Ticket& first, Ticket& second)
{
    if(first.getFlight().getDepartureDate() == second.getFlight().getDepartureDate()){
        return (first.getFlight().getDepartureTime() < second.getFlight().getDepartureTime());
    }
    return ( first.getFlight().getDepartureDate() < second.getFlight().getDepartureDate() );
}

void Passenger::addTicket(Ticket t1) {
    tickets.push_back(t1);
    tickets.sort(cmp);

}

void Passenger::addSuitcase(Suitcase *c1) {
    suitcases.push_back(c1);
}

void Passenger::removeSuitcase(unsigned id) {
    for(auto it = suitcases.begin(); it != suitcases.end(); it++)
        if((*it)->getID() == id)
            suitcases.erase(it);

    throw ErrorInexistentSuitcase();
}

bool Passenger::updateSuitcase(unsigned int id, float weight) {
    for(auto it = suitcases.begin(); it != suitcases.end(); it++)
        if((*it)->getID() == id)
            return (*it)->updateWeight(weight);

    throw ErrorInexistentSuitcase();
}

list<Suitcase*>& Passenger::getLuggage() {
    return suitcases;
}


bool Passenger::validTicket(unsigned int idFlight) {
    for(auto ticket: tickets)
        if(ticket.getFlightID() == idFlight)
            return true;
    return false;
}

bool Person::operator==(const Person &p1) const {
    return nif == p1.getNif();
}

void Passenger::clearSuitcases() {
    suitcases.clear();
}


