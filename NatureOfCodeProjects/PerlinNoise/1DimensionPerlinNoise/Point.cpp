#include "Point.h"
#include <iostream>


Point ::  Point(float pointPosition, float slopeValue){
    pointPosition_ = pointPosition;
    slopeValue_    = slopeValue;
}

float Point ::  getValues(bool isPosition){
    if(isPosition){
        return pointPosition_;
    }
    return slopeValue_;
}