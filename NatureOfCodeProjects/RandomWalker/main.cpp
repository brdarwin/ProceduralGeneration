#include <iostream>
#include <SFML/Graphics.hpp>
#include "Walker.h"
#include <vector>


int main (){
    float  maxSizeX = 1920;
    float  maxSizeY = 1080;
    sf:: RenderWindow theWindow(sf::VideoMode(maxSizeX,maxSizeY),  "Random Walker");
    theWindow.setFramerateLimit(60);
    std:: vector <Walker> walkers;
    Walker classicWalker(maxSizeX/2, maxSizeY/2, maxSizeX, maxSizeY, 0, 0,0, sf::Color(255, 0, 0));
    Walker rangedStepsWalker(maxSizeX/4, maxSizeY/2, maxSizeX, maxSizeY, 5, 0,0, sf::Color(0, 255, 0));
    Walker levyWalker(maxSizeX * (4/3), maxSizeY/2, maxSizeX, maxSizeY, 5, 100,1, sf::Color(0, 0, 255));
    walkers.push_back(classicWalker);
    walkers.push_back(rangedStepsWalker);
    walkers.push_back(levyWalker);
    sf :: CircleShape circleWalker(1.0f);
    
    
    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        for(int i = 0; i < walkers.size(); i++){
            walkers[i].levyFlight();
            walkers[i].setMovementRange();
            walkers[i].nextStep();
            walkers[i].eliminatingBorders();
            walkers[i].setWalkerPosition(circleWalker);
            theWindow.draw(circleWalker);
        }
        
        theWindow.display();
	    
    }
    return 0;
}
