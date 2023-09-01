#include "Field.h"
#include <random>
#include <chrono>
#include <map>
#include <vector>

Field::Field(mcpp::Coordinate basePoint, unsigned int xLength, unsigned int zLength)
{
    this->basePoint.x = basePoint.x;
    this->basePoint.y = basePoint.y;
    this->basePoint.z = basePoint.z;

    this->xLength = xLength;
    this->zLength = zLength;

    SetupField();
}

Field::~Field()
{
    eraseField();
    mcpp::MinecraftConnection mc;
    mc.setBlock(treasureLoc + mcpp::Coordinate(0,1,0), mcpp::Blocks::AIR);
}

void Field::resetField(void){

    eraseField();
    
    mcpp::MinecraftConnection mc;
    mc.setBlock(treasureLoc + mcpp::Coordinate(0,1,0), mcpp::Blocks::AIR);

    SetupField();

}

void Field::SetupField(void){

    mcpp::MinecraftConnection mc;
    // mc.setPlayerPosition(basePoint + mcpp::Coordinate(0, 1, 0));

    //build fence
    BuildFence(mc);

    std::random_device r;

    // Randomly set the treasure
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> xLength_dist(1, xLength-1);
    std::uniform_int_distribution<int> zLength_dist(1, zLength-1);

    treasureLoc.x = basePoint.x + xLength_dist(engine);
    treasureLoc.z = basePoint.z + zLength_dist(engine);
    treasureLoc.y = mc.getHeight(treasureLoc.x, treasureLoc.z);
    mc.setBlock(treasureLoc + mcpp::Coordinate(0,1,0), mcpp::Blocks::GOLD_BLOCK);

}

void setupWall(mcpp::MinecraftConnection& mc, mcpp::Coordinate loc){
    for(int i = 0; i < WALL_HEIGHT; i++){
        mc.setBlock(loc + mcpp::Coordinate(0,i,0), mcpp::Blocks::BROWN_CONCRETE);
    }
}

void removeWall(mcpp::MinecraftConnection& mc, mcpp::Coordinate loc){
    for(int i = 0; i < WALL_HEIGHT; i++){
        if(mc.getBlock(loc + mcpp::Coordinate(0,-i,0)) == mcpp::Blocks::BROWN_CONCRETE){
            mc.setBlock(loc + mcpp::Coordinate(0,-i,0), mcpp::Blocks::AIR);
        }
    }
}


void Field::BuildFence(mcpp::MinecraftConnection& mc){

    // build he fence for two length sides
    for(unsigned int i = 0; i<xLength+1; i++){
        mcpp::Coordinate temp = basePoint.clone(); 
        temp.x += i;
        temp.y = mc.getHeight(temp.x, temp.z)+1;
        setupWall(mc, temp);

        temp.z += zLength;
        temp.y = mc.getHeight(temp.x, temp.z)+1;
        setupWall(mc, temp);

    }

    // build he fence for two width sides
    for(unsigned int i = 1; i<zLength; i++){
        mcpp::Coordinate temp = basePoint.clone(); 
        temp.z += i;
        temp.y = mc.getHeight(temp.x, temp.z)+1;
        setupWall(mc, temp);

        temp.x += xLength;
        temp.y = mc.getHeight(temp.x, temp.z)+1;
        setupWall(mc, temp);

    }

}


void Field::eraseField(){
    mcpp::MinecraftConnection mc;
    
    // delete fence for two length sides
    for(unsigned int i = 0; i<xLength+1; i++){
        mcpp::Coordinate temp = basePoint.clone(); 
        temp.x += i;
        temp.y = mc.getHeight(temp.x, temp.z);
        removeWall(mc, temp);

        temp.z += zLength;
        temp.y = mc.getHeight(temp.x, temp.z);
        removeWall(mc, temp);

    }

    // delete fence for two width sides
    for(unsigned int i = 0; i<zLength+1; i++){
        mcpp::Coordinate temp = basePoint.clone(); 
        temp.z += i;
        temp.y = mc.getHeight(temp.x, temp.z);
        removeWall(mc, temp);

        temp.x += xLength;
        temp.y = mc.getHeight(temp.x, temp.z);
        removeWall(mc, temp);

    }
}


mcpp::Coordinate Field::getStartLocation(void) const{

    mcpp::MinecraftConnection mc;
    mcpp::Coordinate retCoord = basePoint.clone();

    std::random_device r;

    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> xLength_dist(1, xLength-1);
    std::uniform_int_distribution<int> zLength_dist(1, zLength-1);

    retCoord.x += xLength_dist(engine);
    retCoord.z += zLength_dist(engine);
    retCoord.y = mc.getHeight(retCoord.x, retCoord.z) + 1;

    return retCoord;
}

void Field::floodFill(mcpp::Coordinate start, mcpp::BlockType block){
    mcpp::MinecraftConnection mc;
    
    floodFill(start, start, block, mc);

}

void Field::floodFill(mcpp::Coordinate curr, mcpp::Coordinate prev, 
                                                mcpp::BlockType block,
                                                mcpp::MinecraftConnection& mc)
{
    
    if(mc.getHeight(curr.x, curr.z) != mc.getHeight(prev.x, prev.z)){
        //Base-case 1: not same elevation 
        //      do nothing

    }else if(mc.getBlock(curr) == block){
        //Base-case 2: already filled 
        //      do nothing
    }else{
        //Recursive step
        mc.setBlock(curr, block);

        std::vector< mcpp::Coordinate > neighbourhood;
        neighbourhood.push_back(mcpp::Coordinate(1,0,0));    //up
        neighbourhood.push_back(mcpp::Coordinate(-1,0,0));   //down
        neighbourhood.push_back(mcpp::Coordinate(0,0,1));    //right
        neighbourhood.push_back(mcpp::Coordinate(0,0,-1));   //left


        for(mcpp::Coordinate& offset : neighbourhood){

            mcpp::Coordinate xPlus(
                                    curr.x+offset.x, 
                                    mc.getHeight(curr.x+offset.x, curr.z+offset.z)+1 ,
                                    curr.z+offset.z);

            floodFill(xPlus, curr, block, mc);
        }
        // mcpp::Coordinate xPlus(curr.x+1, mc.getHeight(curr.x+1, curr.z)+1 ,curr.z);
        // floodFill(xPlus, curr, block, mc);

        // mcpp::Coordinate xMinus(curr.x-1, mc.getHeight(curr.x-1, curr.z)+1 ,curr.z);
        // floodFill(xMinus, curr, block, mc);

        // mcpp::Coordinate zPlus(curr.x, mc.getHeight(curr.x, curr.z+1)+1 ,curr.z+1);
        // floodFill(zPlus, curr, block, mc);

        // mcpp::Coordinate zMinus(curr.x, mc.getHeight(curr.x, curr.z-1)+1 ,curr.z-1);
        // floodFill(zMinus, curr, block, mc);

    }
}

std::ostream& operator<<(std::ostream& os, const Field& f){
    os << "<< BasePoint: " << f.basePoint << "; Length: " 
                                    << f.xLength << "; Width: " 
                                    << f.zLength << " >>"; 
                                    
    return os;
}