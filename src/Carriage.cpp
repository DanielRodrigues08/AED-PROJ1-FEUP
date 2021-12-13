#include "Carriage.h"

#include <stack>
#include <list>
#include <queue>
#include "Carriage.h"
#include "Suitcase.h"

Carriage::Carriage(unsigned maxNumSuitcases, unsigned maxNumStacks):maxNumSuitcases(maxNumSuitcases), maxNumStacks(maxNumStacks) {}

bool Carriage::addSuitcase(const CheckedSuitcase &l1) {
    if(getCapacity() == 0)
        return false;
    for(auto idx: suitcases){
        if(maxNumSuitcases > idx.size())
            idx.push(l1);
        return true;
    }
    stack<CheckedSuitcase> temp;
    temp.push(l1);
    return true;
}

unsigned Carriage::getCapacity() {
    unsigned counter = 0;
    for(auto idx: suitcases)
        counter += idx.size();
    return maxNumStacks*maxNumSuitcases - counter;
}

bool Carriage::isEmpty() {
    for(auto idx: suitcases)
        if(idx.size() != 0)
            return false;
    return true;
}

list<CheckedSuitcase> Carriage::unloadCarriage(){
    list<CheckedSuitcase> result;
    for(auto it = suitcases.begin(); it != suitcases.end(); it++){
        while (!it->empty()){
            result.push_back(it->top());
            it->pop();
        }
        it = suitcases.erase(it);
        it--;
    }
    return result;
}

bool Carriage::loadSuitcases(queue<CheckedSuitcase> &luggage) {
    bool check = true;
    while (!luggage.empty()){
        if(addSuitcase(luggage.front()))
            luggage.pop();
        else {
            check = false;
            break;
        }
    }
    return check;
}