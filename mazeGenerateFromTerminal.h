#include <iostream>
#include <mcpp/mcpp.h>
#include <string>
#include <string.h>
#include <vector>
#include<cmath>


void PlacePlayerInsideMaze(std::vector<std::string> Maze,int length, int width, int playerPosX, int playerPosY, int playerPosZ)
{
    mcpp::MinecraftConnection mc;
    mcpp::Coordinate playerCoords;

    playerCoords = mcpp::Coordinate(playerPosX,playerPosY,playerPosZ);

//check the perimetre of the maze and the tp the player there
//find outer 
    for(int i = 0; i <length; ++i)
    {
        for (int z = 0; z < width; ++z)
        {
            if(i == 0 || i == length - 1)
            {
                if(Maze[i][z]== '.')
                {  
                    std::cout << "made it" << std::endl;
                    playerCoords = playerCoords + mcpp::Coordinate(z,0,length-i);
                    mc.setPlayerPosition(playerCoords);
                }
            } else {
                if(Maze[i][0] == '.')
                {   
                    width = floor(width/2);
                    playerCoords = playerCoords + mcpp::Coordinate(width,0,i);
                    mc.setPlayerPosition(playerCoords);
                } else if (Maze[i][width-1] == '.')
                {
                    width = floor(width/2);
                    playerCoords = playerCoords + mcpp::Coordinate(-width,0,i);
                    mc.setPlayerPosition(playerCoords);
                }
        }
    }
}
}
void buildMazeInMinecraft(std::vector<std::string> Maze, int playerPosX, int playerPosY, int playerPosZ)
{
    mcpp::MinecraftConnection mc;
    int width = Maze[0].length();
    int length = Maze.size();
    std::cout << length << std::endl;
    std::cout << width << std::endl;
    

        //upper left we will start with 
    mcpp::Coordinate buildCoordsOriginalCopy;
    mcpp::Coordinate buildCoordsOriginal;

    int playerx = ceil((playerPosX + (width/2))+1);
    buildCoordsOriginal = mcpp::Coordinate(playerx,playerPosY-1,playerPosZ + length+1);
    buildCoordsOriginalCopy = mcpp::Coordinate(playerx,playerPosY-1,playerPosZ + length+1);

    std::cout << "Maze generated succesfully\n**Printing Maze**" << std::endl;
    std::cout << "BasePoint: (" << floor(playerPosX) << ", " << floor(playerPosY) << ", " << playerPosZ << ")" << std::endl;
    std::cout << "Structure" << std::endl;
    
    //print structure of the maze

   for(int i = 1; i <=length; ++i)
    {
        for (int z = 1; z <= width; ++z)
        {
            std::cout << Maze[i-1][z-1];
        }
        std::cout << "" << std::endl;
    }



    for(int i = 1; i <=length; ++i)
    {
        for (int z = 1; z <= width; ++z)
        {
            buildCoordsOriginalCopy = mcpp::Coordinate(playerx-z,playerPosY-1,(playerPosZ + length+1)-i);
            mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::ACACIA_WOOD);
            if(Maze[i-1][z-1] == '*')
            {
                mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::ACACIA_WOOD);
            } else {
                mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::AIR);
            }
            buildCoordsOriginalCopy = buildCoordsOriginal;
        }
        
    }
    for(int i = 1; i <=length; ++i)
    {
        for (int z = 1; z <= width; ++z)
        {
            buildCoordsOriginalCopy = mcpp::Coordinate(playerx-z,playerPosY,(playerPosZ + length+1)-i);
            mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::ACACIA_WOOD);
            if(Maze[i-1][z-1] == '*')
            {
                mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::ACACIA_WOOD);
            } else {
                mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::AIR);
            }
            buildCoordsOriginalCopy = buildCoordsOriginal;
        }
        
    }

    for(int i = 1; i <=length; ++i)
    {
        for (int z = 1; z <= width; ++z)
        {
            buildCoordsOriginalCopy = mcpp::Coordinate(playerx-z,playerPosY+1,(playerPosZ + length+1)-i);
            mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::ACACIA_WOOD);
            if(Maze[i-1][z-1] == '*')
            {
                mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::ACACIA_WOOD);
            } else {
                mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::AIR);
            }
            buildCoordsOriginalCopy = buildCoordsOriginal;
        }
        
    }

    PlacePlayerInsideMaze(Maze,length,width,playerPosX,playerPosY,playerPosZ);
        

}

