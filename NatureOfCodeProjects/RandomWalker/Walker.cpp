#include "Walker.h"
#include <iostream>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>  



Walker :: Walker(float xPosition,  float yPosition, float screenSizeX, float screenSizeY,float usualRange,float leviFlightRange, int leviFlightProbability, sf::  Color walkerColor){
    xPosition_ = xPosition;
    yPosition_ = yPosition;
    maxSizeX_  = screenSizeX;
    maxSizeY_  = screenSizeY;
    usualRange_ = usualRange;
    leviFlightRange_ = leviFlightRange ;
    leviFlightProbability_ = leviFlightProbability;
    movementRange_ = usualRange;
    movementRangeIndex_ = usualRange;
    walkerColor_ = walkerColor;
}

void Walker :: setPosition(float newPosition, bool isXPosition){
    if  (isXPosition == true){
        xPosition_  = newPosition;
    }else if(isXPosition == false){
        yPosition_ = newPosition;
    }
    
    
}

float Walker :: getPosition(bool isXPosition){
    if  (isXPosition == true){
        return xPosition_;
    }
    return yPosition_;
}

int Walker :: randomFunction(int min, int max, bool isLeviFlight){
   

    
    std :: random_device rd;
    std :: mt19937 gen(rd());
    std:: uniform_int_distribution<> distrib(min, max);
    if(isLeviFlight == false){
        return distrib(gen);
    }
    
    return  distrib(gen);

}

void Walker:: leviFlight(){
    if(movementRangeIndex_ == 0){
        if(randomFunction(0,100, true) <= leviFlightProbability_){
            movementRange_ = leviFlightRange_;
        }else{
            movementRange_ = usualRange_;
        }
    }
}

void Walker:: setMovementRange(){
    if(movementRangeIndex_  >= movementRange_){
        setDirection_ = randomFunction(0, 7, false);
        movementRangeIndex_ = 0;
    }else{
        movementRangeIndex_ = movementRangeIndex_ + 1;
    }
}

void Walker  :: nextStep(){
    
     


    
    

    
    if(setDirection_ == 0){ 
        setPosition(xPosition_ + 1,  true);
    }else if(setDirection_ == 1){ 
        setPosition(xPosition_ - 1,  true);
    }else if(setDirection_ == 2){ 
        setPosition(yPosition_ + 1,  false);
    }else if(setDirection_ == 3) {
        setPosition(yPosition_ - 1,  false);
    }else if(setDirection_ == 4){
        setPosition(xPosition_ + 1,  true);
        setPosition(yPosition_ + 1,  false);
    }else if(setDirection_ == 5){
        setPosition(xPosition_ + 1,  true);
        setPosition(yPosition_ - 1,  false);
    }else if(setDirection_ == 6){
        setPosition(xPosition_ - 1,  true);
        setPosition(yPosition_ + 1,  false);
    }else{
        setPosition(xPosition_ - 1,  true);
        setPosition(yPosition_ - 1,  false);
    }
    
    
}



void Walker:: eliminatingBorders(){
    if(getPosition(true) > maxSizeX_){
        setPosition(0,true);
    } else if(getPosition(true) < 0){
        setPosition(maxSizeX_ ,true);
    }

    if(getPosition(false) > maxSizeY_){
        setPosition(0,false);
    } else if(getPosition(false) < 0){
        setPosition(maxSizeY_ ,false);
    }

    
    

    

}

void Walker:: setWalkerPosition(sf:: CircleShape& shape){
    shape.setFillColor(walkerColor_);
    shape.setPosition(sf:: Vector2f(getPosition(true),getPosition(false)));
}