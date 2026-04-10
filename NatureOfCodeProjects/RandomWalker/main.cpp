#include <iostream>
#include <SFML/Graphics.hpp>
#include "Walker.h"
#include <vector>


int main (){
    float  maxSizeX = 600;
    float  maxSizeY = 400;
    sf:: RenderWindow theWindow(sf::VideoMode(maxSizeX,maxSizeY),  "Random Walker");
    theWindow.setFramerateLimit(60);
    Walker myWalker(maxSizeX/2, maxSizeY/2, maxSizeX, maxSizeY, 5);
    sf :: CircleShape circleWalker(1.0f);
    circleWalker.setFillColor(sf::Color(255,255,0));
    
    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        myWalker.setMovementRange();
        myWalker.nextStep();
        myWalker.eliminatingBorders();
        myWalker.setWalkerPosition(circleWalker);
         
        theWindow.draw(circleWalker);
        theWindow.display();
	    //theWindow.clear();
    }
    return 0;
}
