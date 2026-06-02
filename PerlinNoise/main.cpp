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
    if((noise  <=  120)){
        float  t = noise / 120;
        r = 255 * t;
        g =  255 * (1 -t);
        b =  0.0f;
    } else if( noise <= 240 ){
        float t =  (noise - 120) / 120;
        r =  255 * (1 - t);
        g =  0.0f;
        b =  255 * t;
    }else{
        float t =  (noise - 240) / 120;
        r =  0.0f;
        g =  255 * t;
        b =   255 * (1 - t);
    }
    
    return sf :: Color(r,g,b);
}

sf :: Color waterLevel (float noise, float waterLevel){
    float r = 0.0;
    float  g = 255;
    float b  = 0;
    if(noise <= waterLevel){
        b = variation_0_255(noise);
        g = 0.0;
    }

    return sf :: Color(r,g,b);

}

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
        float colors = shadesOfGray(p.getNoiseValue());
        
        //float colors = black_and_white(p.getNoiseValue());
        //float colors   =  variation_0_255(p.getNoiseValue());
        //sf :: Color pixelColor(colors, colors, colors);
        sf :: Color pixelColor = rgb360(p.getNoiseValue());
        //sf :: Color pixelColor = waterLevel(p.getNoiseValue(),   0.75f);
        img.setPixel(p.getCoordOrVecWeight(true).x,p.getCoordOrVecWeight(true).y, pixelColor);
    }
    
    
    sf :: Texture tex;
    tex.loadFromImage(img);
    sf :: Sprite sprite(tex);
    
    img.saveToFile("/home/bruno/CompSci/ProceduralGeneration/PerlinNoise/Images/example_rgb360.png");
   
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