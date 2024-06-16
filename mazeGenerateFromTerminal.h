#include <iostream>
#include <mcpp/mcpp.h>
#include <string>
#include <string.h>
#include <vector>




bool checkIfOdd(int width, int length){
    bool isOdd = false;
    if ((width % 2 != 0) && ((length % 2 != 0))){
        isOdd = true;
    }
    return isOdd;
}

std::vector<std::string> userCreateAndCheckMaze(int width, int length){
    std::cout << "enter the maze structure:" << std::endl;
    const int SIZE = length;
    std::vector<std::string> Maze;
    std::string userMazeSegment; 
    
    for (int i = 0; i < length; ++i) {
        std::cout << "Enter string " << i + 1 << ": ";
        std::cin >> userMazeSegment;
        Maze.push_back(userMazeSegment);
    }
    //passes length checks 
    for(int i = 0; i < length; ++i)
    {
        if(Maze[i].length() != width)
        {
            std::cout << "please make sure the width of the maze is all the same" << std::endl;
            userCreateAndCheckMaze(width, length);
        }
    }

    for(int i = 0; i < length; ++i)
    {
        for(int x = 0; x < width; ++x)
        {
            std::string stringArray = Maze[i];
            if(stringArray[x] != '*' || stringArray[x] != '.' )
            {
                std::cout << "please make sure the chars of the maze are all the same e.g. '*' for walls and '.' for open spaces " << std::endl;
                userCreateAndCheckMaze(width, length);
            } 
            
        }
    }
    return Maze;
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

