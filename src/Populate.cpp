//
// Created by pedro on 07/12/2021.
//

#include <fstream>
#include <vector>
#include "Populate.h"

namespace populate {

    void populateFlights(vector<vector<Flight> *> flights) {
        ifstream file("flights.txt");
        int number;
        string from, to, departureDate, duration;
        while (file >> number >> from >> to >> departureDate >> duration) {
            bool destPresent = true;
            for (vector<Flight> *v: flights) {
                bool destNotPresent = true;
                if (v->at(0).getOrigin() == from && v->at(0).getDepartureDate() == to) {
                    v->push_back(Flight(number, from, to, departureDate, duration));
                    destNotPresent = false;
                }

                if (destNotPresent) {
                    vector<Flight> n = {Flight(number, from, to, departureDate, duration)};
                    flights.push_back(&n);
                }
            }
        }
    };
}