#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>

void ReadEnvSize(int& envHeight, int& envWidth){
    std::cout << "Enter the size of the rectangular Environment (H, W): " << std::endl;
    std::cin >> envHeight;
    std::cin >> envWidth;
}

void ReadEnvStart(mcpp::Coordinate** start){
    int x=0;
    int y=0;
    int z=0;
    std::cout << "Enter the start coordinate of rectangular Environment (X, Y, Z): " << std::endl;
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

    *start = new mcpp::Coordinate(x, y, z);
}


void readEnvStdin(char** EnvStruct, int height, int width){
    int charsRead = 0;
    char readC;

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            if(std::cin.good()){
                std::cin >> readC;
                EnvStruct[row][col] = readC;
                ++charsRead;
            }
        }
        
    }

    if (charsRead != (height * width)) {
        std::cerr   << "ERROR: Only read " 
                    << charsRead 
                    << " maze cells - input file incorrectly formatted\n\n";
    }
    
}
