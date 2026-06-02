#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Perlin2D.h"
#include "Point.h"
#include "Gradient.h"

float shadesOfGray (float noise){
    return 127 + 127 *  noise;
}

float variation_0_255(float noise){
    return  255  * ((1 - noise) / 2);
}

float black_and_white (float noise){
    if(noise > 0){
        return 000;
    }
    return 255;
}

sf :: Color rgb360(float noise){
    noise  =  360 *  ((1 - noise) / 2);
    float r, g, b;
    if(0 < noise <=  120){
        r = (255 * noise) / 120;
        g =  255 - ((255 * noise) / 120);
        b =  0.0f;
    } else if( 120 < noise <= 240 ){
        r =  255 - ((255 * noise) / 120);
        g =  0.0f;
        b =  (255 * noise) / 120;
    } else if( (240 < noise <= 359)  || noise == 0){
        r =  0.0f;
        g =  (255 * noise) / 120;
        b =   255 - ((255 * noise) / 120);
    }else{
        r = 255;
        b = 255;
        g = 255;
    }
    
    return sf :: Color(r,g,b);
}

int main(){
    float maxSizeX = 1000;
    float maxSizeY = 1000;
    int   gradientDimension = 1000;
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
        //float colors = shadesOfGray(p.getNoiseValue());
        //float colors = black_and_white(p.getNoiseValue());
        //float colors   =  variation_0_255(p.getNoiseValue());
        //sf :: Color pixelColor(colors, colors, colors);
        sf :: Color pixelColor = rgb360(p.getNoiseValue());
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