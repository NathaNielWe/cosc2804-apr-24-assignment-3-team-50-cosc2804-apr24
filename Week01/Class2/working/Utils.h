#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>
#include <exception>

void ReadEnvSize(int& envHeight, int& envWidth){
    std::cout << "Enter the size of the rectangular Environment (H, W): " << std::endl;
    std::cin >> envHeight;
    std::cin >> envWidth;

    if (envHeight == 0 || envWidth == 0){
        throw std::invalid_argument("Height and width arguments are not correct!");
    }
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
    
}
