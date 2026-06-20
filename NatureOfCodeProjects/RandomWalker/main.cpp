#include <iostream>
#include <SFML/Graphics.hpp>
#include "Walker.h"
#include <vector>



int main (){
    sf :: Vector2f screenSize(1024, 1024);
    sf:: RenderWindow theWindow(sf::VideoMode(screenSize.x,screenSize.y),  "Random Walker");
    theWindow.setFramerateLimit(60);
    Walker *myWalker = new Walker(screenSize, sf :: Color(0,255,255), 10);
    
    
    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        myWalker -> movementRange();
        myWalker -> setSteps();
        myWalker -> eliminatingBorders();
        sf :: CircleShape walker(1.0f);
        walker.setFillColor(sf :: Color(0,0,255));
        sf :: Vector2f  vecPosition= myWalker -> getPosition();
        walker.setPosition(vecPosition);
        theWindow.draw(walker);
        theWindow.display();
        //theWindow.clear();
	    
    }
    delete myWalker;
    return 0;
}
