#include <iostream>
#include <exception>
#include <random>

#include <mcpp/mcpp.h>

#include "Utils.h"
#include "Field.h"


// bool check4Treasure(mcpp::Coordinate& current);
// void randomMove(mcpp::Coordinate& current); 

int main(void){

    

    try{
        //Read the length and width
        unsigned int xLength = 0;
        unsigned int zLength = 0;

        mcpp::Coordinate basePoint(0,0,0);

        //Read the field parameters
        ReadFieldParameters(basePoint, xLength, zLength);

        // setup the field
        Field field(basePoint, xLength, zLength);
        std::cout << field << std::endl;

        //deploy agent
        mcpp::Coordinate currentLoc = field.getStartLocation();

        mcpp::MinecraftConnection mc;
        mc.setPlayerPosition(currentLoc);

        // bool treasureFound = false;

        // while(!treasureFound){
        //     //check around (immediate neighbours) the agent for treasure
        //     treasureFound = check4Treasure(currentLoc);

        //     //move randomly one unit
        //     randomMove(currentLoc);
        // }
        
        
        int x = 0;
        while(x != 1){
            std::cout << "Enter 1 to exit: ";
            std::cin.clear();
            std::cin >> x;
        }
        
        std::cout << "Exitting ..." << x;


    }catch(std::invalid_argument& e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}


// bool check4Treasure(mcpp::Coordinate& current){

// }

// void randomMove(mcpp::Coordinate& current){

//     std::random_device r;
//     std::default_random_engine engine(r());
//     std::uniform_int_distribution<int> move_dist(-1, 1);

//     bool valideMove = false;
//     while (!valideMove)
//     {
//         /* code */
//     }
    
    


//     retCoord.x += xLength_dist(engine);
//     retCoord.z += zLength_dist(engine);
//     retCoord.y = mc.getHeight(retCoord.x, retCoord.z)+1;
// }