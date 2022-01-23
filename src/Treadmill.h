#ifndef AED_PROJ1_TREADMILL_H
#define AED_PROJ1_TREADMILL_H

#include <queue>
#include <list>
#include <vector>
#include "CheckedSuitcase.h"
#include "TransportCar.h"
#include "Flight.h"
#include "Plane.h"

class Treadmill {
    static unsigned idAux;
    int id;
    static list<stack<CheckedSuitcase>> suitcasesContainers;
    vector<TransportCar> cars;
public:
    /**
     * creates a treadmill
     */
    Treadmill();
    /**
     * indicates the number of tranport cars that are being used
     * @return
     */
    unsigned numTransportCars() const;
    /**
     * adds transport car
     * @param c1 transportCar to be added
     */
    void addTransportCart(TransportCar c1);
    /**
     * add suitcase received in parameter to suitcasesContainers
     * @param c1 the suitcase to be added
     */
    void addSuitcase(CheckedSuitcase c1);
    /**
     * loads the plane with all the suitcases it has
     * @param idFlight the flight to which the suitcases "belong"
     * @param plane the plane to which the suitcases will be loaded to
     */
    void loadTransportPlane(const unsigned& idFlight, Plane* plane);
    /**
     * number of cars available to perform the operations
     * @return
     */
    int getNumCarsAvailable() const;
    /**
     * check if the container is empty
     * @return
     */
    bool containersEmpty() const;
    /**
     * complete listing of the available transport cars
     * @return
     */
    vector<TransportCar>* getCars();
    void showCars() const;

};


#endif //AED_PROJ1_TREADMILL_H
