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
    /**
     * Default Constructor
     */
    Carriage();
    /**
     * Constructor
     * @param maxNumSuitcases Number of bags that fit in a stack
     * @param maxNumStacks Number of stacks
     */
    Carriage(unsigned maxNumSuitcases, unsigned maxNumStacks);
    /**
     * If possible add a suitcase to a stack
     * @param l1 Suitcase we want to add
     * @return True if the suitcase was added otherwise it returns false
     */
    bool addSuitcase(const CheckedSuitcase& l1);
    /**
     * Determines carriage capacity
     * @return carriage capacity
     */
    unsigned getCapacity();
    /**
     * Check if the carriage is empty
     * @return Returns true if carriage is empty otherwise returns false
     */
    bool isEmpty();
    /**
     * Remove all bags from the carriage
     * @return A list of all baggage
     */
    list<CheckedSuitcase> unloadCarriage();
    /**
     * Load the bags to the carriage
     * @param luggage bags to load
     */
    void  loadSuitcases(stack<CheckedSuitcase> &luggage);
};


#endif
