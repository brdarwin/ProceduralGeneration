#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "OneDPerlin.h"





int main (){
    float  maxSizeX = 1920;
    float  maxSizeY = 1080;
    float  slopeRange  = 1;
    float  minGradRange = 1;
    float  maxGradRnage = 400;
    
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
    
    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        dotGraph.setPosition(xValue, yValue);
        theWindow.draw(dotGraph);
        
        theWindow.display();
        if(i < dotsYPositions.size()){
            yValue = dotsYPositions[i] + maxSizeY/2;
            
            xValue = xValue + slopeRange;
            i = i + 1;
        }
       
	    
    }
    

    return 0;
}