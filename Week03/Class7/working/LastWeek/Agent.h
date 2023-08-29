#ifndef AGENT_H
#define AGENT_H
#include <mcpp/mcpp.h>
#include <vector>

# include "Path.h"

#define MAX_ITER 1000

class Agent
{

public:
    /*
    initialize an agent with Id at a given location.
    Will move the agent to the location in minecraft world
    */
    Agent(unsigned int id, mcpp::Coordinate location);
    ~Agent();

    /*
    Move the agent randomly to one of the reachable adjacent blocks. 
    adgecent cell is one withing 1 unit in x and y direction.
    reachable if the cell is not more that 1 unit high to the current loc.
    if no reachable locations, then returns false else returns true. 
    */
    bool randomStep(void);

    /*
    check the immediate(1 unit around the current loc) neighbourhood for a given type of block
    if the block is found, then treasureCoord is updated.
    Contract:
        only finds the first instance in case there are multiple blocks in neighbourhood
        no change to treasure coord if block not found.
    */
    bool isBlockInNeighborhood(mcpp::BlockType block, mcpp::Coordinate& treasureCoord);

    /*
    Print the path agent has traversed
    */
    void printPath(void);


    void returnToStart(void);

    /*
    Print agent ID and current location to output stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Agent& f);

private:

    bool checkMove(mcpp::Coordinate next);

    /* data */
    unsigned int id;
    mcpp::Coordinate location;

    Path* path;

};

#endif //AGENT_H


