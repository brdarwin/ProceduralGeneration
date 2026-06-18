#ifndef PERLIN2D_H
#define PERLIN2D_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>
#include "Point.h"
#include <typeinfo>


class Perlin2D{
private:
    sf :: Vector2i screenSize_;
    sf :: Vector2i gradientRange_;
    int numOfOctaves_;
    int colorsSet_;
    std :: vector <std :: vector <Point>> screenPoints_; 
    std :: vector <std :: vector <Point>> gradPoints_;
    std :: mt19937 seed_;
    sf  :: Image noisyImg_;
    

public:
    Perlin2D(std :: vector <int> setOfValues);
    std :: vector <std :: vector <Point>> initializeMatrix(int  xRange, int yRange);
    void setGradient();
    void setInterpolations();
    void colorsSet0To255();
    void colorsSetBlackAndWhite();
    sf :: Color colorsSetRGB360(float noise);
    sf :: Color colorsSetCYM360(float noise);
    void set360(bool isRGB);
    void colorsSetMixRGBCYM360();
    void ruptures();
    sf :: Image getTheNoise();
    float  getScreenPointNoise(int x, int y);

};

#endif