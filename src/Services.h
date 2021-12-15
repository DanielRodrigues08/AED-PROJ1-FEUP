#ifndef AED_PROJ1_SERVICES_H
#define AED_PROJ1_SERVICES_H
#include "Date.h"
#include "Time.h"
#include "Plane.h"
#include "Person.h"

enum TypeService{maintenance, cleaning};

class Service {
private:
    static unsigned idAux;
    unsigned id;
    Staff staff;
    Date date;
    Time time;
    Plane plane;
    TypeService type;
public:
    Service(Staff staff, Date date, Time time, Plane plane, TypeService type);
    void changeDate(Date d1);
    void changeTime(Time t1);
    void changeStaff(Staff s1);
    unsigned getId() const;
    Date getDate() const;
    Time getTime() const;
    Plane getPlane() const;
    TypeService getType() const;
};


#endif //AED_PROJ1_SERVICES_H
