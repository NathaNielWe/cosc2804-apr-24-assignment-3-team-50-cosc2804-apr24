#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>
#include "Utils.h"

int main(void){

    //Read the height and width
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

    for (int row = 0; row < envHeight; row++){
        for (int col = 0; col < envWidth; col++){
            std::cout << envStructure[row][col];
        }
        std::cout << std::endl;
    }

    Env test_env(envHeight, envWidth);
    std::cout << "Height: " << test_env.getHeight() << ", Width: " << test_env.getWidth() << std::endl;

    // Read the start coordinate
    mcpp::Coordinate* start = NULL;
    ReadEnvStart(&start);
    std::cout << start->x << "," << start->y << "," << start->z << std::endl;

    //Construct the environment
    mcpp::MinecraftConnection mc;
    mc.setPlayerPosition(*start + mcpp::Coordinate(0, 1, 0));

    for(int h =0; h < test_env.getHeight(); h++){
        for(int w = 0; w < test_env.getWidth(); w++){
            if(envStructure[h][w] == 'x'){
                mc.setBlock(*start + mcpp::Coordinate(h, 0, w), mcpp::Blocks::BRICKS);
                mc.setBlock(*start + mcpp::Coordinate(h, 1, w), mcpp::Blocks::BRICKS);
            }
        }
    }

    //delete memory
    for(int i =0; i < envHeight; i++){
        delete[] envStructure[i];
    }
    delete[] envStructure;

    delete start;

    return EXIT_SUCCESS;
}
