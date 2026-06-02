#include "Point.h"


Point :: Point (){
    pointCoordinates_ = sf :: Vector2f(0.0f, 0.0f);
    vectorWeight_ = sf :: Vector2f(0.0f, 0.0f);
    noiseValue_ = 0.0f;
}

Point :: Point (sf :: Vector2f pointCoordinates){
    pointCoordinates_ = pointCoordinates;
   
}

float :: Point :: randomFunction(float min, float max ){
   

    
    std :: random_device rd;
    std :: mt19937 gen(rd());
    
    std:: uniform_real_distribution<float> distrib(min, max);
    return  distrib(gen);
    

}

void :: Point :: setVecWeight(){
    float angle = randomFunction(0.f, 2.f * 3.14159265f);
    vectorWeight_.x = std :: sin(angle);
    vectorWeight_.y = std :: cos(angle);
    
}

sf :: Vector2f Point :: getCoordOrVecWeight(bool isCoordinates){
    if(isCoordinates){
        return pointCoordinates_;
    }
    return vectorWeight_;
}

float :: Point :: setInfluence(Point gradPoint){
    sf :: Vector2f gradWeight = gradPoint.getCoordOrVecWeight(false);
    sf :: Vector2f gradCoord  = gradPoint.getCoordOrVecWeight(true);
    return gradWeight.x * (pointCoordinates_.x - gradCoord.x)  + gradWeight.y * (pointCoordinates_.y - gradCoord.y);
    
    
}

float :: Point :: setInterpolationFactor(Point fstGPoint, Point sndGPoint, bool isHorizontal){

    sf :: Vector2f fstCoord = fstGPoint.getCoordOrVecWeight(true);
    sf :: Vector2f sndCoord = sndGPoint.getCoordOrVecWeight(true);
    if(isHorizontal){
        return (pointCoordinates_.x  - fstCoord.x) / (sndCoord.x - fstCoord.x);
    }
    return (pointCoordinates_.y  - fstCoord.y) / (sndCoord.y - fstCoord.y);
}

float :: Point :: setInterpolation(float a, float b, float f){
    return a + f * (b - a);
}
float :: Point ::  fadingFucntion(float t)
{
    return t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f);
}
void  :: Point :: setNoiseValue(std :: vector<Point> vecGradPoints){
    Point topLeft = vecGradPoints[0];
    Point topRight = vecGradPoints[1];
    Point bottomLeft = vecGradPoints[2];
    Point bottomRight = vecGradPoints[3];
    float topLefInfluence = setInfluence(topLeft);
    float topRightInfluence = setInfluence(topRight);
    float bottomLefInfluence = setInfluence(bottomLeft);
    float bottomRightInfluence = setInfluence(bottomRight);
    float topT = setInterpolationFactor(topLeft,topRight, true);
    float bottomT = setInterpolationFactor(bottomLeft,bottomRight, true);
    float u = setInterpolationFactor(topLeft,bottomLeft, false); //vertical factor
    topT = fadingFucntion(topT);
    bottomT = fadingFucntion(bottomT);
    u = fadingFucntion(u);
    float topInterpolation = setInterpolation (topLefInfluence, topRightInfluence, topT);
    float bottomInterpolation = setInterpolation(bottomLefInfluence, bottomRightInfluence, bottomT );
    noiseValue_ = setInterpolation(topInterpolation, bottomInterpolation, u);


    
}

void :: Point :: setNoiseValue(float noise){
    noiseValue_ = noise;
}

float :: Point ::getNoiseValue(){
    return noiseValue_;
}