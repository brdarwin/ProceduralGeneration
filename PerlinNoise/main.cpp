#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Perlin2D.h"
#include "Point.h"





int main(int argc, char  *argv[]){
    std :: vector<int> setOfValues;
    setOfValues.push_back(1024); //Screen Width
    setOfValues.push_back(setOfValues[0]); //screen Height
    setOfValues.push_back(setOfValues[0]);// maxGradient
    setOfValues.push_back(32); // minGradient)
    setOfValues.push_back(0); // setOfColors;
    if(argc > 1){
        for(int i =  1; i < argc; i+=1){
            setOfValues[i - 1] = std :: stof(argv[i]);
        }
    }
    Perlin2D*  myPerlin  = new Perlin2D(setOfValues);
    myPerlin->setGradient();
    myPerlin->setInterpolations();
    sf :: Image  myImg = myPerlin -> getTheNoise();
    delete myPerlin;
    sf::Texture tex;
    tex.create(myImg.getSize().x, myImg.getSize().y);
    tex.update(myImg);
    sf :: Sprite sprite(tex);
    sf :: RenderWindow myWindow(sf::VideoMode(myImg.getSize().x, myImg.getSize().y), "Perlin2D");
    myWindow.setFramerateLimit(60);
    while(myWindow.isOpen()){
        sf::Event event;
        while (myWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                myWindow.close();
            }
        
        }
        
        myWindow.draw(sprite);
        myWindow.display();
        myWindow.clear();
	    


    }
    
    
    
   
    return 0;
}