#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "OneDPerlin.h"





int main (){
    float  maxSizeX = 1920;
    float  maxSizeY = 1080;
    float  slopeRange  = 0.1;
    float  minGradRange = 5;
    float  maxGradRnage = 300;
    
    sf:: RenderWindow theWindow(sf::VideoMode(maxSizeX,maxSizeY),  "1D Perlin Noise");
    theWindow.setFramerateLimit(60);
    sf :: CircleShape dotGraph(1.0f);
    dotGraph.setFillColor(sf::Color(0,0,255));
    dotGraph.setPosition(0,maxSizeY/2);
    OneDPerlin Perlin(minGradRange,maxGradRnage,slopeRange,maxSizeX,maxSizeY);
    Perlin.settingGradPoints();
    Perlin.settingSlopePoints();
    std:: vector<float> dotsYPositions = Perlin.gettingPerlin(); 
    float xValue = 0;
    float yValue = dotGraph.getPosition().y;
    int i = 0;
    sf :: CircleShape dotGraph2(1.0f);
    dotGraph2.setFillColor(sf::Color(255,255,0));
    dotGraph2.setPosition(0,maxSizeY/4);
    OneDPerlin Perlin2(minGradRange,maxGradRnage,1,maxSizeX,maxSizeY);
    Perlin2.settingGradPoints();
    Perlin2.settingSlopePoints();
    std:: vector<float> dotsYPositions2 = Perlin2.gettingPerlin(); 
    float xValue2 = 0;
    float yValue2 = dotGraph2.getPosition().y;
    int i2 = 0;
    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        dotGraph.setPosition(xValue, yValue);
        theWindow.draw(dotGraph);
        dotGraph2.setPosition(xValue2, yValue2);
        theWindow.draw(dotGraph2);
        theWindow.display();
        if(i < dotsYPositions.size()){
            yValue = dotsYPositions[i] + maxSizeY/2;
            
            xValue = xValue + slopeRange;
            i = i + 1;
        }
        if(i2 < dotsYPositions2.size()){
            yValue2 = dotsYPositions2[i] + maxSizeY/4;
            
            xValue2 = xValue2 + 1;
            i2 = i2 + 1;
        }
	    
    }
    

    return 0;
}