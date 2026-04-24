#include <iostream>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>


float randomFunction(float firstValue,  float secondValue, bool isGaussian ){

    
    

    
    std :: random_device rd;
    std :: mt19937 gen(rd());
    if (isGaussian){
        std :: normal_distribution<float> dist(firstValue, secondValue);
        return dist(gen);
    }

    std:: uniform_int_distribution<> distrib(firstValue, secondValue);
    return  distrib(gen);

}

std :: vector <float> settingCoordinates(int vecLenght, float coordinateRange){
    std :: vector<float> vec;
    for(int index = 0; index <= vecLenght; index++){
        vec.push_back(randomFunction(0, coordinateRange, false));
    }
    return vec;
}

float gettingMeanOfCoordinates( std :: vector <float> vec){
    float totalSum = 0;
    for(int index = 0; index < vec.size(); index++){
        totalSum = totalSum + vec[index];

    }
    return totalSum / vec.size();
}

float gettingStandardDeviantion(std:: vector <float> vec, float mean){
    float variance = 0;
    for(int index = 0; index < vec.size(); index++){
        variance = variance + std:: pow(vec[index] - mean, 2); 
    }
    return std :: sqrt(variance / vec.size());
}

float settingBorders(float maxSize, float coordinate){
    if (coordinate < 0 ){
        return maxSize + coordinate;
    }else if(coordinate > maxSize ){
        return  coordinate - maxSize;

    }
    return coordinate;
}

int main(){
    float maxSizeX = 1920;
    float maxSizeY = 800;
    sf :: RenderWindow theWindow(sf:: VideoMode(maxSizeX,maxSizeY), "Gaussian Distribution");
    theWindow.setFramerateLimit(60);
    std :: vector <float> xCoordinates = settingCoordinates(5, maxSizeX / 10);
    std :: vector <float> yCoordinates = settingCoordinates(5, maxSizeY / 10);
    float xCoordinatesMean = gettingMeanOfCoordinates(xCoordinates);
    float yCoordinatesMean = gettingMeanOfCoordinates(yCoordinates);
    float xCoordinatesStandarDeviation = gettingStandardDeviantion(xCoordinates, xCoordinatesMean);
    float yCoordinatesStandarDeviation = gettingStandardDeviantion(yCoordinates, yCoordinatesMean);
    sf:: CircleShape centralCircle(3.0f);
    centralCircle.setFillColor(sf:: Color(0,0,255));
    centralCircle.setPosition(xCoordinatesMean, yCoordinatesMean);
    theWindow.draw(centralCircle);
    sf:: CircleShape circle(3.0f);
    circle.setFillColor(sf:: Color(255,255, 0));
    float xCoordinate;
    float yCoordinate;
    while (theWindow.isOpen() )
    {
       sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        
        xCoordinate = randomFunction(xCoordinatesMean, xCoordinatesStandarDeviation, true);
        yCoordinate = randomFunction(yCoordinatesMean, yCoordinatesStandarDeviation, true);
        xCoordinate = settingBorders(maxSizeX, xCoordinate);
        yCoordinate = settingBorders(maxSizeY, yCoordinate);
        circle.setPosition(xCoordinate, yCoordinate);
        theWindow.draw(circle);
        theWindow.display();
    }
    
    return 0;
}
