#ifndef ONEDPERLIN_H
#define ONEDPERLIN_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <random>
#include <iostream>
#include "Point.h"

class OneDPerlin{
private:
float minGradRange_;
float maxGradRange_;
float slopeRange_;
float xAxisSize_;
float yAxisSize_;
std :: vector<Point> gradPoints_;
std :: vector<float> slopePoints_;

public:
OneDPerlin(float minGradRange, float maxGradRange, float slopeRange, float xAxisSize, float yAxisSize);
float randFunction(float minValue, float maxValue);
void settingGradPoints();
void settingSlopePoints();
std :: vector<float> gettingPerlin();
};

#endif