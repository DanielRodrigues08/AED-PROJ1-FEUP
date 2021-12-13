#include "Carriage.h"

#include <stack>
#include <list>
#include <queue>
#include "Carriage.h"
#include "Suitcase.h"
Carriage::Carriage(unsigned int maxNumSuitcases):maxNumSuitcases(maxNumSuitcases) {}

bool Carriage::addSuitcase(const CheckedSuitcase &l1) {
    if(getCapacity() == 0)
        return false;
    suitcases.push(l1);
}

CheckedSuitcase Carriage::removeSuitcase() {
    CheckedSuitcase temp = suitcases.top() ;
    suitcases.pop();
    return temp;
}

unsigned Carriage::getCapacity() {
    return maxNumSuitcases - CheckedSuitcase.size();
}

bool Carriage::isEmpty() {
    return suitcases.empty();
}

list<CheckedSuitcase> Carriage::unloadStack(){
    list<CheckedSuitcase> result;
    while(!isEmpty()){
        result.push_back(suitcases.top());
        suitcases.pop();
    }
    return result;
}

void Carriage::loadStack(queue<CheckedSuitcase> &luggage) {
    while (!luggage.empty()){
        suitcases.push(luggage.front());
        luggage.pop();
    }
}