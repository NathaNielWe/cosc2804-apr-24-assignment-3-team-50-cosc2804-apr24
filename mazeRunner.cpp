#include <iostream>

#include <mcpp/mcpp.h>

#include "Maze.h"
#include "Agent.h"
#include "menuUtils.h"

#define NORMAL_MODE 0
#define TESTING_MODE 1

enum States{
    ST_Main,
    ST_GetMaze,
    ST_SolveMaze,
    ST_Creators,
    ST_Exit
};

int main(void){

    bool mode = NORMAL_MODE;
    int menuChoice;
    //read Mode

    

    mcpp::MinecraftConnection mc; 
    mc.doCommand("time set day"); 

    States curState = ST_Main;
    printStartText();

    //State machine for menu        
    while (curState != ST_Exit)
    {
        printMainMenu();

        std::cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            break;
        case 2:
            
            break;
        case 3:

            break;
        case 4:
            break;
        case 5:
            printExitMassage();
            exit(1);
            break;
        
        default:
            break;
        }
    }
    

    return EXIT_SUCCESS;

}

