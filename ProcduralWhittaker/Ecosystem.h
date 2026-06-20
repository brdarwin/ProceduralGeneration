#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "/home/bruno/CompSci/ProceduralGeneration/PerlinNoise_2.0/Perlin.h"
class Ecosystem {
private:
    std :: vector < std:: vector <float>> temperature_;
    std :: vector < std:: vector <float>> humidity_;
    sf  :: Image ecosystemImage_;
    sf :: Vector2i screenSize_;
public:
   Ecosystem (sf :: Vector2i screenSize);
   std :: vector<std::vector<float>>  getNoise(std :: vector<int> setOfValues );
   void  settingBiomes();
   sf :: Image getEcosystemImg();


};

#endif

