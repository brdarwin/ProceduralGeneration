#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <vector>
#include <random>
#include "Column.h"


int randFuntion(int max){
    int min = 0;
   

    
    std :: random_device rd;
    std :: mt19937 gen(rd());
    std:: uniform_int_distribution<> distrib(min, max);

    
    return  distrib(gen);

}


int main (){
    float  maxSizeX = 600;
    float  maxSizeY = 400;
    sf:: RenderWindow theWindow(sf::VideoMode(maxSizeX,maxSizeY),  "Random Partition");
    theWindow.setFramerateLimit(60);
    std ::  vector<Column> vecColumns;
    int columPosition = 0;
    for(int i = 0; i < 10; i++){
        Column newColumn(sf:: Vector2f(59, 0), sf:: Vector2f(columPosition, maxSizeY));
        vecColumns.push_back(newColumn);
        columPosition = columPosition + 60;
    } 

    while(theWindow.isOpen()){
        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        for(int i = 0; i < vecColumns.size(); i++){
            sf:: RectangleShape myColumn(vecColumns[i].getColumnShape());
            myColumn.setPosition(vecColumns[i].getColumnPosition());
            myColumn.setFillColor(sf:: Color(255,255,255));
            myColumn.setOutlineColor(sf::Color(0,0,255));
            //myColumn.setOutlineThickness(2.0f); 
            int randomIndex = randFuntion(vecColumns.size());
            if(i == randomIndex){
                sf:: Vector2f columnShape = vecColumns[i].getColumnShape();
                vecColumns[i].setColumnShape(sf::Vector2f(columnShape.x, columnShape.y - 2));
            }
            theWindow.draw(myColumn);
            
        }
        theWindow.display();
        
    }
    return 0;

    return 0;
}