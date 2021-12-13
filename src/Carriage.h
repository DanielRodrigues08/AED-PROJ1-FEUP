#ifndef AED_PROJ1_CARRIAGE_H
#define AED_PROJ1_CARRIAGE_H

#include <stack>
#include <list>
#include <queue>
#include "Suitcase.h"

using namespace std;
class Carriage {
    stack<CheckedSuitcase> suitcases;
    unsigned maxNumSuitcases;
public:
    Carriage(unsigned maxNumSuitcases);
    bool addSuitcase(const CheckedSuitcase& l1);
    CheckedSuitcase removeSuitcase();
    unsigned getCapacity();
    bool isEmpty();
    list<CheckedSuitcase> unloadStack();
    void  loadStack(queue<CheckedSuitcase> &luggage);
};


#endif
