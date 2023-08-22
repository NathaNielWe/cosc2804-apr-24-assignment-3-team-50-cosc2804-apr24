#include "Field.h"
#include <random>

#define SEED 100

Field::Field(mcpp::Coordinate basePoint, unsigned int xLength, unsigned int zLength)
{
    this->basePoint.x = basePoint.x;
    this->basePoint.y = basePoint.y;
    this->basePoint.z = basePoint.z;

    this->xLength = xLength;
    this->zLength = zLength;

}

Field::~Field()
{
}

void Field::SetupField(void){

    mcpp::MinecraftConnection mc;
    mc.setPlayerPosition(basePoint + mcpp::Coordinate(0, 1, 0));

    //build fence
    BuildFence(mc);

    // Randomly set the treasure
    std::default_random_engine engine(SEED);
    std::uniform_int_distribution<int> xLength_dist(1, xLength-1);
    std::uniform_int_distribution<int> zLength_dist(1, zLength-1);

    treasureLoc.x = basePoint.x + xLength_dist(engine);
    treasureLoc.z = basePoint.z + zLength_dist(engine);
    treasureLoc.y = mc.getHeight(treasureLoc.x, treasureLoc.z)+1;
    mc.setBlock(treasureLoc + mcpp::Coordinate(0,1,0), mcpp::Blocks::GOLD_BLOCK);


}

void Field::BuildFence(mcpp::MinecraftConnection& mc){

    // build he fence for two length sides
    for(unsigned int i = 0; i<xLength; i++){
        mcpp::Coordinate temp(basePoint);
        temp.x += i;
        temp.y = mc.getHeight(temp.x, temp.z)+1;
        mc.setBlock(temp, mcpp::Blocks::BIRCH_FENCE);

        temp.z += zLength;
        temp.y = mc.getHeight(temp.x, temp.z)+1;
        mc.setBlock(temp, mcpp::Blocks::BIRCH_FENCE);

    }

    // build he fence for two width sides
    for(unsigned int i = 0; i<zLength; i++){
        mcpp::Coordinate temp(basePoint);
        temp.z += i;
        temp.y = mc.getHeight(temp.x, temp.z)+1;
        mc.setBlock(temp, mcpp::Blocks::BIRCH_FENCE);

        temp.x += xLength;
        temp.y = mc.getHeight(temp.x, temp.z)+1;
        mc.setBlock(temp, mcpp::Blocks::BIRCH_FENCE);

    }

}


std::ostream& operator<<(std::ostream& os, const Field& f){
    os << "<< BasePoint: " << f.basePoint << "; Length: " 
                                    << f.xLength << "; Width: " 
                                    << f.zLength << " >>";
    return os;
}