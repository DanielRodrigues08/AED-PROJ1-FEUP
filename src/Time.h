#ifndef AED_PROJ1_TIME_H
#define AED_PROJ1_TIME_H

#include <exception>
#include <iostream>
#include <iomanip>
using namespace std;

class Time{
private:
    unsigned hours, minutes, seconds;
public:
    Time(unsigned hours,unsigned minutes,unsigned seconds);
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
