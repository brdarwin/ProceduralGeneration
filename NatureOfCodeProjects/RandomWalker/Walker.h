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
    float  levyFlightRange_;
    int    levyFlightProbability_;
    float  movementRange_;
    float  movementRangeIndex_;
    int    setDirection_ = 0;
    sf :: Color walkerColor_;

    
    public:
    Walker(float xPosition,  float yPosition, float screenSizeX, float screenSizeY,float  usualRange,float  levyFlightRange, int    levyFlightProbability, sf:: Color walkerColor);
    void setPosition( float newPosition, bool isXPosition);
    float getPosition(bool isXPosition);
    template <typename T> T randomFunction(T min, T max, bool isFloat);
    float acceptRejectAlgorithm();
    void levyFlight();
    void setMovementRange();
    void nextStep();
    void eliminatingBorders();
    void setWalkerPosition(sf:: CircleShape& shape);
    

    
    

};

#endif
