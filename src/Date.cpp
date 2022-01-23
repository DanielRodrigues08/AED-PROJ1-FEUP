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
        && month >= 0 && month<13
        && day>=0 && day <= GetMonthDay(year, month)){
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else
        throw ErrorInvalidDate();
}

Date::Date(){
    year = 0;
    month = 0;
    day = 0;
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

bool Date::operator==(const Date &d1) const{
    return d1.getYear() == year && d1.getMonth() == month && d1.getDay() == day;
}

bool Date::operator<(const Date &d1) const{
    if(d1.getYear() == year && d1.getMonth() == month)
        return day < d1.getDay();
    if(d1.getYear() == year)
        return month < d1.getMonth();
    return year < d1.getYear();
}

ostream& operator<<(ostream& out, const Date& d1){
    out << d1.year << "-" << setw(2) << setfill('0') << d1.month << "-" << setw(2) << setfill('0') << d1.day;
    return out;
}


istream& operator>>(istream& is,  Date& d){
    int day, month, year;
    char ch1, ch2;
    if (is >> day >> ch1 >> month >> ch2 >> year)
    {
        if ((ch1 == '/' && ch2 == '/') || (ch1 == '-' && ch2 == '-')){
            try {
                d = Date(day, month, year);
            }catch (ErrorInvalidDate){
                is.setstate(ios::failbit);
            }
        }
        else
            is.setstate(ios::failbit);
    }
    return is;
}