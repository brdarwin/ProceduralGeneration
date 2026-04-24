#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Worm.h"
#include "Body.h"


int main (){
    float maxSizeX = 1920;
    float maxSizeY = 800;
    int   wormSize = 1000;
    int   movementRange = 5;
     
   
    
    
   
    sf:: RenderWindow theWindow(sf::VideoMode(maxSizeX,maxSizeY),  "Random Worm");
    theWindow.setFramerateLimit(60);
    Body headBody({maxSizeX/4,maxSizeY/4}, sf:: Color(255, 255, 255), 1.0f);
    Worm myWorm(headBody, wormSize, maxSizeX,maxSizeY, movementRange);
    myWorm.setWormBody(false);
    Body headBody2({maxSizeX/6,maxSizeY/6}, sf:: Color(255, 255, 255), 1.0f);
    Worm myWorm2(headBody2, wormSize, maxSizeX,maxSizeY, movementRange);
    myWorm2.setWormBody(false);
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
        myWorm2.setMovementRange();
        myWorm2.nextStep();
        myWorm2.eliminatingBorders();
        myWorm2.setWormBody(true);
        for (int i = 0; i < myWorm.getWormSize(); i++){
            sf :: CircleShape wormBody;
            myWorm.getWormBody(wormBody, i);
            theWindow.draw(wormBody);
            myWorm2.getWormBody(wormBody, i);
            theWindow.draw(wormBody);
        }
        theWindow.display();
        theWindow.clear();
	    
    }
    return 0;
}
