#ifndef AED_PROJ1_TIME_H
#define AED_PROJ1_TIME_H

#include <exception>
#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

class Time{
private:
    unsigned hours, minutes, seconds;
    friend void sum( Time& t1, const Time& t2, Date& d1);
public:
    Time(unsigned hours,unsigned minutes,unsigned seconds);
    Time();
    bool operator<(const Time& t1);
    bool operator==(const Time& t1);
    unsigned getHours() const;
    unsigned getMinutes() const;
    unsigned getSeconds() const;
};

class ErrorInvalidTime: public exception{
public:
    ErrorInvalidTime(){};
};
#endif //AED_PROJ1_TIME_H
