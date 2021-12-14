#include "Time.h"
#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;

Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    if(hours < 24 || minutes < 60 || seconds < 60)
        throw ErrorInvalidTime();
    else{
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
}

ostream& operator<<(ostream& out, const Time& t){
    out << setw(2) << setfill('0') << t.getHours() << ":" << setw(2) << setfill('0') << t.getMinutes() << ":" << setw(2) << setfill('0') << t.getSeconds();
    return out;
}

istream& operator>>(istream& in,  Time& t){
    in >> t.hours >> t.minutes >> t.seconds;
    return in;
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

bool Time::operator<(const Time &t1) {
    if(hours == t1.getHours() && minutes == t1.getMinutes())
        return seconds < t1.getSeconds();
    if(hours == t1.getHours())
        return minutes < t1.getMinutes();
    return hours < t1.getHours();
}

bool Time::operator==(const Time &t1) {
    if(t1.getHours() == hours && t1.getMinutes() == minutes && t1.getSeconds() == seconds)
        return true;
    return false;
}