#include "Transport.h"

Transport::Transport(string destination, Type type): destination(destination), type(type), schedule(Time(0,0,0)) {
}

void Transport::addTime( Time t1) {
    schedule.insert(t1);
}

void Transport::addTime(stack<Time>& t1) {
    while(!t1.empty()) {
        schedule.insert(t1.top());
        t1.pop();
    }
}

bool Transport::removeTime(const Time &t1) {
    return schedule.remove(t1);
}

string Transport::getDestination() const {
    return destination;
}

void Transport::changeDestination(string d1) {
    destination = d1;
}

Type Transport::getType() const {
    return type;
}

bool Transport::operator==(const Transport& t1){
    return type == t1.getType() && destination == t1.getDestination();
}