bool checkIfOdd(int width, int length){
    bool isOdd = false;
    if ((width % 2 != 0) && ((length % 2 != 0))){
        isOdd = true;
    }
    return isOdd;
}

std::vector<std::string> userCreateAndCheckMaze(long unsigned int width, int length){
    std::cout << "enter the maze structure:" << std::endl;
    //const int SIZE = length;
    std::vector<std::string> Maze;
    std::string userMazeSegment; 

    for (int i = 0; i < length; ++i) {
        std::cin >> userMazeSegment;
        Maze.push_back(userMazeSegment);
    }
    //passes length checks 
    for(int i = 0; i < length; ++i)
    {
        if(Maze[i].size() != width)
        {
            std::cout << "please make sure the width of the maze is all the same" << std::endl;
            userCreateAndCheckMaze(width, length);
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

void createMazeFromTerminal()
{
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
            } else {
                std::cout << "please type '- done' to confirm coordinates" << std::endl;
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
         std::vector<std::string> Maze = userCreateAndCheckMaze(width, length);
         buildMazeInMinecraft(Maze,coord.x,coord.y,coord.z);
    
    
}

std::vector<std::vector<char>>  divide(std::vector<std::vector<char>>& maze, int x, int y, int width, int height, char orientation) 
{
    if (width < 2 || height < 2) return maze;

    // Choose the direction to split
    bool horizontal = orientation == 'H';

    // Choose the location of the wall and the passage
    int wx = x + (horizontal ? 0 : rand() % (width - 2));
    int wy = y + (horizontal ? rand() % (height - 2) : 0);
    int px = wx + (horizontal ? rand() % width : 0);
    int py = wy + (horizontal ? 0 : rand() % height);

    // Draw the wall
    int dx = horizontal ? 1 : 0;
    int dy = horizontal ? 0 : 1;
    int length = horizontal ? width : height;
    for (int i = 0; i < length; i++) {
        if (wx != px || wy != py) {
            maze[wy][wx] = 'x';
        }
        wx += dx;
        wy += dy;
    }

    // Recursively divide the sub-areas
    int nx = x;
    int ny = y;
    int nw = horizontal ? width : wx - x;
    int nh = horizontal ? wy - y : height;
    divide(maze, nx, ny, nw, nh, orientation == 'H' ? 'V' : 'H');

    nx = horizontal ? x : wx + 1;
    ny = horizontal ? wy + 1 : y;
    nw = horizontal ? width : x + width - wx - 1;
    nh = horizontal ? y + height - wy - 1 : height;
    divide(maze, nx, ny, nw, nh, orientation == 'H' ? 'V' : 'H');
}

std::vector<std::vector<char>> createRandomlyGeneratedMaze()
{  
    int width,height;
    std::cout << "please enter the width and length of the maze." << std::endl;
    std::cin >> width >> height;
    //validation for the maze 
    bool whileTrueOdd = true;
    while(whileTrueOdd)
    {
        if(checkIfOdd(width,height))
        {
            whileTrueOdd = false;
        } else {
            std::cout << "please enter the width and length of the maze of odd numbers." << std::endl;
            std::cin >> width >> height;
        }

    }
    //for the maze generation we will use recursive division but to do this the maze has to be enclosed by borders 
    //the entry point and exit point will be dictated later 
    std::vector<std::vector<char>> maze(height, std::vector<char>(width, '.'));
    for (int i = 0; i < width; i++) 
    {
        maze[0][i] = 'x';
        maze[height - 1][i] = 'x';
    }

    for (int i = 0; i < height; i++) {
        maze[i][0] = 'x';
        maze[i][width - 1] = 'x';
    }

    //Now that the maze is ready we will call the recursive division function 
        divide(maze, 1, 1, width - 2, height - 2, 'H');
    return maze;
}   

std::vector<std::vector<char>>  mazeFromTerminalMenu(void)
{   
    int menuChoiceTwo;
    while(true)
    {
        printGenerateMazeMenu2();
        std::cin >> menuChoiceTwo;
        std::vector<std::vector<char>> Maze;
    

        if(menuChoiceTwo == 1){
            createMazeFromTerminal();
        } else if (menuChoiceTwo == 2) {
            Maze = createRandomlyGeneratedMaze();

            for (const auto& row : Maze) {
                    for (const auto& cell : row) {
                        std::cout << cell;
                    }
                    std::cout << std::endl;
                }

            return Maze;
        } else if (menuChoiceTwo == 3) {
        } else {
            std::cout << "invalid input please select from 1, 2 or 3" << std::endl;
            mazeFromTerminalMenu();
        }
        

    }
}

