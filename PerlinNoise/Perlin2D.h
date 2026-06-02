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
    float maxGradient_;
    float minGradient_;
    int   numberOfOctaves_;
    //std :: vector <Gradient> gradients_;
    std :: vector <std :: vector <Point> >  octavePoints_;
    std :: vector <Point> screenPoints_;

public:
    Perlin2D(sf:: Vector2f screeenSize, float gmaxGradient, float minGradient );
    std :: vector <Gradient> setGradients(float grad);
    std :: vector <Point> setPoints(std :: vector <Gradient> grad);
    void setOctavePoints();
    void setScreenPoints();
    std :: vector <Point> getScreenPoints();



};

#endif