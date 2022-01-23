#ifndef AED_PROJ1_TIME_H
#define AED_PROJ1_TIME_H

#include <exception>
#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;
/**
 * simple class used to cover cases where a time type class is needed
 */
class Time{
    friend ostream& operator<<(ostream& out, const Time& t);
    friend istream& operator>>(istream& is,Time& t);
private:
    unsigned hours, minutes, seconds;
public:
    /**
     * main constructor - populates all the attributes
     * @param hours
     * @param minutes
     * @param seconds
     */
    Time(unsigned hours,unsigned minutes,unsigned seconds);
    Time();
    bool operator<(const Time& t1) const;
    bool operator<=(const Time& t1) const;
    bool operator==(const Time& t1) const;

    unsigned getHours() const;
    unsigned getMinutes() const;
    unsigned getSeconds() const;
};

class ErrorInvalidTime: public exception{
public:
    ErrorInvalidTime(){};
};
#endif //AED_PROJ1_TIME_H
