#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>

//function declaration
void ReadEnvSize(int& envHeight, int& envWidth);
void readEnvStdin(char** EnvStruct, int height, int width);

int main(void){
    int envHeight = 0;
    int envWidth = 0;

    ReadEnvSize(envHeight, envWidth);

    // Read the structure of the environment
    char** envStructure;
    envStructure = new char*[envHeight];
    for(int i =0; i < envHeight; i++){
        envStructure[i] = new char[envWidth];
    }

    readEnvStdin(envStructure, envHeight, envWidth);

    // char envStructure[envHeight][envWidth];
    // char readC;
    // for (int row = 0; row < envHeight; row++){
    //     for (int col = 0; col < envWidth; col++){
    //         if(std::cin.good()){
    //             std::cin >> readC;
    //             envStructure[row][col] = readC;
    //         }
    //     }
        
    // }

    for (int row = 0; row < envHeight; row++){
        for (int col = 0; col < envWidth; col++){
            std::cout << envStructure[row][col];
        }
        std::cout << std::endl;
        
    }

    Env test_env(envHeight, envWidth);
    std::cout << "Height: " << test_env.getHeight() << ", Width: " << test_env.getWidth() << std::endl;

    mcpp::Coordinate testCoord(3, 2, 1);
    std::cout << testCoord.x << std::endl;



    //delete memory
    for(int i =0; i < envHeight; i++){
        delete[] envStructure[i];
    }
    delete[] envStructure;

    return EXIT_SUCCESS;
}

//function definition
void ReadEnvSize(int& envHeight, int& envWidth){
    std::cout << "Enter the size of the rectangular Environment (H, W): " << std::endl;
    std::cin >> envHeight;
    std::cin >> envWidth;
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
