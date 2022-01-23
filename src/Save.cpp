//
// Created by pedro on 21/12/2021.
//


#include "Save.h"
#include <fstream>
#include <sstream>


using namespace std;

namespace save{

    void users(set<Passenger*> usersSet){
        ofstream outFile("users.txt");
        for (const auto &e : usersSet){
            outFile << 'P' << " " << e->getName() << " " << e->getAge() << " " << e->getNif() << " " << e->getUsername() <<" "<< e->getPassword()  << "\n";
            for(auto t:e->getAllTickets()){
                outFile << 'T' << " " << t.getTypeTicket() << " " << t.getSeat() << " " << t.getFlightID() << "\n";
            }
        }
    }

    void locations(vector<Location*> locations){
        ofstream outFile("locations.txt");
        for (const auto &e : locations){
            outFile << "L" << " " << e->getStr()  << "\n";
            for(const auto s: e->getStation(0,100)){
                outFile << "S" << " " << s.getDistance() << "\n";
                for( auto t: s.getTransports()){
                    outFile << "T" << " " << t.getDestination() << " " << t.getType() ;
                    for(auto se: t.getSchedule()){
                        outFile << se << " ";
                    }
                    outFile << "\n";
                }
            }

        }
    }

    void planes(vector<Plane*> planes){
        ofstream outFile("planes.txt");
        for (const auto &e : planes){
            outFile << "P" << " "<< e->getNumSeatsFirst() << " " << e->getNumSeatsExecutive() << " " << e->getNumSeatsEconomic() << " " << e->getLicensePlate() << " " << e->getModel()  << "\n";
            for(const auto &f: e->getFlightPlan()){
                outFile << "F" << " "<< f->getIdFlight() << "  " << f->getDepartureDate() << " " << f->getDepartureTime() << " " << f->getDuration() << " " << f->getOrigin().getStr() << " " << f->getDestination().getStr()<< "\n";
            }
            for(const auto &s: e->getNEliminateServicesToDo()){
                outFile << "S" << " "<< s.getAssignStaffNIF() << " "  << s.getDate() << " " << s.getTime() << " " << s.getType() << "\n";
            }
            for(const auto &d: e->getServicesDone()){
                outFile << "D" << " "<< d.getAssignStaffNIF() << " "  << d.getDate() << " " << d.getTime() << " " << d.getType() << "\n";
            }
        }
    }

    void staff(vector<Person*> staff){
        ofstream outFile("staff.txt");
        for (const auto &e : staff) outFile  << e->getName() << " " << " " <<e->getAge() << " " << e->getNif() << " "<< e->getUsername() << " " << e->getPassword()  << "\n";
    }


}
