//
// Created by pedro on 21/12/2021.
//

#ifndef AED_PROJ1_SAVE_H
#define AED_PROJ1_SAVE_H


#include "Person.h"
#include "Location.h"
#include "Plane.h"
#include <set>


using namespace std;
/**
 * when the program is coming to an end it saves all the data created to .txt files
 */
namespace save {
    /**
     * saves data that was created during the program to .txt files
     * @param users
     */
    void users(set<Passenger*> users);
    /**
     * saves data that was created during the program to .txt files
     * @param locations
     */
    void locations(vector<Location*> locations);
    /**
     * saves data that was created during the program to .txt files
     * @param planes
     */
    void planes(vector<Plane*> planes);
    /**
     * saves data that was created during the program to .txt files
     * @param staff
     */
    void staff(vector<Person*> staff);

};


#endif //AED_PROJ1_SAVE_H
