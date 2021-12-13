#include "Suitcase.h"
#include "Passenger.h"
#include "Flight.h"

Suitcase::Suitcase() {
    weight = 0;
    width = 0;
    height = 0;
    length = 0;
}

Suitcase::Suitcase( float weight, float width, float height, float length): weight(weight), width(width), height(height), length(length){
}

void Suitcase::setWeight(float weight) {
    this->weight=weight;
}

float Suitcase::getWeight() const{
    return weight;
}

float Suitcase::getWidth() const{
    return width;
}

float Suitcase::getHeight() const{
    return height;
}

float Suitcase::getLength() const{
    return length;
}

bool Suitcase::isAllow() const {
    return isAllowedDimensions() && overweight() == 0;
}

void Suitcase::removeOverweight(){
    weight -= overweight();
}

Handbag::Handbag(): Suitcase(){}

Handbag::Handbag(float weight, float width, float height, float length): Suitcase(weight,width,height,length){}


bool Handbag::isAllowedDimensions() const{
    if(getHeight() > 55 || getWidth() > 20 || getHeight() > 40)
        return false;
    return true;
}

float Handbag::overweight() const{
    if(getWeight() - 8 > 0)
        return getWeight() - 8;
    else
        return 0;
}

HoldSuitcase::HoldSuitcase():Suitcase() {}

HoldSuitcase::HoldSuitcase(float weight, float width, float height, float length): Suitcase(weight,width,height,length){}

bool HoldSuitcase::isAllowedDimensions() const{
    if(getHeight() > 55 || getWidth() > 24 || getLength() > 40)
        return false;
    return true;
}

float HoldSuitcase::overweight() const{
    if(getWeight() - 23 > 0)
        return getWeight() - 23;
    else
        return 0;
}

CheckedSuitcase::CheckedSuitcase(Passenger passenger, Flight flight, HoldSuitcase suitcase): suitcase(suitcase), passenger(passenger), flight(flight) {}

Flight CheckedSuitcase::getFlight() const {
    return flight;
}

Passenger CheckedSuitcase::getPassenger() const {
    return passenger;
}

HoldSuitcase CheckedSuitcase::getSuitcase() {
    return suitcase;
}
