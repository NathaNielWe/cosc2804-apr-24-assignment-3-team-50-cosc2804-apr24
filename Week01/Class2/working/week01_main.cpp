#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>
#include "Utils.h"
#include <exception>

/*
The code below has some issues.
We will be fixing along the way. Do not assume correctness.
*/

int main(void){

    //Read the height and width
    unsigned int envHeight = 0;
    unsigned int envWidth = 0;

    try{
        ReadEnvSize(envHeight, envWidth);

        // Create instance of Env class
        Env env(envHeight, envWidth);
        // std::cout << "Height: " << env.getHeight() << ", Width: " 
        //                                 << env.getWidth() << std::endl;

        // Read the structure of the environment
        char** envStructure;
        envStructure = new char*[envHeight];
        for(unsigned int i =0; i < envHeight; i++){
            envStructure[i] = new char[envWidth];
        }
        readEnvStdin(envStructure, envHeight, envWidth);

        env.setEnvStructure(envStructure);

        for (unsigned int row = 0; row < env.getHeight(); row++){
            for (unsigned int col = 0; col < env.getWidth(); col++){
                std::cout << env.getEnvStructure()[row][col];
            }
            std::cout << std::endl;
        }

        
        // Read the start coordinate
        mcpp::Coordinate* start = nullptr;
        ReadEnvStart(&start);
        // std::cout << start->x << "," << start->y << "," << start->z << std::endl;

        env.setStart(start);
    
        //Construct the environment
        BuildEnvironment(&env);

        //Testing build
        std::cout << std::endl;
        std::cout << "Enter the region to check (startx starty startz height width):" << std::endl;
        int startx, starty, startz; 
        unsigned int hgt, wdt;

        std::cin >> startx;
        std::cin >> starty;
        std::cin >> startz;
        std::cin >> hgt;
        std::cin >> wdt;

        mcpp::MinecraftConnection mc;
        for(unsigned int h = 0; h<hgt; h++){
            for(unsigned int w = 0; w<wdt; w++){
                mcpp::BlockType block1 = mc.getBlock(mcpp::Coordinate(startx + h,starty, startz+w));
                mcpp::BlockType block2 = mc.getBlock(mcpp::Coordinate(startx + h,starty+1, startz+w));
                if( block1 == mcpp::Blocks::BRICKS && block2 == mcpp::Blocks::BRICKS){
                    std::cout << 'b';
                }else if (block1 == mcpp::Blocks::AIR && block2 == mcpp::Blocks::AIR){
                    std::cout << 'a';
                }else{
                    std::cout << 'e';
                }
            }
            std::cout << std::endl;

        }


        

        //delete memory
        for(unsigned int i =0; i < envHeight; i++){
            delete[] envStructure[i];
            envStructure[i] = nullptr;
        }
        delete[] envStructure;
        envStructure = nullptr;

        delete start;
        start = nullptr;

    }catch(std::invalid_argument& e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
