#include "Perlin2D.h"


Perlin2D :: Perlin2D (sf:: Vector2f screeenSize,float gradientDimension){
    screeenSize_ = screeenSize;
    gradientDimension_ = gradientDimension;
}



void :: Perlin2D :: setGradients(){
    float gradX = 0;
    for(float i = 0 ; i  < (screeenSize_.x/ gradientDimension_); i++ ){
        float gradY = 0;
        for(float j = 0; j  < (screeenSize_.y/ gradientDimension_); j++ ){
            Point pointA(sf :: Vector2f(gradX, gradY));
            Point pointB(sf :: Vector2f(gradX + gradientDimension_, gradY));
            Point pointC(sf :: Vector2f(gradX, gradY + gradientDimension_));
            Point pointD(sf :: Vector2f(gradX + gradientDimension_, gradY + gradientDimension_));
            pointA.setVecWeight();
            pointB.setVecWeight();
            pointC.setVecWeight();
            pointD.setVecWeight();
            if(j > 0){
                pointA = gradients_.back().getSpecificPoint('c');
                pointB = gradients_.back().getSpecificPoint('d');
                
            }
            if(i > 0){
                int  gradIndex =  gradients_.size() - (screeenSize_.y/ gradientDimension_);
                pointA = gradients_[gradIndex].getSpecificPoint('b');
                pointC = gradients_[gradIndex].getSpecificPoint('d');
            }
            gradY = gradY + gradientDimension_;
            Gradient newGrad({pointA,pointB,pointC, pointD});
            gradients_.push_back(newGrad);
        }
        gradX = gradX + gradientDimension_;
    }
}
void :: Perlin2D :: setScreenPoints(){
    for(int g = 0; g  < gradients_.size(); g++){
        Gradient grad = gradients_[g];
        for(float x = grad.getSpecificPoint('a').getCoordOrVecWeight(true).x; x < grad.getSpecificPoint('b').getCoordOrVecWeight(true).x; x++ ){
            for(float y = grad.getSpecificPoint('a').getCoordOrVecWeight(true).y; y < grad.getSpecificPoint('c').getCoordOrVecWeight(true).y; y++ ){
                Point newPoint(sf :: Vector2f(x,y));
                newPoint.setNoiseValue(grad.getAllPoints());
                screenPoints_.push_back(newPoint);
                
            }
        }
        
    }
}

std :: vector<Point> Perlin2D :: getScreenPoints(){
    return screenPoints_;
}