#ifndef AED_PROJ1_TRANSPORT_H
#define AED_PROJ1_TRANSPORT_H
#include <string>
#include <vector>
#include "BST.h"
#include "Time.h"

using namespace std;

enum Type {metro, train, bus};

class Transport{
    Type type;
    string destination;
    BST<Time> schedule;
public:
    Transport(string destination, Type type);
    void addTime( Time t1);
    void addTime(stack<Time>& t1);
    bool removeTime(const Time& t1);
    string getDestination() const;
    Type getType() const;
    void changeDestination( string d1);
    bool operator==(const Transport& t1);
};

#endif //AED_PROJ1_TRANSPORT_H
