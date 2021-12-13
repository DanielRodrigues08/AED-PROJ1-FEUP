#ifndef AED_PROJ1_PASSENGER_H
#define AED_PROJ1_PASSENGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Passenger {
    string name,birthdate,id;


    int numFriends;
    vector<string> friendsName;

public:
    Passenger(string id, string birthdate, string name);
    bool canBuyTicket();
    void buyTicket();
    bool wantLuggage();
    string getID();
    void cancelFlight();
};


#endif //AED_PROJ1_PASSENGER_H