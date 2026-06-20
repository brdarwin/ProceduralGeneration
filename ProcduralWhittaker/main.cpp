#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "/home/bruno/CompSci/ProceduralGeneration/PerlinNoise/Perlin2D.h"
#include "/home/bruno/CompSci/ProceduralGeneration/PerlinNoise/Point.h"
#include "Ecosystem.h"


int main (int argc, char *argv[]){
    sf :: Vector2i screenSize(1024, 1024);
    if(argc > 1){
        screenSize.x = screenSize.y = std :: stoi(argv[1]);
    }
    sf:: RenderWindow theWindow(sf::VideoMode(screenSize.x,screenSize.y),  "Procedural Whittaker");
    theWindow.setFramerateLimit(60);
    Ecosystem *myEco = new Ecosystem(screenSize);
    myEco ->settingBiomes();
    sf :: Image myImg =  myEco -> getEcosystemImg();
    myImg.saveToFile("/home/bruno/CompSci/ProceduralGeneration/ProcduralWhittaker/Images/exampple.png");
    delete myEco;
    sf :: Texture tex;
    tex.create(myImg.getSize().x, myImg.getSize().y);
    tex.update(myImg);
    sf :: Sprite sprt (tex);
    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        theWindow.draw(sprt);
        theWindow.display();
        theWindow.clear();
	    
    }
    
    return 0;
}
