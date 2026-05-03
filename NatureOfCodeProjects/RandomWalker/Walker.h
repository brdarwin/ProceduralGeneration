#ifndef WALKER_H
#define WALKER_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>

class Walker{
    private:
    float  xPosition_;
    float  yPosition_;
    float  maxSizeX_;
    float  maxSizeY_;
    float  usualRange_;
    float  leviFlightRange_;
    int    leviFlightProbability_;
    float  movementRange_;
    float  movementRangeIndex_;
    int    setDirection_ = 0;

    
    public:
    Walker(float xPosition,  float yPosition, float screenSizeX, float screenSizeY,float  usualRange,float  leviFlightRange, int    leviFlightProbability);
    void setPosition( float newPosition, bool isXPosition);
    float getPosition(bool isXPosition);
    int randomFunction(int min, int max, bool isLeviFlight);
    void leviFlight();
    void setMovementRange();
    void nextStep();
    void eliminatingBorders();
    void setWalkerPosition(sf:: CircleShape& shape);
    

    
    

};

#endif
