#ifndef AED_PROJ1_PERSON_H
#define AED_PROJ1_PERSON_H

#include <string>
#include <list>
#include <algorithm>
#include "Date.h"
#include "Ticket.h"
#include "Suitcase.h"

using namespace std;
/**
 * this class is a parent class to passenger
 *
 * is used to store info about a person sucha as name, age, nif and their login informations
 */
class Person {
    string name;
    unsigned age;
    unsigned nif;
    //Login
    string username;
    string password;
public:
    Person(string name, unsigned age, unsigned nif, string username, string password);
    Person();
    void changePassword(string password);
    void changeUsername(string username);
    string getUsername() const;
    string getName() const;
    string getPassword() const;
    unsigned getAge() const;
    unsigned getNif() const;
    bool operator==(const Person& p1) const;
    ~Person(){};
};
/**
 * extends Person and adds a few methods such as buying tickets, adding suitcases etc...
 */
class Passenger:public Person{
    list<Ticket> tickets;
    list<Suitcase*> suitcases;

public:
    /**
     * main constructor
     * @param name the name of the passenger
     * @param age the name of the passenger
     * @param nif the nif of the passenger
     * @param username the username of the passenger
     * @param password the password of the passenger
     */
    Passenger(string name, unsigned age, unsigned nif, string username, string password);
    Passenger();
    /**
     * listagem completa dos tickets comprados pelo passageiro
     * @return a list just like the one in the attributes
     */
    list<Ticket> getAllTickets();
    /**
     * adds a ticket to the list of tickets
     * @param t1
     */
    void addTicket(Ticket t1);
    Ticket& getTicket(int ticketID);
    /**
     * checks for the validity of the ticket
     * @param idFlight the flight that needs its existence checked
     * @return the bool that translates the success of the operation
     */
    bool validTicket(unsigned idFlight);
    void cancelTicket(int ticketID);
    /**
     * in the act of check in it adds a suitcase to the passenger
     * @param c1
     */
    void addSuitcase(Suitcase* c1);
    void removeSuitcase(unsigned id);
    bool updateSuitcase(unsigned id, float weight);
    list<Suitcase*>& getLuggage();
    void clearSuitcases();

};

class ErrorInvalidTicket{
public:
    ErrorInvalidTicket(){};
};

class ErrorInexistentSuitcase{
public:
    ErrorInexistentSuitcase(){};
};
#endif //AED_PROJ1_PERSON_H
