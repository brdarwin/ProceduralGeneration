#ifndef PERLIN2D_H
#define PERLIN2D_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>
#include "Point.h"
#include "Gradient.h"


class Perlin2D{
private:
    sf:: Vector2f screeenSize_;
    float gradientDimension_;
    std :: vector <Point> screenPoints_;
    std :: vector <Gradient> gradients_;

public:
    Perlin2D(sf:: Vector2f screeenSize,float gradientDimension );
    void setGradients();
    void setScreenPoints();
    std :: vector <Point> getScreenPoints();



};

#endif