#include <iostream>
#include <mcpp/mcpp.h>


void printGenerateMazeMenu2(void){
    std::cout << std::endl;
    std::cout << "------------- CREATE A MAZE -------------" << std::endl;
    std::cout << "1) Read Maze from terminal" << std::endl;
    std::cout << "2) Generate Random Maze" << std::endl;
    std::cout << "3) Back" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter Menu item to continue: " << std::endl;
}

void mazeFromTerminalMenu(void)
{   
    int menuChoiceTwo;
    while(true)
    {
        printGenerateMazeMenu2();
        std::cin >> menuChoiceTwo;
    

        if(menuChoiceTwo == 1){
            createMazeFromTerminal();
        } else if (menuChoiceTwo == 2) {

        } else if (menuChoiceTwo == 3) {
            return;
            break;
        } else {
            std::cout << "invalid input please select from 1, 2 or 3" << std::endl;
            mazeFromTerminalMenu();
        }
    }
}

void createMazeFromTerminal(){
    std::cout << "In Minecraft, navigate to where you need the maze\nto be built in Minecraft and type - done:" << std::endl;

}