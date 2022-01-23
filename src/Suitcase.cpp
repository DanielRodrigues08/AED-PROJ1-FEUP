#include "Suitcase.h"
#include "Person.h"
#include "Flight.h"

unsigned Suitcase::idAux =1;

Suitcase::Suitcase() {
}

Suitcase::Suitcase( float weight, float width, float height, float length): weight(weight), width(width), height(height), length(length){
    id = idAux;
    idAux++;
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

Handbag::Handbag(float weight, float width, float height, float length): Suitcase(weight,width,height,length){
}


bool Handbag::isAllowedDimensions() const{
    if(getHeight() > 55 || getWidth() > 20 || getHeight() > 40 || getWeight() < 0)
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

unsigned Suitcase::getID() const {
    return id;
}

bool Suitcase::operator==(const Suitcase &c1) const{
    return c1.id == id;
}

bool Suitcase::operator==(const Suitcase *c1) const{
    return c1->id == id;
}

void Suitcase::setWeight(float w1) {
    weight = w1;
}

bool HoldSuitcase::updateWeight(float w1)  {
    if(w1<0)
        return false;
    setWeight(w1);
    return true;
}

bool Handbag::updateWeight(float w1)  {
    if(w1<0)
        return false;
    setWeight(w1);
    return true;
}

string Handbag::getType() const {
    return "Handbag";
}

string HoldSuitcase::getType() const {
    return "HoldSuitcase";
}

