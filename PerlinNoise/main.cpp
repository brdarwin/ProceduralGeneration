#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Perlin2D.h"
#include "Point.h"
#include "Gradient.h"



int main(){
    float maxSizeX = 1000;
    float maxSizeY = 1000;
    int   gradientDimension = 100;
    Perlin2D  myPerlin(sf :: Vector2f(maxSizeX, maxSizeY),gradientDimension);
    myPerlin.setGradients();
    myPerlin.setScreenPoints();
    std :: vector<Point> screenPoints = myPerlin.getScreenPoints();
    sf:: RenderWindow theWindow(sf::VideoMode(maxSizeX,maxSizeY),  "2D Pelrlin Noise");
    theWindow.setFramerateLimit(60);
    sf :: Image img;
    img.create(maxSizeX,maxSizeY);
    for(int i = 0; i < screenPoints.size(); i ++){
        Point p = screenPoints[i];
        float colors =225;
        //float colors = 127 + 127 * p.getNoiseValue();
        if (p.getNoiseValue() > 0){
            colors = 000;
        }
        sf :: Color pixelColor(colors, colors, colors);
        img.setPixel(p.getCoordOrVecWeight(true).x,p.getCoordOrVecWeight(true).y, pixelColor);
    }
    sf :: Texture tex;
    tex.loadFromImage(img);
    sf :: Sprite sprite(tex);

     while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        theWindow.clear();
        theWindow.draw(sprite);
        theWindow.display();
        
	    
    }
    return 0;
}