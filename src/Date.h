#ifndef AED_PROJ1_DATE_H
#define AED_PROJ1_DATE_H

#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
    static unsigned monthArray[13];
    unsigned day;
    unsigned month;
    unsigned year;
public:
    inline unsigned GetMonthDay(int year, int month) const;
    Date(unsigned day, unsigned month, unsigned year);
    unsigned getDay() const;
    unsigned getMonth() const;
    unsigned getYear() const;
    bool operator<(const Date& d1);
    bool operator==(const Date& d1);
};

class ErrorInvalidDate: public exception{
public:
    ErrorInvalidDate(){};
};


#endif
