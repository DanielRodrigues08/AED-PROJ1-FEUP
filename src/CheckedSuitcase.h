#ifndef AED_PROJ1_CHECKEDSUITCASE_H
#define AED_PROJ1_CHECKEDSUITCASE_H


#include "Suitcase.h"
#include "Person.h"
#include "Flight.h"
class CheckedSuitcase{
    HoldSuitcase suitcase;
    Passenger passenger;
    Flight flight;
public:
    /**
     * constructor that populates all the attributes
     * @param passenger
     * @param flight
     * @param suitcase
     */
    CheckedSuitcase(Passenger passenger, Flight flight, HoldSuitcase suitcase);
    /**
     * getter
     * @return the attribute flight
     */
    Flight getFlight() const;
    /**
     *getter
     * @return the attribute passenger
     */
    Passenger getPassenger() const;
    /**
     * getter
     * @return the attribute passenger
     */
    HoldSuitcase getSuitcase();
};


#endif //AED_PROJ1_CHECKEDSUITCASE_H
