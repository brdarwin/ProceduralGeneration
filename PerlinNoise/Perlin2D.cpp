#include "Perlin2D.h"


Perlin2D :: Perlin2D (sf:: Vector2f screeenSize,float maxGradient, float minGradient){
    screeenSize_ = screeenSize;
    maxGradient_ = maxGradient;
    minGradient_ = minGradient;
    numberOfOctaves_ = maxGradient_ / minGradient_;
}



std :: vector <Gradient> Perlin2D :: setGradients(float grad){
    std :: vector <Gradient> gradients;
    float gradX = 0;
    for(float i = 0 ; i  < (screeenSize_.x/ grad); i++ ){
        float gradY = 0;
        for(float j = 0; j  < (screeenSize_.y/ grad); j++ ){
            Point pointA(sf :: Vector2f(gradX, gradY));
            Point pointB(sf :: Vector2f(gradX + grad, gradY));
            Point pointC(sf :: Vector2f(gradX, gradY + grad));
            Point pointD(sf :: Vector2f(gradX + grad, gradY + grad));
            pointA.setVecWeight();
            pointB.setVecWeight();
            pointC.setVecWeight();
            pointD.setVecWeight();
            if(j > 0){
                pointA = gradients.back().getSpecificPoint('c');
                pointB = gradients.back().getSpecificPoint('d');
                
            }
            if(i > 0){
                int  gradIndex =  gradients.size() - (screeenSize_.y/ grad);
                pointA = gradients[gradIndex].getSpecificPoint('b');
                pointC = gradients[gradIndex].getSpecificPoint('d');
            }
            gradY = gradY + grad;
            Gradient newGrad({pointA,pointB,pointC, pointD});
            gradients.push_back(newGrad);
        }
        gradX = gradX + grad;
    }
    return gradients;
}
std :: vector <Point> Perlin2D :: setPoints(std :: vector <Gradient> gradients){
    std :: vector <Point> points;
    for(int g = 0; g  < gradients.size(); g++){
        Gradient grad = gradients[g];
        for(float x = grad.getSpecificPoint('a').getCoordOrVecWeight(true).x; x < grad.getSpecificPoint('b').getCoordOrVecWeight(true).x; x++ ){
            for(float y = grad.getSpecificPoint('a').getCoordOrVecWeight(true).y; y < grad.getSpecificPoint('c').getCoordOrVecWeight(true).y; y++ ){
                Point newPoint(sf :: Vector2f(x,y));
                newPoint.setNoiseValue(grad.getAllPoints());
                points.push_back(newPoint);
                
            }
        }
        
    }
    return points;
}

void :: Perlin2D :: setOctavePoints (){
    for(float octave = minGradient_; octave <= maxGradient_ ; octave = octave * 2){
        std :: vector <Gradient> gradients = setGradients(octave);
        std :: vector <Point>   points = setPoints(gradients);
        octavePoints_.push_back(points);
    }

};
void :: Perlin2D :: setScreenPoints(){
    
    
    for(int i = 0; i < octavePoints_[0].size();i++ ){
        Point newPoint = octavePoints_[0][i];
        float amplitude = 1.0f;
        float noise  = 0.0f;
        for(int j = 0; j <  octavePoints_.size(); j++){
            Point p = octavePoints_[j][i];
            noise = noise + amplitude *  p.getNoiseValue();
            amplitude = amplitude  / 2;
        }
        newPoint.setNoiseValue(noise);
        screenPoints_.push_back(newPoint);
    }
}

std :: vector <Point> Perlin2D :: getScreenPoints(){
    return screenPoints_;
}