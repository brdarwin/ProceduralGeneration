#include "Point.h"


Point :: Point(){
    pointCoordinates_ = sf :: Vector2i(0,0);
    pointVector_ = sf :: Vector2i(0,0);
    
}

Point :: Point (sf :: Vector2i pointCoordinates){
    pointCoordinates_ = pointCoordinates;
    pointVector_ = sf :: Vector2i(0,0);
    
    
} 



void Point :: setVector(std :: mt19937& seed){
    std:: uniform_int_distribution<> distrib(0, 7);
    int index = distrib(seed);
    pointVector_ = vectors_[index];
    
}

sf ::Vector2i Point :: getVector(){
    return pointVector_;
}

sf ::Vector2i Point :: getPointCoodrinates(){
    return pointCoordinates_;
}

float Point :: calculateDotProduct(Point corner, float grad){
    float distanceX = (pointCoordinates_.x - corner.getPointCoodrinates().x)/grad  ;
    float distanceY = (pointCoordinates_.y - corner.getPointCoodrinates().y)/grad;
  
    return (corner.getVector().x * distanceX) + (corner.getVector().y * distanceY);
 
}

float Point::getPosition(float c0, float c1, bool isHorizontal)
{
    if (isHorizontal)
    {
        return static_cast<float>(pointCoordinates_.x - c0)
             / static_cast<float>(c1 - c0);
    }

    return static_cast<float>(pointCoordinates_.y - c0)
         / static_cast<float>(c1 - c0);
}

float Point :: fade(float t)
{
    return t*t*t*(t*(t*6 - 15) + 10);
}


float Point :: calculateInterpolation(float a, float b, float u){
    return a + (u *(b - a ));
}

void Point ::  setNoiseValue(std:: vector <std :: vector<Point>>  cell){
    Point pointA = cell[0][0];
    Point pointB = cell[1][0];
    Point pointC = cell[0][1];
    Point pointD = cell[1][1];
    float grad = pointB.getPointCoodrinates().x - pointA.getPointCoodrinates().x; 
    float dotA  = calculateDotProduct(pointA, grad);
    float dotB  = calculateDotProduct(pointB, grad);
    float dotC  = calculateDotProduct(pointC, grad);
    float dotD = calculateDotProduct(pointD, grad);
    float horizontal   = getPosition(pointA.getPointCoodrinates().x,pointB.getPointCoodrinates().x,true);
    float vertical   = getPosition(pointA.getPointCoodrinates().y,pointC.getPointCoodrinates().y,false);
    horizontal = fade(horizontal);
    vertical  = fade(vertical);
    float topInterpolation =  calculateInterpolation(dotA,dotB, horizontal);
    float bottomInterpolation =  calculateInterpolation(dotC,dotD, horizontal);
    float noise = calculateInterpolation(topInterpolation, bottomInterpolation, vertical);
    noiseValues_.push_back(noise); 
    

}
float Point :: getNoiseValue(){
    float noiseValue = 0.0f;
    float amplitude = 1.0f;
    for(int i = 0;  i < noiseValues_.size(); i+=1){
        noiseValue = noiseValue + (amplitude * noiseValues_[i]);
        amplitude  = amplitude / 2;
    }
    return noiseValue;
}