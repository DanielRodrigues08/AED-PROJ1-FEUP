#ifndef AED_PROJ1_SERVICES_H
#define AED_PROJ1_SERVICES_H
#include "Date.h"
#include "Time.h"
#include "Person.h"

enum TypeService{maintenance, cleaning};
/**
 * holds data for the services to be performed on the plane
 */
class Service {
    static unsigned idAux;
    unsigned id;
    Person staff;
    Date date;
    Time time;
    TypeService type;
public:
    /**
     * main constructor - populates all the attributes
     * @param staff  the staff member that will be performing the service
     * @param date the date in which the service will be performed
     * @param time the time at  which the service will be performed
     * @param type the type may vary from cleaning to maintenance
     */
    Service(Person staff, Date date, Time time, TypeService type);
    Service(){};
    void changeDate(Date d1);
    void changeTime(Time t1);
    void changeStaff(Person s1);
    unsigned getAssignStaffNIF() const;
    unsigned getId() const;
    Date getDate() const;
    Time getTime() const;
    TypeService getType() const;
    void show() const;
};


#endif //AED_PROJ1_SERVICES_H
