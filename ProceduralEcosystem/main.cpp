#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "/home/bruno/CompSci/ProceduralGeneration/PerlinNoise_2.0/Perlin.h"

void setLandSea(sf :: Image *img, std :: vector<std:: vector<float>> points){
    for(int x = 0; x < img -> getSize().x; x+=1){
        for(int y = 0; y < img -> getSize().y; y+=1){
            float colorValue  = (1 + points[x][y])/2;
            float r = 0, g = 0, b = 0;
            
                
                if(colorValue  < 0.2){
                    b = 127.5  * colorValue/0.2;
                }else if(colorValue < 0.4){
                    b = 127.5 + (127.5 * ((colorValue - 0.2) / 0.2));
                }else if(colorValue < 0.5){
                    g = 127.5 + (127.5 * ((colorValue - 0.4) / 0.1));  b = 255 ; 
                }else if(colorValue < 0.6){
                    g = 127.5 + (127.5 * ((colorValue - 0.5) / 0.1));
                    r = 127.5 - (127.5 * ((colorValue - 0.4) / 0.1));
                }else{
                    g = 127.5 * ((colorValue - 0.6) / 0.3);
                }
                
            
            sf :: Color pxColor(r, g, b);
            img -> setPixel(x,y, pxColor);
        }
    }
   
    
}

std :: vector<std :: vector<float>> setMatrix(int maxX, int  maxY){
    std :: vector<std :: vector<float>> matrix;
    for(int x = 0; x < maxX; x+=1){
        std :: vector <float> points;
        for(int y = 0; y < maxY; y+=1){
            points.push_back(0.0f);
        }
        matrix.push_back(points);
    }
    return matrix;
}

//Implement Later;
void setLatitude(std :: vector <std:: vector<float>> *noise){
    for(int x = 0; x < noise -> size(); x+=1){
        for(int y = 0; y <  noise[x].size(); y+=1 ){
            float latRange = noise[x].size();
            float amplitude = latRange / 4;
            if((y < amplitude) || (y > (latRange - amplitude))){// Polar
               (*noise)[x][y] = 6.0f;
            } else if((y < amplitude * 2) || (y > (latRange - amplitude * 2))){// boreal
               (*noise)[x][y] = 12.0f ;
            } else if((y < amplitude * 3) || (y > (latRange - amplitude * 3))){// temperate
               (*noise)[x][y] = 24.0f;
            }else{//tropical;
                (*noise)[x][y] = 35.0f;
            }
        }
    }

}


int main(int argc, char* argv[]){
    std :: vector<int> setOfValues;
    setOfValues.push_back(256); //Screen Width
    setOfValues.push_back(setOfValues[0]); //screen Height
    setOfValues.push_back(setOfValues[0]);// maxGradient
    setOfValues.push_back(8); // minGradient)
    
    if(argc > 1){
        for(int i =  1; i < argc; i+=1){
            setOfValues[i - 1] = std :: stoi(argv[i]);
        }
    }
    
    Perlin *ecosystem = new Perlin(setOfValues);
    ecosystem ->setOctaves();
    ecosystem ->setGradCells();
    ecosystem ->settingNoise();
    sf :: Image ecoImg = ecosystem -> getNoiseImg();
    std :: vector <std :: vector<float>> temperature = setMatrix(setOfValues[0], setOfValues[1]);
    setLandSea(&ecoImg, ecosystem -> getNoise());
    ecoImg.saveToFile("/home/bruno/CompSci/ProceduralGeneration/ProceduralEcosystem/Example.png");
    
    delete ecosystem;
    return 0;
}