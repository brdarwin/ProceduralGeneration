#include "Ecosystem.h"


Ecosystem :: Ecosystem(sf :: Vector2i screenSize){
    screenSize_  = screenSize;
    ecosystemImage_.create(screenSize_.x,screenSize_.y);
    temperature_ = getNoise({screenSize_.x,screenSize_.y,512,32,0});
    humidity_    = getNoise({screenSize_.x,screenSize_.y,512,32,0});
}

std :: vector<std::vector<float>> Ecosystem :: getNoise(std :: vector<int> setOfValues ){
    
    Perlin2D perlin(setOfValues);
    perlin.setGradient();
    perlin.setInterpolations();
    std :: vector<std::vector<float>> matrix;
    for(int x = 0; x < screenSize_.x; x+=1){
        std :: vector <float> noises;
        for(int y = 0; y < screenSize_.y; y+=1 ){
            noises.push_back(perlin.getScreenPointNoise(x,y));
        }
        matrix.push_back(noises);
    }
    
    return matrix;
} 

void Ecosystem :: settingBiomes(){
    for(int x = 0; x < ecosystemImage_.getSize().x; x+=1){
        for(int y= 0; y < ecosystemImage_.getSize().y; y+=1){
            float temp =  50 * ((1 + temperature_[x][y])/ 2 );
            float hum  = 500  *((1 + humidity_[x][y])/ 2 );
            float r =0 , g = 0 , b = 0;
            if(temp < 15 && hum < 100) {
                // tundra;
                r = 127.5;
                g = 255;
            }else if(temp < 35 && hum < 17 ){
                // grassland desert;
                r = 255;
                g = 127.5;
            }else if(temp < 40 && hum < 120){
                // woodland/srhubland;
                r = 60.5;
                g = 255;

            }else if(temp < 23 && hum < 200){
                // taiga;
                g = 198;
                
            }else if(temp < 30 && hum < 200){
                // temperate deciduous forest
                g = 255;
                
            }else if(temp < 42 && hum < 340){
                // temperate rain forest
                g = 255;
                b = 60.5;
                
            }else if(temp < 50 && hum < 15){
                // subtropical desert
                r = 255;
                g = 255;
            }else if(temp < 45 && hum < 100){
                //savanna
                r = 186;
                g = 160;
                b = 79;
               
            }else if(temp < 45 && hum < 260){
                
                // tropical seasonal rain forest;
                g = 190.5;
                b = 127.5;
            }else if(temp < 45 && hum < 500){
                // tropical rain forest
                g = 127.5;
            }
            sf :: Color pxColor(r, g, b);
            ecosystemImage_.setPixel(x,y,pxColor);
        };
    }
}

sf :: Image Ecosystem :: getEcosystemImg(){
    return ecosystemImage_;
}