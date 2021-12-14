#include <iomanip>
#include "Date.h"

unsigned Date::monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

inline unsigned Date::GetMonthDay(int year, int month) const  //Get specific days per month
{
    if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))){
        return 29;
    }
    return monthArray[month];
}

Date::Date(unsigned year,unsigned month,unsigned day)
{
    if (year > 1800
        && month > 0 && month<13
        && day>0 && day <= GetMonthDay(year, month)){
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else
        throw ErrorInvalidDate();
}

unsigned Date::getDay() const {
    return day;
}

unsigned Date::getMonth() const {
    return month;
}

unsigned Date::getYear() const {
    return year;
}

bool Date::operator==(const Date &d1) {
    return d1.getYear() == year && d1.getMonth() == month && d1.getDay() == day;
}

bool Date::operator<(const Date &d1) {
    if(d1.getYear() == year && d1.getMonth() == month)
        return day < d1.getDay();
    if(d1.getYear() == year)
        return month < d1.getMonth();
    return year < d1.getYear();
}

ostream& operator<<(ostream& out, const Date& d1){
    out << d1.getYear() << "-" << setw(2) << setfill('0') << d1.getMonth() << ":" << setw(2) << setfill('0') << d1.getDay();
    return out;
}
