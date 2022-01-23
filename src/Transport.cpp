#include "Transport.h"

Transport::Transport(string destination, TypeTransport type): destination(destination), type(type), schedule(Time(0,0,0)) {
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

TypeTransport Transport::getType() const {
    return type;
}

bool Transport::operator==(const Transport& t1) const{
    return type == t1.type && destination == t1.destination;
}

void Transport::show() const {
    switch (type) {
        case(metro):
            cout<< "Metro\t";
            break;
        case(train):
            cout<< "Train\t";
            break;
        case(bus):
            cout<<"Bus\t";
            break;
    }
    cout << destination << endl;
    BSTItrIn<Time> temp(schedule);
    unsigned useless = 0;
    while(!temp.isAtEnd()){
        cout << temp.retrieve() << "\t";
        if(useless%3==0)
            cout << endl;
        useless++;
    }
}

void Transport::show(const Time& t1, const Time&t2) const {
    switch (type) {
        case(metro):
            cout<< "Metro\t";
            break;
        case(train):
            cout<< "Train\t";
            break;
        case(bus):
            cout<<"Bus\t";
            break;
    }
    cout << destination  << endl;
    BSTItrIn<Time> temp(schedule);
    unsigned useless = 0;
    while(!temp.isAtEnd()){
        if(t2 < temp.retrieve())
            break;
        else if(temp.retrieve() < t1)
            continue;
        cout << temp.retrieve() << "\t";
        if(useless%3==0)
            cout << endl;
        useless++;
        temp.advance();
    }
    cout << endl;
}

vector<Time> Transport::getSchedule() {
    vector<Time> t;
    switch (type) {
        case(metro):
            cout<< "Metro\t";
            break;
        case(train):
            cout<< "Train\t";
            break;
        case(bus):
            cout<<"Bus\t";
            break;
    }
    cout << destination << endl;
    BSTItrIn<Time> temp(schedule);
    while(!temp.isAtEnd()){
        t.push_back(temp.retrieve());
    }
    return t;
}