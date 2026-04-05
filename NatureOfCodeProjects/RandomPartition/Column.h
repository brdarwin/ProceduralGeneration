#ifndef COLUMN_H
#define WALKER_H
#include <iostream> 
#include <SFML/Graphics.hpp>


class Column
{
private:
    sf:: Vector2f columnShape_;
    sf:: Vector2f columnPosition_;
      
    
public:
   Column (sf:: Vector2f columShape,sf:: Vector2f columPosition);
   void setColumnShape(sf:: Vector2f columnShape);
   void setColumnPosition(sf:: Vector2f columPosition);
   sf :: Vector2f getColumnShape();
   sf :: Vector2f getColumnPosition();
};




#endif