#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "/home/bruno/CompSci/ProceduralGeneration/PerlinNoise_2.0/Perlin.h"

class Ecosystem {
private:
    sf :: Vector2i screenSize_;
    std :: vector <std :: vector<float>> terrainNoise_; 
    std :: vector <std :: vector<float>> riverNoise_;
    std :: vector <std :: vector<float>> humidityNoise_;
    sf :: Image EcosystemImg_;

public:
    Ecosystem (sf :: Vector2i screenSize);
    std :: vector <std :: vector<float>> setNoise( std :: vector<int> setOfValues);
    void setTerrain();
    void setRivers();
    sf :: Image getEcosystemImg();

};


#endif
