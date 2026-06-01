#ifndef GRADIENT_H
#define GRADIENT_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>
#include "Point.h"
class Gradient{
private:
    Point pointA_;
    Point pointB_;
    Point pointC_;
    Point pointD_;
    std :: vector<Point> allPoints_;
public: 
    Gradient(std :: vector<Point> allPoints);
    Point getSpecificPoint(char whichPoint);
    std :: vector <Point> getAllPoints();

};


#endif