#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>
#include "Utils.h"
#include <exception>
#include <random>

//#define TESTING_ON

#define MAX_SIZE 10
#define MIN_SIZE 5
#define SEED 101

/*
The code below has some issues.
We will be fixing along the way. Do not assume correctness.
*/

int main(void){

    //Read the height and width
    unsigned int envHeight = 0;
    unsigned int envWidth = 0;

    try{
        //Read env size
        ReadEnvSize(envHeight, envWidth);

        // Read the structure of the environment
        char** envStructure;
        envStructure = new char*[envHeight];
        for(unsigned int i =0; i < envHeight; i++){
            envStructure[i] = new char[envWidth];
        }
        readEnvStdin(envStructure, envHeight, envWidth);

        // Read the start coordinate
        mcpp::Coordinate* start = nullptr;
        ReadEnvStart(&start);

        // Create instance of Env class
        // Ownership of start, envStructure passed to env
        Env env(envHeight, envWidth, envStructure, start);
        envStructure = nullptr;
        start = nullptr;
        
        //Construct the environment
        BuildEnvironment(&env);


        //Make a copy and build at c
        Env env2(env);
        start = new mcpp::Coordinate(4868, 71, 4349);
        env2.setStart(start);
        start = nullptr;

        BuildEnvironment(&env2);
        

        //Buidl a random structure at 4828 71 4389
        start = new mcpp::Coordinate(4858, 71, 4359);

        //initialize values randomly
        std::default_random_engine engine(SEED);
        std::uniform_int_distribution<int> size_dist(MIN_SIZE, MAX_SIZE);
        

        envHeight = size_dist(engine);
        envWidth = size_dist(engine);
        std::cout << "Random env size (H, W): " << envHeight << ", " << envWidth << std::endl;

        envStructure = new char*[envHeight];
        for(unsigned int i =0; i < envHeight; i++){
            envStructure[i] = new char[envWidth];
        }

        std::uniform_int_distribution<int> block_dist(0, 1);
        for(unsigned int h =0; h < envHeight; h++){
            for(unsigned int w = 0; w < envWidth; w++){
                int block_type = block_dist(engine);
                if(block_type == 0){
                    envStructure[h][w] = 'x';
                }else{
                    envStructure[h][w] = '.';
                }
                
            }
        }

        Env env3(envHeight, envWidth, envStructure, start);
        envStructure = nullptr;
        start = nullptr;
        BuildEnvironment(&env3);


        


        #ifdef TESTING_ON
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
        #endif
        

    }catch(std::invalid_argument& e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
