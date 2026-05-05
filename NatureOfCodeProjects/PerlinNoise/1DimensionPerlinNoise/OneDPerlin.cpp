#include "SFML/Graphics.hpp"
#include <vector>
#include <random>
#include <iostream>
#include "Point.h"
#include "OneDPerlin.h"


 OneDPerlin :: OneDPerlin(float minGradRange, float maxGradRange, float slopeRange, float xAxisSize, float yAxisSize){
    minGradRange_ = minGradRange;
    maxGradRange_ = maxGradRange;
    slopeRange_= slopeRange;
    xAxisSize_ = xAxisSize;
    yAxisSize_ = yAxisSize;
 }

float :: OneDPerlin :: randFunction(float minValue, float maxValue){
    

    std :: random_device rd;
    std :: mt19937 gen(rd());
    std:: uniform_real_distribution<float> distrib(minValue, maxValue);
    return  distrib(gen);
    
}



void :: OneDPerlin :: settingGradPoints(){
    for(float i = 0; i <= xAxisSize_; i = i + randFunction(minGradRange_,maxGradRange_)){
        
        gradPoints_.push_back(Point(i,randFunction(-1,1)));

    }
}

void :: OneDPerlin :: settingSlopePoints(){
    for(int i = 0; i < gradPoints_.size() - 1;i ++ ){
        float previousPoint = gradPoints_[i].getValues(true);
        float previousSlope = gradPoints_[i].getValues(false);
        float nextPoint = gradPoints_[i + 1].getValues(true);
        float nextSlope = gradPoints_[i + 1].getValues(false);
        for(float j= previousPoint; j <= nextPoint; j = j + slopeRange_){
            float slopePoint = j;
            float distPrevious = previousSlope * (slopePoint - previousPoint); 
            float distNext = nextSlope *(nextPoint - slopePoint);
            //float t = (slopePoint - previousPoint) / (nextPoint - previousPoint);
            //float u = t * t * (3 - 2 * t); 
            float u = (slopePoint - previousPoint) / (nextPoint - previousPoint);
            float value = (1 - u) * distPrevious + u * distNext;
            slopePoints_.push_back(value);
            
        }
    }

}
std :: vector<float>  OneDPerlin :: gettingPerlin(){
    return  slopePoints_;
}