#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Perlin.h"






int main(int argc, char  *argv[]){
    std :: vector<int> setOfValues;
    setOfValues.push_back(256); //Screen Width
    setOfValues.push_back(setOfValues[0]); //screen Height
    setOfValues.push_back(setOfValues[0]);// maxGradient
    setOfValues.push_back(8); // minGradient)
    setOfValues.push_back(0); // setOfColors;
    if(argc > 1){
        for(int i =  1; i < argc; i+=1){
            setOfValues[i - 1] = std :: stof(argv[i]);
        }
    }
    Perlin *myPerlin = new Perlin(setOfValues);
    myPerlin->setOctaves();
    myPerlin->setGradCells();
    myPerlin->settingNoise();
    myPerlin->setNoiseImg();
    sf :: Image myImg = myPerlin -> getNoiseImg();

    sf :: Texture tex;
    tex.create(myImg.getSize().x, myImg.getSize().y);
    tex.update(myImg);
    sf :: Sprite sprite(tex);



    sf :: RenderWindow myWindow(sf :: VideoMode(setOfValues[0],setOfValues[1]), "Perlin2D");
    myWindow.setFramerateLimit(60);
    while(myWindow.isOpen()){
        sf::Event event;
        while (myWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                myWindow.close();
            }
        
        }
        myWindow.clear();
        myWindow.draw(sprite);
        myWindow.display();
        
	    


    }
    
    
    
    delete myPerlin;
    return 0;
}