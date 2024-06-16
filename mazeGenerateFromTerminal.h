#include <iostream>
#include <mcpp/mcpp.h>
#include <string>


bool checkIfOdd(int width, int length){
    bool isOdd = false;
    if ((width % 2 != 0) && ((length % 2 != 0))){
        isOdd = true;
    }
    return isOdd;
}
void printGenerateMazeMenu2(void){
    std::cout << std::endl;
    std::cout << "------------- CREATE A MAZE -------------" << std::endl;
    std::cout << "1) Read Maze from terminal" << std::endl;
    std::cout << "2) Generate Random Maze" << std::endl;
    std::cout << "3) Back" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter Menu item to continue: " << std::endl;
}

void createMazeFromTerminal(){
    mcpp::MinecraftConnection mc;
    mc.postToChat("hello");
    std::cout << "In Minecraft, navigate to where you need the maze\nto be built in Minecraft and type - done:" << std::endl;
    bool playerDoneBool = true;
    std::string playerReady;
    std::getline(std::cin, playerReady);
    

    //checks if user has typed -done.
    if(playerReady != "- done")
    {
        while(playerDoneBool)
        {
            std::getline(std::cin, playerReady);
            if(playerReady == "- done")
            {
                playerDoneBool = false;
            }
        }
    }
    
    //once the player is done we get there coordinates and fix the height of the player 
    mcpp::Coordinate coord = mc.getPlayerPosition() ;
    coord = (coord + mcpp::Coordinate(0,1,0));

    int width, length;
    //now we will read the maze from the player terminal first we need to read the input of the width and the length and check if its odd if not they need to choose another width 
    std::cout << "please enter the width and length of the maze." << std::endl;
    std::cin >> width >> length;

    bool whileTrueOdd = true;
    while(whileTrueOdd)
    {
        if(checkIfOdd(width,length))
        {
            whileTrueOdd = false;
        } else {
            std::cout << "please enter the width and length of the maze of odd numbers." << std::endl;
            std::cin >> width >> length;
        }

    }
    const int SIZE = length;
    std::string Maze[SIZE];
    
    for (int i = 0; i < length; ++i) {
        std::cout << "Enter string " << i + 1 << ": ";
        std::cin >> Maze[i];
    }

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
            break;

        } else if (menuChoiceTwo == 3) {
            return;
        } else {
            std::cout << "invalid input please select from 1, 2 or 3" << std::endl;
            mazeFromTerminalMenu();
        }
        

    }
}

