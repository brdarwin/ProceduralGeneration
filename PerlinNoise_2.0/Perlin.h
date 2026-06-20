#ifndef PERLIN_H
#define PERLIN_h
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>

class Perlin{
private:
    sf :: Vector2f screenSize_;
    int maxGradient_;
    int minGradient_;
    int numOfGradients_;
    int setOfColors_;
    sf :: Image myNoise_;
    std  :: vector <std :: vector<float>> noises_;
    std :: mt19937 seed_;
    std :: vector<sf :: Vector2i> arrayVectors_ = {
        sf :: Vector2i(0,1),sf :: Vector2i(0,-1),
        sf :: Vector2i(1,0),sf :: Vector2i(1,-1),
        sf :: Vector2i(1,1),sf :: Vector2i(-1,-1),
        sf :: Vector2i(-1,1),sf :: Vector2i(-1,0),
    };
    std  :: vector <std :: vector<sf :: Vector2i>> gradients_;
    std  :: vector <int> octaves_;
    std  :: vector<std :: vector< std :: vector<int>>> cells_;
    std  :: vector<float> amplitude_;
    
public:
    Perlin (std :: vector<int> setOfValues);
    std  :: vector <std :: vector<float>> noisesInitializer();
    template <typename T> T randomFunction(T min, T max, bool isFloat);
    std  :: vector <std :: vector<sf :: Vector2i>> gradientsInitializer();
    void setOctaves();
    void setGradCells();
    sf :: Vector2i getVector(int x, int y);
    float dotProduct (sf :: Vector2i vec, sf ::Vector2i vecCoordinates ,sf ::Vector2i pointCoordinates, float grad);
    float getPosition(float corner0, float corner1, float pointLocation);
    float smoothStep(float value);
    float interpolation(float a, float b, float u);
    void settingNoise();
    std  :: vector <std :: vector<float>> getNoise();
    void setNoiseImg();
    sf :: Image getNoiseImg();
    

};




#endif