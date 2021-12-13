#ifndef AED_PROJ1_SUITCASE_H
#define AED_PROJ1_SUITCASE_H

class Suitcase{
private:
    float weight, width, height, length;
public:
    Suitcase();
    Suitcase(float weight, float width, float height, float length);
    void setWeight (float weight);
    float getWeight() const;
    float getWidth() const;
    float getHeight()const;
    float getLength() const;
    bool isAllow() const;
    void removeOverweight();
    virtual bool isAllowedDimensions() const= 0;
    virtual float overweight() const= 0;

};

class Handbag: public Suitcase{
public:
    Handbag();
    Handbag(float weight, float width, float height, float length);
    bool isAllowedDimensions() const override;
    float overweight() const;
};


class HoldSuitcase: public Suitcase{
public:
    HoldSuitcase();
    HoldSuitcase(float weight, float width, float height, float length);
    bool isAllowedDimensions() const;
    float overweight() const;
};

#endif //AED_PROJ1_SUITCASE_H