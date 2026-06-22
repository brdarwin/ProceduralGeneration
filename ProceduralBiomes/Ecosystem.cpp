#include "Ecosystem.h"

Ecosystem :: Ecosystem(sf :: Vector2i screenSize){
    screenSize_ = screenSize;
    EcosystemImg_.create(screenSize_.x, screenSize_.y);
    terrainNoise_ = setNoise({screenSize_.x, screenSize_.y, 512, 128});
    riverNoise_   = setNoise({screenSize_.x, screenSize_.y, 512, 128});
    humidityNoise_ = setNoise({screenSize_.x, screenSize_.y, 512, 128});
}

std :: vector <std :: vector<float>> Ecosystem :: setNoise(std :: vector<int> setOfValues){
    Perlin  perlin(setOfValues);
    perlin.setOctaves();
    perlin.setGradCells();
    perlin.settingNoise();
    return perlin.getNoise();

}

void Ecosystem :: setTerrain(){
    for(int x = 0; x < EcosystemImg_.getSize().x; x+=1){
        for(int y = 0; y < EcosystemImg_.getSize().y; y+=1){
            float humidityNoise =  8 *  ( (1 + humidityNoise_[x][y]) / 2);
            float r = 0, g = 0, b = 0;
            if(humidityNoise < 1){//desert 
                g = r = 255;
            }else if (humidityNoise < 2){//desert scrubs
                g = 255; r = 223;
            }else if (humidityNoise < 3){//thorn woodland;
                g = 255; r = 191; 
            }else if (humidityNoise < 4){// very dry forest;
                g = 255; r = 158;
            }else if (humidityNoise < 5){// dry forest;
                g = 255; r = 116;
            }else if (humidityNoise < 6){// moist forest;
                g = 255; r = 94;
            }else if (humidityNoise < 7){// wet forest;
                g = 255; r = 61;
            }else{// rain forest;
                g =255;
            }
            sf :: Color pxColor(r,g,b);
            EcosystemImg_.setPixel(x,y,pxColor);
        }
    }
}

void Ecosystem :: setRivers(){
    for(int x = 0; x < EcosystemImg_.getSize().x; x+=1){
        for(int y = 0; y < EcosystemImg_.getSize().y; y+=1){
            float riverNoise = riverNoise_[x][y];
            float humidityNoise =  8 *  ( (1 + humidityNoise_[x][y]) / 2);
            float  amplitude = 0.0f;
            if(humidityNoise < 1 ){//super-arid;
                amplitude = 0.01;
            }else if(humidityNoise < 2){//perarid;
                amplitude = 0.02;
            }else if(humidityNoise < 3){//arid;
                amplitude = 0.03;
            }else if(humidityNoise < 4){//semi-arid;
                amplitude = 0.04;
            }else if(humidityNoise < 5){//sub-humid;
                amplitude = 0.05;
            }else if(humidityNoise < 6){//humid;
                amplitude = 0.06;
            }else if(humidityNoise < 7){//perhumind;
                amplitude = 0.07;
            }else{//super-humid
                amplitude = 0.08;
            }   

            if(riverNoise > (-1) * amplitude  && riverNoise < amplitude){
               float r = 0, g = 0, b = 255;
               sf :: Color pxColor(r,g,b);
               EcosystemImg_.setPixel(x,y,pxColor);
            }
            
        }
    }
}

 sf :: Image Ecosystem :: getEcosystemImg(){
    return EcosystemImg_;
 }