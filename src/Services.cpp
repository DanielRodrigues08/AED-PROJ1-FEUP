#include "Services.h"
#include "Date.h"
#include "Time.h"
#include "Person.h"

unsigned Service::idAux = 1;

Service::Service(Person staff, Date date, Time time, TypeService type) {
    this->staff = staff;
    this->date = date;
    this->time=time;
    this->type=type;
    id = idAux;
    idAux++;
}

void Service::changeDate(Date d1) {
    date = d1;
}

void Service::changeTime(Time t1) {
    time = t1;
}

void Service::changeStaff(Person s1) {
    staff = s1;
}

unsigned Service::getId() const {
    return id;
}

Date Service::getDate() const {
    return date;
}

Time Service::getTime() const {
    return time;
}


TypeService Service::getType() const {
    return type;
}

void Service::show() const {
    cout << id << "\t" << staff.getName() << "\t" << date << "\t" << time << endl;
}

unsigned Service::getAssignStaffNIF() const {
    return staff.getNif();
}