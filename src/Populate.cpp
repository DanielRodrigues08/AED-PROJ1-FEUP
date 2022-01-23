//
// Created by danie on 18/12/2021.
//

#include "Populate.h"
#include <set>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

namespace populate{

    void users(set<Passenger*> &usersSet,vector<Plane*> &planeVect){
        string str;
        string name;
        unsigned age, nif;
        string username,password;
        fstream file;
        int type,flightID;
        string seat;
        Flight f;
        Passenger* p;
        char identifier;
        file.open("users.txt");
        if(!file.is_open()) {
            cout << "Not found";
        }

        while(getline(file,str)){
            if(str[0]=='P'){
                stringstream ss(str);
                ss >> identifier >> name >> age >> nif >> username >> password;
                p=new Passenger(name, age, nif, username, password);
                usersSet.insert(p);
            }
            else if(str[0]=='T'){
                stringstream ss(str);
                ss >> identifier >> type >> seat >> flightID;
                //search for the said flight
                for(auto plane: planeVect){
                    for(auto flight: plane->getFlightPlan()){
                        if(flight->getIdFlight()==flightID){
                            f = *flight;
                            break;
                        }
                    }
                }
                p->addTicket(*(new Ticket((TypeTicket)type,seat, f)));

            }
        }

        file.close();
    }


    void locations(vector<Location*> &locationsVect){
        string str;
        string city;
        char identifier;
        string destination;
        ifstream file("locations.txt");
        if(!file.is_open()) {
            cout << "Not found";
        }


        while(getline(file,str)){
            if(str[0]=='L'){
                stringstream ss(str);
                ss >> identifier >> city;
                locationsVect.push_back(new Location(city));
            }
        }

        file.close();
    }

    void planes(vector<Plane*> &planeVect,vector<Person*> &staffVect){
        string str;
        char identifier;
        unsigned numSeatsFirst, numSeatsExecutive, numSeatsEconomic;
        int licensePlate;
        string model;
        unsigned idFlight;
        unsigned nif;
        int type;
        Date departureDate;
        Date date;
        Time time;
        Time departureTime, duration;
        Location origin, destination;
        ifstream file;
        file.open("planes.txt");
        if(!file.is_open()) {
            cout << "Not found";
        }

        while(getline(file,str)){
            if(str[0]=='P'){
                stringstream ss(str);
                ss >> identifier >> numSeatsFirst >> numSeatsExecutive >> numSeatsEconomic >> licensePlate >> model;
                planeVect.push_back(new Plane(numSeatsFirst, numSeatsExecutive, numSeatsEconomic,licensePlate,model));
            }
            else if(str[0]=='F'){
                stringstream ss(str);
                ss >> identifier >> idFlight >> departureDate >> departureTime >> duration >>  origin >>  destination;
                planeVect.back()->addFlight(new Flight(idFlight, departureDate,  departureTime, duration,  origin,  destination));
            }
            else if(str[0]=='S'){
                stringstream ss(str);
                ss >> identifier >> nif >> date >> time >> type;
                for(auto x: staffVect){
                    if(x->getNif()==nif){
                        planeVect.back()->addService(*(new Service(*x,date,time,(TypeService)type)));
                    }
                }
            }
            else if(str[0]=='D'){
                cout << " "<< endl;
                stringstream ss(str);
                ss >> identifier >> nif >> date >> time >> type;
                for(auto x: staffVect){
                    if(x->getNif()==nif){
                        planeVect.back()->addServiceDone(*(new Service(*x,date,time,(TypeService)type)));
                    }
                }
            }
        }

        file.close();
    }

    void staff(vector<Person*> &staffVect){
        string str;
        ifstream file("staff.txt");
        if(!file.is_open()) {
            cout << "Not found";
        }

        string name;
        unsigned age;
        unsigned nif;

        string username;
        string password;
        while(getline(file,str)){
            stringstream ss(str);
            ss >> name >> age >> nif >> username >> password;
            staffVect.push_back(new Person(name, age, nif, username, password));
        }

        file.close();
    }
}
