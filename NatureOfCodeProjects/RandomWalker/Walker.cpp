#include "Walker.h"
#include <iostream>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>  



Walker :: Walker(float xPosition,  float yPosition, float screenSizeX, float screenSizeY,float usualRange,float levyFlightRange, int levyFlightProbability, sf::  Color walkerColor){
    xPosition_ = xPosition;
    yPosition_ = yPosition;
    maxSizeX_  = screenSizeX;
    maxSizeY_  = screenSizeY;
    usualRange_ = usualRange;
    levyFlightRange_ = levyFlightRange ;
    levyFlightProbability_ = levyFlightProbability;
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

template<typename T> T Walker :: randomFunction(T min, T max, bool isFloat){
   

    
    std :: random_device rd;
    std :: mt19937 gen(rd());
    if(isFloat){
        std:: uniform_real_distribution<float> distrib(min, max);
        return  distrib(gen);
    }

    std:: uniform_int_distribution<> distrib(min, max);
    return  distrib(gen);

}

float Walker :: acceptRejectAlgorithm(){
    float probability = randomFunction<float>(0,usualRange_, true);
    float newNumber = randomFunction<float>(0,usualRange_, true);
    if(probability > newNumber){
        return probability;
    }
    return acceptRejectAlgorithm();
}

void Walker:: levyFlight(){
    if(movementRangeIndex_ == 0){
        if(randomFunction<int>(0,100,  false) <= levyFlightProbability_){
            movementRange_ = levyFlightRange_;
        }else{
            movementRange_ = usualRange_;
        }
    }
}

void Walker:: setMovementRange(){
    if(movementRangeIndex_  >= movementRange_){
        setDirection_ = randomFunction<int>(0, 7, false);
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