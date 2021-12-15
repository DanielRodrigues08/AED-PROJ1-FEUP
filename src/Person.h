//
// Created by pedro on 15/12/2021.
//

#ifndef AED_PROJ1_PERSON_H
#define AED_PROJ1_PERSON_H


class Person {
    string id,name,birthdate;

public:
    Person(string id,string name,string birthdate);
};

class Passenger:public Person{
    list<Ticket> tickets;

public:
    explicit Passenger(string id, string birthdate, string name);
    void buyTicket();
    //total listing of tickets bought
    list<Ticket> getAllTickets();
    //partial listing of Ticket
    Ticket* getTicket(int ticketID);
    string getID();
    void cancelTicket(int ticketID);
};

class Admin: public Person{

};

class Staff: public Person{


};
#endif //AED_PROJ1_PERSON_H
