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
    float  movementRange_;
    float  movementRangeIndex_;
    int    setDirection_ = 0;

    
    public:
    Walker(float xPosition,  float yPosition, float screenSizeX, float screenSizeY, float movementRange);
    void setPosition( float newPosition, bool isXPosition);
    float getPosition(bool isXPosition);
    void randomFunction();
    void setMovementRange();
    void nextStep();
    void eliminatingBorders();
    void setWalkerPosition(sf:: CircleShape& shape);
    

    
    

};

#endif
