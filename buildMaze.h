#include <iostream>
#include <mcpp/mcpp.h>
#include <string>
#include <string.h>
#include <vector>
#include<cmath>


void flattenTerrain()
{


}
mcpp::Coordinate BuildMaze(std::vector<std::vector<char>>& maze )
{
    flattenTerrain();
   mcpp::MinecraftConnection mc;
    int width = maze[0].size();
    int length = maze.size();
    std::cout << length << std::endl;
    std::cout << width << std::endl;
    mcpp::Coordinate coord;

        //upper left we will start with 
    mcpp::Coordinate buildCoordsOriginalCopy;
    mcpp::Coordinate buildCoordsOriginal;

    int playerx = ceil((coord.x + (width/2))+1);
    buildCoordsOriginal = mcpp::Coordinate(playerx,coord.y-1,coord.z + length+1);
    buildCoordsOriginalCopy = mcpp::Coordinate(playerx,coord.y-1,coord.z + length+1);

    std::cout << "Maze generated succesfully\n**Printing Maze**" << std::endl;
    std::cout << "BasePoint: (" << floor(coord.x) << ", " << floor(coord.y) << ", " << coord.z << ")" << std::endl;
    std::cout << "Structure" << std::endl;
    
    //print structure of the maze

   for(int i = 1; i <=length; ++i)
    {
        for (int z = 1; z <= width; ++z)
        {
            std::cout << maze[i-1][z-1];
        }
        std::cout << "" << std::endl;
    }

    std::cout << "**End Printing Maze**" << std::endl;

    
    for(int i = 1; i <=length; ++i)
    {
        for (int z = 1; z <= width; ++z)
        {
            for(int o = 0; o <=2; ++o)
            {
                buildCoordsOriginalCopy = mcpp::Coordinate(playerx-z,coord.y-1+o,(coord.z + length+1)-i);
                mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::ACACIA_WOOD);
                if(maze[i-1][z-1] == '*')
                {
                    mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::ACACIA_WOOD);
                } else {
                    mc.setBlock(buildCoordsOriginalCopy, mcpp::Blocks::AIR);
                }
                buildCoordsOriginalCopy = buildCoordsOriginal;
        
            }
            
        }
        
    }
    mcpp::Coordinate playerTeleportedPosition;
    return playerTeleportedPosition;
}