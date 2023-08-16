#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>
#include "Utils.h"

int main(void){

    //Read the height and width
    int envHeight = 0;
    int envWidth = 0;

    ReadEnvSize(envHeight, envWidth);

    // Create instance of Env class
    Env env(envHeight, envWidth);
    std::cout << "Height: " << env.getHeight() << ", Width: " 
                                    << env.getWidth() << std::endl;

    // Read the structure of the environment
    char** envStructure;
    envStructure = new char*[envHeight];
    for(int i =0; i < envHeight; i++){
        envStructure[i] = new char[envWidth];
    }
    readEnvStdin(envStructure, envHeight, envWidth);

    env.setEnvStructure(envStructure);

    for (int row = 0; row < env.getHeight(); row++){
        for (int col = 0; col < env.getWidth(); col++){
            std::cout << env.getEnvStructure()[row][col];
        }
        std::cout << std::endl;
    }

    
    // Read the start coordinate
    mcpp::Coordinate* start = nullptr;
    ReadEnvStart(&start);
    std::cout << start->x << "," << start->y << "," << start->z << std::endl;

    env.setStart(start);

    //Construct the environment
    mcpp::MinecraftConnection mc;
    mc.setPlayerPosition(*(env.getStart()) + mcpp::Coordinate(0, 1, 0));

    env.buildEnv(&mc);
    

    //delete memory
    for(int i =0; i < envHeight; i++){
        delete[] envStructure[i];
        envStructure = nullptr;
    }
    delete[] envStructure;
    envStructure = nullptr;

    delete start;
    start = nullptr;

    return EXIT_SUCCESS;
}
