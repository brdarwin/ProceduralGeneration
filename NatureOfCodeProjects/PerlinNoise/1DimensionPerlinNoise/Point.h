#ifndef POINT_H
#define POINT_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
class Point{
private:
float pointPosition_;
float slopeValue_;
public:
Point(float pointPosition, float slopeValue);
float getValues(bool isPosition);
};


#endif