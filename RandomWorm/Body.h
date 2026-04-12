#ifndef BODY_H
#define BODY_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>


class Body{
private:
    std:: vector <float> bodyPosition_;
    std:: vector <float> previousBodyPosition_;
    sf:: Color bodyColor_;
    float bodyRadius_;


public:
    Body(std:: vector<float> bodyPosition, sf:: Color bodyColor, float bodyRadius);
    void setBodyPosition(std:: vector<float> bodyPosition);
    std:: vector<float>  getBodyPosition();
    void setPreviousBodyPosition(std:: vector<float> previousBodyPosition);
    std :: vector<float> getPreviousBodyPosition ();
    sf :: Color getBodyColor();
    float  getBodyRadius();
};



#endif