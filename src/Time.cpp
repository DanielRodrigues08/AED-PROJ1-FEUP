#include "Time.h"
#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;

Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    if(hours>24 || minutes >59 || seconds >59)
        throw ErrorInvalidTime();
    else{
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
}

Time::Time() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

ostream& operator<<(ostream& out, const Time& t){
    out << setw(2) << setfill('0') << t.hours << ":" << setw(2) << setfill('0') << t.minutes << ":" << setw(2) << setfill('0') << t.seconds;
    return out;
}

unsigned Time::getHours() const {
    return hours;
}

unsigned Time::getMinutes() const {
    return minutes;
}

unsigned Time::getSeconds() const {
    return seconds;
}

bool Time::operator<(const Time &t1) const{
    if(hours == t1.hours && minutes == t1.minutes)
        return seconds < t1.seconds;
    if(hours == t1.hours)
        return minutes < t1.minutes;
    return hours < t1.hours;
}

bool Time::operator<=(const Time &t1) const{
    if(hours == t1.hours && minutes == t1.minutes && seconds == t1.seconds)
        return true;
    if(hours == t1.hours && minutes == t1.minutes)
        return seconds < t1.seconds;
    if(hours == t1.hours)
        return minutes < t1.minutes;
    return hours < t1.hours;
}

bool Time::operator==(const Time &t1) const{
    if(t1.hours == hours && t1.minutes == minutes && t1.seconds == seconds)
        return true;
    return false;
}

istream& operator>>(istream& is, Time& t){
    unsigned hour, minute, second;
    char ch1, ch2;
    if (is >> hour >> ch1 >> minute >> ch2 >> second)
    {
        if (ch1 == ':' && ch2 == ':') {
            try{
            t = Time(hour, minute, second);
            }catch (ErrorInvalidTime){
                is.setstate(ios::failbit);
            }
        }
        else
            is.setstate(ios::failbit);
    }
    return is;
}
