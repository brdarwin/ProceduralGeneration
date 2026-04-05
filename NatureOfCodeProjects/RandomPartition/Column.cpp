#include "Column.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Column :: Column (sf:: Vector2f columShape,sf:: Vector2f columPosition){
    columnShape_ = columShape;
    columnPosition_ = columPosition;
}

void Column :: setColumnShape(sf:: Vector2f columnShape){
    columnShape_ = columnShape;
}

void Column :: setColumnPosition(sf:: Vector2f columnPosition){
    columnPosition_ = columnPosition;
}

sf:: Vector2f Column :: getColumnPosition(){
    return columnPosition_;
}

sf:: Vector2f Column :: getColumnShape(){
    return columnShape_;
}