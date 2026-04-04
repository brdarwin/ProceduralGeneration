#include <iostream>
#include <chrono>
using namespace std;


int main (){
    auto currentTime = chrono::system_clock::now();
    auto duration = currentTime.time_since_epoch();
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();  
    //srand(time(NULL));
    srand(milliseconds);
    for(int i = 0; i < 4;i++){
        
        cout << rand() % 4 << '\n';

    }
    
    return 0;
}