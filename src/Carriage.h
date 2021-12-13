#ifndef AED_PROJ1_CARRIAGE_H
#define AED_PROJ1_CARRIAGE_H

#include <stack>
#include <list>
#include <queue>
#include "Suitcase.h"

using namespace std;
class Carriage {
    list<stack<CheckedSuitcase>> suitcases;
    unsigned maxNumSuitcases;
    unsigned maxNumStacks;
public:
    Carriage(unsigned maxNumSuitcases, unsigned maxNumStacks);
    bool addSuitcase(const CheckedSuitcase& l1);
    CheckedSuitcase removeSuitcase();
    unsigned getCapacity();
    bool isEmpty();
    list<CheckedSuitcase> unloadCarriage();
    void  loadSuitcases(stack<CheckedSuitcase> &luggage);
};


#endif
