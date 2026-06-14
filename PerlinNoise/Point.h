#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>

class Point{
private:
    sf :: Vector2i pointCoordinates_;
    sf :: Vector2i pointVector_;
    std :: vector <float> noiseValues_;
    const std:: vector <sf :: Vector2i> vectors_ = {
        sf :: Vector2i(0, 1),
        sf :: Vector2i(0, -1),
        sf :: Vector2i(1, 0),
        sf :: Vector2i(1, -1),
        sf :: Vector2i(1, 1),
        sf :: Vector2i(-1, 0),
        sf :: Vector2i(-1, 1),
        sf :: Vector2i(-1, -1),
    };
  
public:
    Point();
    Point(sf :: Vector2i pointCoordinates);
    void setVector(std :: mt19937& seed);
    sf ::Vector2i  getVector();
    sf ::Vector2i  getPointCoodrinates();
    void setNoiseValue(std:: vector <std :: vector<Point>>  cell);
    float calculateDotProduct(Point corner, float grad);
    float getPosition(float c0, float c1, bool isHorizontal );
    float calculateInterpolation(float a, float b, float u);
    float fade(float t);
    float getNoiseValue();
    

};

#endif