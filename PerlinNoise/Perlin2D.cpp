#include "Perlin2D.h"


Perlin2D :: Perlin2D (std :: vector <int> setOfValues){
    screenSize_.x = setOfValues[0];
    screenSize_.y = setOfValues[1];
    gradientRange_.x = setOfValues[2];
    gradientRange_.y = setOfValues[3];
    colorsSet_ = setOfValues[4];
    numOfOctaves_ = gradientRange_.x /gradientRange_.y;
    screenPoints_ =  initializeMatrix(screenSize_.x,screenSize_.y);
    gradPoints_   =  initializeMatrix(screenPoints_.size() + 1, screenPoints_[0].size() + 1);
    noisyImg_.create(screenPoints_.size(), screenPoints_[0].size());
    std :: random_device rd;
    std :: mt19937 gen(rd());
    seed_ = gen;

    
    

}

std :: vector< std :: vector<Point>>  Perlin2D :: initializeMatrix(int xRange, int yRange ){
    std :: vector< std :: vector<Point>>  matrix;
    for(int x = 0; x < xRange; x+=1){
        std :: vector <Point> points;
        for(int y = 0;  y  < yRange; y+=1){
            points.push_back(Point(sf::Vector2i(x,y)));
            

        }
        matrix.push_back(points);
    }
    return matrix;
}

void Perlin2D :: setGradient(){
    for(int grad  =  gradientRange_.x ; grad >= gradientRange_.y; grad = grad / 2){
    for(int x = 0; x < gradPoints_.size(); x+=grad){
        
       for(int y = 0 ; y < gradPoints_[x].size(); y+= grad){
            
            if(gradPoints_[x][y].getVector() == sf :: Vector2i(0,0)){
                gradPoints_[x][y].setVector(seed_);
            }
            
        }
        
    }
    }
}

void Perlin2D :: setInterpolations(){
    std :: vector <std :: vector<std :: vector<Point>>> cells;
    for(int grad  =  gradientRange_.x ; grad >= gradientRange_.y; grad = grad / 2){
    for(int x = 0; x < gradPoints_.size() - 1 ; x+=grad){
        for(int y = 0; y < gradPoints_[x].size() -1 ; y+=grad){
          std :: vector<std :: vector<Point>> cell = {
            {gradPoints_[x][y] ,gradPoints_[x ][y + grad] },
            {gradPoints_[x + grad ][y] ,gradPoints_[x + grad ][y + grad] } 
          };
          cells.push_back(cell); 
        }
    }
    }
    
    for(int c = 0; c < cells.size(); c+= 1){
        std :: vector<std :: vector<Point>> cell = cells[c];
        int x0 = cell[0][0].getPointCoodrinates().x;
        int x1 = cell[1][0].getPointCoodrinates().x;
        int y0 = cell[0][0].getPointCoodrinates().y;
        int y1 = cell[0][1].getPointCoodrinates().y;
        for(int x = x0; x < x1; x+= 1){
            for(int y = y0; y < y1; y +=1){
                screenPoints_[x][y].setNoiseValue(cell);
                
            }
        }
    }
}

void Perlin2D :: colorsSet0To255(){
    for(int x = 0; x < noisyImg_.getSize().x; x +=1){
        for(int y = 0; y < noisyImg_.getSize().y; y+=1){
            float transformNoise =  (1 + screenPoints_[x][y].getNoiseValue()) / 2;
            float color  = 255 * transformNoise;
            sf :: Color pxColors(color, color, color);
            noisyImg_.setPixel(x,y, pxColors);
        }
    }

}

void Perlin2D :: colorsSetBlackAndWhite(){
   for(int x = 0; x < noisyImg_.getSize().x; x +=1){
        for(int y = 0; y < noisyImg_.getSize().y; y+=1){
            float color = 255;
            float noise =   screenPoints_[x][y].getNoiseValue();
            if(noise < 0) color = 0;
            sf :: Color pxColors(color, color, color);
            noisyImg_.setPixel(x,y, pxColors);
        }
    }
 
}

sf :: Color Perlin2D :: colorsSetRGB360(float noise){
    float r = 0;
    float g = 0;
    float b = 0;
            if(noise < 120){
                float t = noise / 120;
                r = 255 * t;
                b = 255 * (1 -t);
            }
            else if(noise < 240){
                float t = (noise - 120) / 120;
                g = 255 * t;
                r = 255 * (1 -t);
            }else{
                float t = (noise - 240) / 120;
                b = 255 * t;
                g = 255 * (1 -t);
            }    
    return sf :: Color (r,g,b);
}

sf :: Color Perlin2D :: colorsSetCYM360(float noise){
    float r = 0;
    float g = 0;
    float b = 0;
            if(noise < 120){
                float t = noise / 120;
                r = 255 * (1 -t);
                g = 255 * t;
                b = 255 * t;
            }
            else if(noise < 240){
                float t = (noise - 120) / 120;
                r = 255 * t;
                g = 255 * t;
                b = 255 * (1 -t);
            }else{
                float t = (noise - 240) / 120;
                r = 255 * t;
                g = 255 * (1 -t);
                b = 255 * t;
            }    
    return sf :: Color (r,g,b);
}

void Perlin2D :: set360(bool isRGB){
   for(int x = 0; x < noisyImg_.getSize().x; x +=1){
        for(int y = 0; y < noisyImg_.getSize().y; y+=1){
            float noise = 360 * ( (1 + screenPoints_[x][y].getNoiseValue()) / 2);
            sf :: Color pxColors(0, 0, 0);
            if(isRGB){
                pxColors = colorsSetRGB360(noise);
            }else{
                pxColors = colorsSetCYM360(noise);
            }
            noisyImg_.setPixel(x,y, pxColors);
        }
    }
}

void Perlin2D :: colorsSetMixRGBCYM360(){
   for(int x = 0; x < noisyImg_.getSize().x; x +=1){
        for(int y = 0; y < noisyImg_.getSize().y; y+=1){
            sf :: Color pxColors(0, 0, 0);  
            float noise = 360  * screenPoints_[x][y].getNoiseValue();
            if(noise < 0){
                noise = (-1)*noise;
                pxColors = colorsSetCYM360(noise);
                
            }else{
                pxColors = colorsSetRGB360(noise);
            }
            noisyImg_.setPixel(x,y, pxColors);
        }
    } 
}

sf :: Image Perlin2D :: getTheNoise(){
    switch (colorsSet_)
    {
    case 0:
        colorsSet0To255(); 
        break;
    case 1:
        colorsSetBlackAndWhite();
        break;
    case 2:
        set360(true);
        break;
    case 3:
        set360(false);
        break;
    case 4:
        colorsSetMixRGBCYM360();
        break;
    default:
        colorsSet0To255();
        break;
    }
    return noisyImg_;
}



