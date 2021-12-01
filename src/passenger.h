#ifndef AED_PROJ1_PASSENGER_H
#define AED_PROJ1_PASSENGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Passenger {
    string name;
    int numFriends;
    vector<string> friendsName;

public:
    Passenger(string name);
    bool canBuyTicket();
    void buyTicket();
    bool wantLuggage();
};


#endif //AED_PROJ1_PASSENGER_H