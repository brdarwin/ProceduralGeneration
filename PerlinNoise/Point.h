#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>
class Point{
private:
    sf :: Vector2f pointCoordinates_;
    sf :: Vector2f vectorWeight_;
    float noiseValue_;
public:
    Point();
    Point(sf :: Vector2f pointCoordinates);
    float randomFunction(float min, float max);
    float setInfluence(Point gradPoint);
    void setVecWeight();
    sf :: Vector2f getCoordOrVecWeight(bool isCoordinates);
    float setInterpolationFactor(Point fstGPoint, Point sndGPoint, bool isHorizontal);
    float setInterpolation(float a, float b, float f);
    float fadingFucntion(float t);
    void setNoiseValue(std :: vector<Point> vecGradPoints);
    void setNoiseValue(float noise);
    float getNoiseValue();

};

#endif