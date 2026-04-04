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

    
    public:
    Walker(float xPosition,  float yPosition, float screenSizeX, float screenSizeY);
    void setPosition( float newPosition, bool isXPosition);
    float getPosition(bool isXPosition);
    void nextStep();
    void eliminatingBorders();
    void setWalkerPosition(sf:: CircleShape& shape);
    

    
    

};

#endif
