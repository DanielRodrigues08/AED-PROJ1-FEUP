#ifndef AED_PROJ1_CARRIAGE_H
#define AED_PROJ1_CARRIAGE_H

#include <stack>
#include <list>
#include <queue>
#include "CheckedSuitcase.h"

using namespace std;
/**
 *
 */
class Carriage {

    list<stack<CheckedSuitcase>> suitcases;
    unsigned maxNumSuitcases;
    unsigned maxNumStacks;
public:
    /**
     * main constructor - populates the attributes maxNumSuitcases and maxNumStacks
     * @param maxNumSuitcases
     * @param maxNumStacks
     */
    Carriage(unsigned maxNumSuitcases, unsigned maxNumStacks);
    /**
     * adds suitcase to carriage
     * @param l1
     * @return
     */
    bool addSuitcase(const CheckedSuitcase& l1);
    /**
     * removes a suitcas
     * @return a checked suitcase that is now ready to go to a transportCar
     */
    CheckedSuitcase removeSuitcase();
    unsigned getCapacity();
    bool isEmpty();
    list<CheckedSuitcase> unloadCarriage();
    void  loadSuitcases(stack<CheckedSuitcase>& luggage);
};


#endif
