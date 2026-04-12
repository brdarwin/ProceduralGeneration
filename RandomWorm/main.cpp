#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Worm.h"
#include "Body.h"


int main (){
    float  maxSizeX = 200;
    float  maxSizeY = 100;
    sf:: RenderWindow theWindow(sf::VideoMode(maxSizeX,maxSizeY),  "Random Worm");
    theWindow.setFramerateLimit(60);
    Body headBody({maxSizeX/2,maxSizeY/2}, sf:: Color(255, 255, 255), 1.0f);
    Worm myWorm(headBody, 50, maxSizeX,maxSizeY, 20);
    myWorm.setWormBody(false);
    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        myWorm.setMovementRange();
        myWorm.nextStep();
        myWorm.eliminatingBorders();
        myWorm.setWormBody(true);
        for (int i = 0; i < myWorm.getWormSize(); i++){
            sf :: CircleShape wormBody;
            myWorm.getWormBody(wormBody, i);
            theWindow.draw(wormBody);
        }
        theWindow.display();
        theWindow.clear();
	    
    }
    return 0;
}
