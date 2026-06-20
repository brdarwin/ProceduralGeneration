#ifndef WALKER_H
#define WALKER_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include <random>
#include "/home/bruno/CompSci/ProceduralGeneration/PerlinNoise_2.0/Perlin.h"

class Walker{
    private:
    sf :: Vector2f position_;
    sf :: Vector2f screenSize_;
    sf :: Color walkerColor_;
    float  movementRange_;
    float  usualRange_;
    float  minLevyFlightRange_;
    float  maxLevyFkightRange_;
    float  rangeIndex_ = 0;
    int    levyFlightProbability_ = 1;
    std :: mt19937 seed_;
    std :: vector<std::vector<float>> noises_;
   
    int iX_ = 0;
    int iY_ = 0;
    int setDirection_ = 0;
    public:
    Walker(sf :: Vector2f screenSize, sf :: Color walkerColor, float usualRange);
    std :: vector<std::vector<float>> getNoise();
    template <typename T> T randomFunction(T min, T max, bool isFloat);
    void movementRange();
    void setSteps();
    void eliminatingBorders();
    sf :: Vector2f getPosition();
    
    

    
    

};

#endif
