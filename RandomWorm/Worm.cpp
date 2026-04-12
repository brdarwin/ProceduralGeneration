#include "Worm.h"
#include "Body.h"
#include <iostream>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>  

 Worm:: Worm(Body headBody, int  wormSize,float  maxSizeX,float  maxSizeY, float  movementRange){
    wormBody_.push_back(headBody);
    wormSize_ = wormSize;
    maxSizeX_ = maxSizeX;
    maxSizeY_ = maxSizeY;
    movementRange_ = movementRange;
    movementRangeIndex_ = movementRange;
}

int Worm :: randomFunction(int min, int max){
    

    
    std :: random_device rd;
    std :: mt19937 gen(rd());
    std:: uniform_int_distribution<> distrib(min, max);

    
    return distrib(gen);

}

void :: Worm :: setWormBody(bool movingBody){
    for(int  i = 1;  i < wormSize_; i++){
        if(movingBody == true){
            wormBody_[i].setPreviousBodyPosition(wormBody_[i].getBodyPosition());
            wormBody_[i].setBodyPosition(wormBody_[i - 1].getPreviousBodyPosition());
        }else{
            Body bodyPart(wormBody_[i - 1].getBodyPosition(),sf:: Color(randomFunction(25,255),randomFunction(25,255),randomFunction(25,255)), 1.0f);
            wormBody_.push_back(bodyPart);
        }
        
    }
}

void Worm:: setMovementRange(){
    if(movementRangeIndex_  >= movementRange_){
        setDirection_ = randomFunction(0,7);
        movementRangeIndex_ = 0;
    }else{
        movementRangeIndex_ = movementRangeIndex_ + 1;
    }
}

void Worm :: bodyHead(std:: vector<float> newPosition){
    if(wormBody_[0].getPreviousBodyPosition() == newPosition){
        setDirection_ = randomFunction(0,7);
        nextStep();
    }else{
        wormBody_[0].setPreviousBodyPosition(wormBody_[0].getBodyPosition());
        wormBody_[0].setBodyPosition(newPosition);    
    }
    
}

void Worm  :: nextStep(){
    
     


    
    std :: vector <float> newPostion = wormBody_[0].getBodyPosition();

    
    if(setDirection_ == 0){ 
        newPostion[0] = newPostion[0] + 1;
        
    }else if(setDirection_ == 1){ 
        newPostion[0] = newPostion[0] - 1;
        
    }else if(setDirection_ == 2){ 
        newPostion[1] = newPostion[1] - 1;
       
    }else if(setDirection_ == 3) {
        newPostion[1] = newPostion[1] + 1;
    }else if(setDirection_ == 4){
        newPostion[0] = newPostion[0] + 1;
        newPostion[1] = newPostion[1] + 1;
    }else if(setDirection_ == 5){
        newPostion[0] = newPostion[0] - 1;
        newPostion[1] = newPostion[1] + 1;
    }else if(setDirection_ == 6){
        newPostion[0] = newPostion[0] + 1;
        newPostion[1] = newPostion[1] - 1;
    }else{
        newPostion[0] = newPostion[0] - 1;
        newPostion[1] = newPostion[1] - 1;
    }
    bodyHead(newPostion);
    
}

void Worm:: eliminatingBorders(){
    std:: vector  <float> currentPosition = wormBody_[0].getBodyPosition();
    if(currentPosition[0] > maxSizeX_){
        currentPosition[0] = 0;
        
    } else if(currentPosition[0] < 0){
        currentPosition[0] = maxSizeX_;
    }

    if(currentPosition[1] > maxSizeY_){
        currentPosition[1] = 0;
    } else if(currentPosition[1] < 0){
        currentPosition[1] = maxSizeY_;
    }
    wormBody_[0].setBodyPosition(currentPosition);
}

int Worm :: getWormSize(){
    return  wormSize_;
}

void Worm :: getWormBody(sf :: CircleShape& wormBody, int i){
    wormBody.setFillColor(wormBody_[i].getBodyColor());
    std :: vector <float> newPosition = wormBody_[i].getBodyPosition();
    wormBody.setPosition(sf:: Vector2f(newPosition[0], newPosition[1]));
    wormBody.setRadius(wormBody_[i].getBodyRadius());
}