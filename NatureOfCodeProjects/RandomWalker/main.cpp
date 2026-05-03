#include <iostream>
#include <SFML/Graphics.hpp>
#include "Walker.h"
#include <vector>


int main (){
    float  maxSizeX = 1900;
    float  maxSizeY = 800;
    float  usualRange = 5;
    float  leviFlightRange = 100 ;
    int    leviProbability = 1;
    sf:: RenderWindow theWindow(sf::VideoMode(maxSizeX,maxSizeY),  "Random Walker");
    theWindow.setFramerateLimit(60);
    Walker myWalker(maxSizeX/2, maxSizeY/2, maxSizeX, maxSizeY, usualRange, leviFlightRange,leviProbability);
    sf :: CircleShape circleWalker(1.0f);
    circleWalker.setFillColor(sf::Color(255,255,0));
    
    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        myWalker.leviFlight();
        myWalker.setMovementRange();
        myWalker.nextStep();
        myWalker.eliminatingBorders();
        myWalker.setWalkerPosition(circleWalker);
        theWindow.draw(circleWalker);
        theWindow.display();
	    
    }
    return 0;
}
