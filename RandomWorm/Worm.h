#ifndef WORM_H
#define WORM_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include "Body.h"

class Worm{
    private:
    std:: vector<Body> wormBody_;
    int  wormSize_;
    float  maxSizeX_;
    float  maxSizeY_;
    float  movementRange_;
    float  movementRangeIndex_;
    int  setDirection_;
    

    
    public:
    Worm(Body headBody, int  wormSize,float  maxSizeX,float  maxSizeY, float  movementRange);
    int randomFunction(int min, int max);
    void setWormBody(bool movingBody);
    void setMovementRange();
    void bodyHead(std:: vector<float> newPosition);
    void nextStep();
    void eliminatingBorders();
    int getWormSize();
    void getWormBody(sf:: CircleShape& wormBody, int i);
    

    
    

};

#endif
