#include "Walker.h"
#include <iostream>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>  



Walker :: Walker (float xPosition, float yPosition, float screenSizeX, float screenSizeY){
    xPosition_ = xPosition;
    yPosition_ = yPosition;
    maxSizeX_  = screenSizeX;
    maxSizeY_  = screenSizeY;
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

void Walker  :: nextStep(){
    
     
    int min = 0;
    int max = 7;

    
    std :: random_device rd;
    std :: mt19937 gen(rd());
    std:: uniform_int_distribution<> distrib(min, max);

    
    int setDiretion = distrib(gen);

    
    

    
    if(setDiretion == 0){ 
        setPosition(xPosition_ + 1,  true);
    }else if(setDiretion == 1){ 
        setPosition(xPosition_ - 1,  true);
    }else if(setDiretion == 2){ 
        setPosition(yPosition_ + 1,  false);
    }else if(setDiretion == 3) {
        setPosition(yPosition_ - 1,  false);
    }else if(setDiretion == 4){
        setPosition(xPosition_ + 1,  true);
        setPosition(yPosition_ + 1,  false);
    }else if(setDiretion == 5){
        setPosition(xPosition_ + 1,  true);
        setPosition(yPosition_ - 1,  false);
    }else if(setDiretion == 6){
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
    shape.setPosition(sf:: Vector2f(getPosition(true),getPosition(false)));
}