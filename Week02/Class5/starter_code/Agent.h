#ifndef AGENT_H
#define AGENT_H
#include <mcpp/mcpp.h>

class Agent
{

public:
    Agent(unsigned int id, mcpp::Coordinate location);
    ~Agent();

    /*
    
    */
    bool randomStep(void);

    /*
    
    */
    bool isBlockInNeighborhood(mcpp::BlockType block, mcpp::Coordinate& treasureCoord);

    /*
    Print agent ID and current location to output stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Agent& f);

private:

    bool checkMove(mcpp::Coordinate next);

    /* data */
    unsigned int id;
    mcpp::Coordinate location;

};

#endif //AGENT_H


