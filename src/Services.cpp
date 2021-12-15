#include "Services.h"
#include "Date.h"
#include "Time.h"
#include "Plane.h"
#include "Person.h"

unsigned Service::idAux = 1;

Service::Service(Staff staff, Date date, Time time, Plane plane, TypeService type) {
    this->staff = staff;
    this->date = date;
    this->time=time;
    this->plane=plane;
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

void Service::changeStaff(Staff s1) {
    staff = t1;
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

Plane Service::getPlane() const {
    return plane;
}

TypeService Service::getType() const {
    return type;
}