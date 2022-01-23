#ifndef AED_PROJ1_FLIGHT_H
#define AED_PROJ1_FLIGHT_H
#include <string>
#include "Time.h"
#include "Date.h"
#include "Location.h"

using namespace std;
/**
 * holds the vital info of a flight, and has methods to enable CRUD operations
 */
class Flight {
    unsigned idFlight;
    Date departureDate;
    Time departureTime;
    Time duration;
    Location origin;
    Location destination;
public:
    /**
     * main constructor that populates all the attributes a flight has.
     * @param idFlight primary key for each flight
     * @param departureDate
     * @param departureTime
     * @param duration
     * @param origin
     * @param destination
     */
    Flight(unsigned idFlight, Date departureDate, Time departureTime, Time duration, Location origin, Location destination);
    /**
     * default constructor
     */
    Flight();
    /**
     * getter
     * @return idFlight
     */
    unsigned getIdFlight() const;
    /**
     * getter
     * @return departure date as a Date object
     */
    Date getDepartureDate() const;
    /**
     * getter
     * @return departure date as a Time object
     */
    Time getDepartureTime() const;
    /**
     * getter
     * @return duration of flight as Time object
     */
    Time getDuration() const;
    /**
     * getter
     * @return origin as Location object
     */
    Location getOrigin() const;
    /**
     * getter
     * @return destination as Location object
     */
    Location getDestination() const;
    /**
     * setter
     * @param d1 the new departureDate of the flight
     */
    void changeDepartureDate(Date d1);
    /**
     * setter
     * @param t1 the new departureTime of the flight
     */
    void changeDepartureTime(Time t1);
    /**
     * setter
     * @param dest the new destination of the flight
     */
    void changeDestination(Location dest);
    /**
     * setter
     * @param duration the new duration of the flight
     */
    void changeDuration(Time &duration);
    /**
     * setter
     * @param origin the new origin of the flight
     */
    void changeOrigin(Location origin);
    bool operator==(const Flight& f1) const;
    bool operator==(const Flight* f1) const;
    bool operator<(const Flight* f1) const;
    void show() const;
};





#endif