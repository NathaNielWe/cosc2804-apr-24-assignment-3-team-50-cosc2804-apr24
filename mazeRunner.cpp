#include <iostream>

#include <mcpp/mcpp.h>
#include "buildMaze.h"
#include "Maze.h"
#include "Agent.h"
#include "menuUtils.h"
#include "mazeGenerateFromTerminal.h"
#include "solveMaze.h"

#define NORMAL_MODE 0
#define TESTING_MODE 1

enum States{
    ST_Main,
    ST_GetMaze,
    ST_SolveMaze,
    ST_Creators,
    ST_Exit
};

int main(int argc, char* argv[]){

    //bool mode = NORMAL_MODE;
    int menuChoice;
    //read Mode

    

    mcpp::MinecraftConnection mc; 
    mc.doCommand("time set day"); 

    States curState = ST_Main;
    printStartText();
    std::vector<std::vector<char>> maze;
    mcpp::Coordinate playerTeleportedPos;
    //State machine for menu        
    while (curState != ST_Exit)
    {
        printMainMenu();

        std::cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            maze = mazeFromTerminalMenu();
        case 2:
            playerTeleportedPos = BuildMaze(maze);
        case 3:
            SolveManually();
        case 4:
            printTeamInfo();    
        case 5:
            printExitMassage();
            exit(1);
        }
    }
    

    return EXIT_SUCCESS;

}

