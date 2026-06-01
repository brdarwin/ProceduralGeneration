#include "Gradient.h"



Gradient :: Gradient(std :: vector<Point> allPoints){
    allPoints_ = allPoints;
    pointA_ = allPoints[0];
    pointB_ = allPoints[1];
    pointC_ = allPoints[2];
    pointD_ = allPoints[3];
}

Point  Gradient :: getSpecificPoint(char whichPoint){
    if(whichPoint == 'a'){
        return pointA_;
    }
    if(whichPoint == 'b'){
        return pointB_;
    }
    if(whichPoint == 'c'){
        return pointC_;
    }
    if(whichPoint == 'd'){
        return pointD_;
    }
    return pointA_;
}

std :: vector <Point> Gradient ::  getAllPoints(){
    return allPoints_;
}