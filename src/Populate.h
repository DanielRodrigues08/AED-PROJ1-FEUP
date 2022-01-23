//
// Created by danie on 18/12/2021.
//

#ifndef AED_PROJ1_POPULATE_H
#define AED_PROJ1_POPULATE_H
#include "Person.h"
#include "Location.h"
#include "Plane.h"
#include "Date.h"
#include "Time.h"
#include <set>
#include <vector>


using namespace std;
/**
 * populates the static vectors in menu.cpp
 */
namespace populate {
    /**
     * populates the given containers with data from a .txt file
     * @param usersSet
     */
    void users(set<Passenger*> &usersSet,vector<Plane*> &planeVect);
    /**
     * populates the given containers with data from a .txt file
     * @param locationsVect
     */
    void locations(vector<Location*> &locationsVect);
    /**
     * populates the given containers with data from a .txt file
     * @param planeVect
     * @param staffVect
     */
    void planes(vector<Plane*> &planeVect,vector<Person*> &staffVect);
    /**
     * populates the given containers with data from a .txt file
     * @param staffVect
     */
    void staff(vector<Person*> &staffVect);

};


#endif //AED_PROJ1_POPULATE_H
