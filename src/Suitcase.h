#ifndef AED_PROJ1_SUITCASE_H
#define AED_PROJ1_SUITCASE_H

#include "Flight.h"
#include <list>
#include <string>

using namespace std;
/**
 * every passenger has a certain amount of luggage when boarding a flight, in this class we create objects suitcase that hold all the information a suitcase might have
 */
class Suitcase{
private:
    unsigned id;
    static unsigned idAux;
    float weight, width, height, length;
public:
    Suitcase();
    Suitcase(float weight, float width, float height, float length);
    ~Suitcase(){};
    float getWeight() const;
    float getWidth() const;
    float getHeight()const;
    float getLength() const;
    void setWeight(float w1);
    bool isAllow() const;
    void removeOverweight();
    unsigned getID() const;
    /**
     * as you know there are limits to the dimensions of luggage, this "parent method" will be extended to all the child classes
     * @return true if the luggage size is within limits
     */
    virtual bool isAllowedDimensions() const= 0;
    virtual bool updateWeight(float w1) =0;
    virtual float overweight() const= 0;
    bool operator==(const Suitcase& c1) const;
    bool operator==(const Suitcase* c1) const;
    virtual string getType() const = 0;

};
/**
 * extends the class suitcase. It is a specific kind of luggage that unlike the HoldSuitcase will always be in the possession of the passenger
 *
 * It never goes to the cargo hold
 */
class Handbag: public Suitcase{
public:
    Handbag();
    Handbag(float weight, float width, float height, float length);
    bool isAllowedDimensions() const override;
    float overweight() const;
    bool updateWeight(float w1);
    string getType() const ;
};

/**
 * heavier suitcases that will be sent to the cargo hold in the check in
 */
class HoldSuitcase: public Suitcase{
public:
    HoldSuitcase();
    HoldSuitcase(float weight, float width, float height, float length);
    bool isAllowedDimensions() const;
    float overweight() const;
    bool updateWeight(float w1);
    string getType() const ;
};



#endif //AED_PROJ1_SUITCASE_H