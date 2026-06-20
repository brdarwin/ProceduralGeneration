#include "Perlin.h"



Perlin :: Perlin(std :: vector<int> setOfvalues){
    screenSize_.x   = setOfvalues[0];
    screenSize_.y   = setOfvalues[1];
    maxGradient_    = setOfvalues[2];
    minGradient_    = setOfvalues[3];
    setOfColors_    = setOfvalues[4];
    numOfGradients_ = (int) (maxGradient_/minGradient_);
    noises_  = noisesInitializer();
    std :: random_device rd;
    std :: mt19937 gen(rd());
    seed_ = gen;
    gradients_ = gradientsInitializer();
    myNoise_.create(screenSize_.x, screenSize_.y);

}

std  :: vector <std :: vector<float>>  Perlin ::  noisesInitializer(){
    std  :: vector <std :: vector<float>> matrix;
    for(int x = 0; x < screenSize_.x; x +=1){
        std :: vector <float> vec;
        for(int y = 0; y < screenSize_.y; y +=1){
            vec.push_back(0.0f);
        }
        matrix.push_back(vec);
    }    

    return matrix;
}



template <typename T> T  Perlin :: randomFunction(T min, T max, bool isFloat){

   
    if(isFloat){
        std :: uniform_real_distribution<float> distrib(min,max);
        return distrib(seed_);
    }
    std:: uniform_int_distribution<> distrib(min, max);
    return distrib(seed_);
}

std  :: vector <std :: vector<sf :: Vector2i>>  Perlin ::  gradientsInitializer(){
    std  :: vector <std :: vector<sf :: Vector2i>> matrix;
    for(int x = 0; x <= screenSize_.x ; x +=1){
        std :: vector<sf :: Vector2i> vec;
        for(int y = 0; y <= screenSize_.y ; y +=1){
          int index =  randomFunction(0,7, false);
          vec.push_back(arrayVectors_[index]);  
        }
        matrix.push_back(vec);
    }    

    return matrix;
}

void Perlin :: setOctaves(){
    for(int octave  = maxGradient_; octave >= minGradient_; octave = octave / 2){
        
        octaves_.push_back(octave);
    }
    
}

void Perlin :: setGradCells(){
    float amplitude  = 1;
    for(int o  =  0; o < octaves_.size(); o+=1){
   
    for(int x = 0; x <= gradients_.size() - octaves_[o] ; x+= octaves_[o]){
       
        for(int y = 0; y <= gradients_[x].size() - octaves_[o] ; y+=octaves_[o]){
          std :: vector<std :: vector<int>> cell = {
            {x, y },
            {x + octaves_[o], y},
            {x, y+ octaves_[o]},
            {x+ octaves_[o], y+ octaves_[o]},
          };
          cells_.push_back(cell);
          amplitude_.push_back(amplitude);
        }
    }
    amplitude  = amplitude / 2;
    }
}


sf :: Vector2i Perlin :: getVector(int x, int y){
    return gradients_[x][y];
}


float Perlin ::  dotProduct (sf :: Vector2i vec,sf ::Vector2i vecCoordinates ,sf ::Vector2i pointCoordinates, float grad){
    float distanceX = (pointCoordinates.x - vecCoordinates.x)/grad;
    float distanceY = (pointCoordinates.y - vecCoordinates.y)/grad;
   
    return (vec.x * distanceX) + (vec.y * distanceY);
    
}

 float Perlin ::  getPosition(float corner0, float corner1, float pointLocation){

    return ((pointLocation - corner0 ) / (corner1 - corner0));
 }


 float Perlin :: smoothStep(float value){
    return value*value*value*(value*(value*6 - 15) + 10);
 }

 float  Perlin :: interpolation(float a, float b, float u){
    return a + (u *(b - a ));
 }

void Perlin :: settingNoise (){
    for(int c = 0; c < cells_.size(); c +=1){
       float amplittude = 1.0f;
       std :: vector<std :: vector<int>> cell = cells_[c];
       int x0 = cell[0][0];
       int y0 = cell[0][1];
       int x1 = cell[1][0];
       int y1 = cell[1][1];
       int x2 = cell[2][0];
       int y2 = cell[2][1];
       int x3 = cell[3][0];
       int y3 = cell[3][1];
       int grad = x1 - x0; 
       if (grad == 0) {
    std::cout << "ZERO GRADIENT\n";
}
       sf :: Vector2i vecA = getVector(cell[0][0], cell[0][1]);
       sf :: Vector2i vecB = getVector(cell[1][0], cell[1][1]);
       sf :: Vector2i vecC = getVector(cell[2][0], cell[2][1]);
       sf :: Vector2i vecD = getVector(cell[3][0], cell[3][1]); 
        
       for(int x = x0; x < x1 ; x+=1){
            for(int y = y0; y < y2; y+=1){
                float productA = dotProduct(vecA,sf :: Vector2i(x0,y0),sf :: Vector2i(x,y), grad);
                

                float productB = dotProduct(vecB,sf :: Vector2i(x1,y1),sf :: Vector2i(x,y), grad);
                float productC = dotProduct(vecC,sf :: Vector2i(x2,y2),sf :: Vector2i(x,y), grad);
                float productD = dotProduct(vecD,sf :: Vector2i(x3,y3),sf :: Vector2i(x,y), grad);
                float horizontal = getPosition(x0,x1, x);
                float vertical = getPosition(y0,y2, y);
                horizontal = smoothStep(horizontal);
                vertical   = smoothStep(vertical);
                float topInterpolation = interpolation(productA, productB, horizontal);
                float bottomInterpolation =  interpolation(productC,productD, horizontal);
                float noise =  interpolation(topInterpolation,bottomInterpolation, vertical);
                noise = amplitude_[c] * noise;
                
                noises_[x][y] += noise;
                
            }
       }
    }
}

 std  :: vector <std :: vector<float>> Perlin :: getNoise(){
    return noises_;
 }

void Perlin :: setNoiseImg(){
    for(int x = 0; x < myNoise_.getSize().x; x+=1){
        for(int y = 0; y < myNoise_.getSize().y; y+=1){
            float color = 255 * ((1 + noises_[x][y])/ 2);
            sf ::  Color pxColors(color,color,color);
            myNoise_.setPixel(x,y, pxColors);
            
        }
    }
}

sf :: Image Perlin :: getNoiseImg(){
    return myNoise_;
}