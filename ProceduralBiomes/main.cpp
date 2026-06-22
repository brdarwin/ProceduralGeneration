#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Ecosystem.h"



int main(int argc, char * argv[]){
    sf :: Vector2i screenSize(1536, 1024);
    if(argc  == 2){
        std :: cout << "lacking some input";
        return -1;
    }else if(argc > 2){
        screenSize.x = std :: stoi( argv[1]);
        screenSize.y = std :: stoi( argv[2]);
    }
    Ecosystem * eco  = new  Ecosystem(screenSize);
    eco->setTerrain();
    eco->setRivers();
    sf :: Image myImg = eco->getEcosystemImg();
    sf :: Texture tex;
    tex.loadFromImage(myImg);
    sf :: Sprite sprt;
    sprt.setTexture(tex);
    sf :: RenderWindow theWindow(sf :: VideoMode(screenSize.x,screenSize.y), " Ecosystem");
    theWindow.setFramerateLimit(60);
    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        theWindow.clear();
        theWindow.draw(sprt);
        theWindow.display();
        
	    
    }
    myImg.saveToFile("/home/bruno/CompSci/ProceduralGeneration/ProceduralBiomes/Images/example.png");
    delete eco;
    return 0;
}