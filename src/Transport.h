#ifndef AED_PROJ1_TRANSPORT_H
#define AED_PROJ1_TRANSPORT_H
#include <string>
#include <vector>
#include <iostream>
#include "BST.h"
#include "Time.h"

using namespace std;

enum TypeTransport {metro, train, bus};
/**
 * every station must have a transport, it is this class that provides those objects
 */
class Transport{
    TypeTransport type;
    string destination;
    BST<Time> schedule;
public:
    /**
     * main constructor - populates all the transport attributes
     * @param destination
     * @param type
     */
    Transport(string destination, TypeTransport type);
    Transport(): schedule(Time(0,0,0)){};
    /**
     * ads a Time to the transport schedule
     * @param t1
     */
    void addTime( Time t1);
    void addTime(stack<Time>& t1);
    /**
     * removes a time from the transport schedule
     * @param t1 the time that must be removed
     * @return a bool that is true if it was able to find and successfully remove the time
     */
    bool removeTime(const Time& t1);
    /**
     * total listing of the BST "schedules", it is very useful when storing the info in .txt
     * @return BST in form of vector
     */
    vector<Time> getSchedule();
    /**
     * getter
     * @return attribute destination
     */
    string getDestination() const;
    /**
     * getter
     * @return attribute ty+w
     */
    TypeTransport getType() const;
    void changeDestination( string d1);
    bool operator==(const Transport& t1) const;
    void show() const;
    void show(const Time& t1, const Time&t2) const;

};

#endif //AED_PROJ1_TRANSPORT_H
