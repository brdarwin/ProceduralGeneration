#include "Walker.h"
 


Walker :: Walker(sf :: Vector2f screenSize, sf :: Color walkerColor, float usualRange){
    screenSize_ = screenSize;
    position_.x = screenSize_.x / 2;
    position_.y = screenSize_.y/ 2;
    usualRange_ = usualRange;
    movementRange_ = usualRange;
    maxLevyFkightRange_ =  20 * usualRange_;
    minLevyFlightRange_ =  10 * usualRange_;
    std :: random_device rd;
    std :: mt19937 gen(rd());
    seed_ = gen;
    noises_ = getNoise();
    
    
    
}


 std :: vector<std::vector<float>> Walker :: getNoise( ){
    std :: vector<int> setOfValues  = {256,256,256,8,0};
    Perlin perlin(setOfValues);
    perlin.setOctaves();
    perlin.setGradCells();
    perlin.settingNoise();
    
    return perlin.getNoise();
 } 


template<typename T> T Walker :: randomFunction(T min, T max, bool isFloat){
   

    
    
    if(isFloat){
        std:: uniform_real_distribution<float> distrib(min, max);
        return  distrib(seed_);
    }

    std:: uniform_int_distribution<> distrib(min, max);
    return  distrib(seed_);

}

void Walker :: movementRange(){
    if(rangeIndex_ < movementRange_){
        rangeIndex_ +=1;
    }else{
        setDirection_ = randomFunction(0, 7,false);
        movementRange_ = usualRange_;
        if(randomFunction(0,100, false) == 1){
            movementRange_ = maxLevyFkightRange_;
        }
        rangeIndex_ = 0;

    }

} 



void Walker :: setSteps(){
    iX_ += randomFunction(-1, 1, false);
    iX_ += randomFunction(-1, 1, false);
    if(iX_ < 0) {iX_ = 0;}
    else if(iX_ > 255){iX_ = 255;}
    if(iY_ < 0) {iY_ = 0;}
    else if(iY_ > 255){iY_ = 255;}
    float noise = noises_[iX_][iY_];
    float angle = noise * M_PI;
    
    switch (setDirection_)
    {
    case 0:
        position_.x += cos(angle);
        break;
    case 1: 
        position_.y += sin(angle);
        break;
    case 2: 
        position_.x -= cos(angle);
        
        break;
    case 3: 
        position_.y -= sin(angle);
        
        break;
    case 4: 
        position_.x += cos(angle);
        position_.y += sin(angle);
        break;
    case 5: 
        position_.x += cos(angle);
        position_.y -= sin(angle);
        break;
    case 6: 
        position_.x -= cos(angle);
        position_.y -= sin(angle);
        break;
    case 7: 
        position_.x -= cos(angle);
        position_.y += sin(angle);
        break;
    default:
        break;
    } 
   
}

void Walker :: eliminatingBorders(){
    if(position_.x > screenSize_.x){
        position_.x = 0;
    }else if(position_.x < 0){
        position_.x = screenSize_.x;
    }

    if(position_.y > screenSize_.y){
        position_.y = 0;
    }else if(position_.y < 0){
        position_.y = screenSize_.y;
    }
    
}


sf :: Vector2f Walker :: getPosition(){

    return position_;
}






    
    

    



