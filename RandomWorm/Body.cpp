#include "Body.h"
#include <iostream>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>  


Body :: Body(std:: vector<float> bodyPosition, sf:: Color bodyColor, float bodyRadius){
    bodyPosition_ = bodyPosition;
    previousBodyPosition_ = bodyPosition;
    bodyColor_ = bodyColor;
    bodyRadius_ = bodyRadius;

} 

void Body:: setBodyPosition(std:: vector<float> bodyPosition){
    bodyPosition_ = bodyPosition;
}

std :: vector<float> Body::  getBodyPosition(){
    return bodyPosition_;
}

std :: vector<float> Body:: getPreviousBodyPosition(){
    return previousBodyPosition_;
}

void Body :: setPreviousBodyPosition(std :: vector<float> previousBodyPosition){
    previousBodyPosition_ = previousBodyPosition;
}

sf :: Color  Body :: getBodyColor(){
    return bodyColor_;
}

float Body :: getBodyRadius(){
    return bodyRadius_;
}