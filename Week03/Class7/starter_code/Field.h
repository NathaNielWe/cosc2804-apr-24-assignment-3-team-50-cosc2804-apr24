#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <mcpp/mcpp.h>

#define WALL_HEIGHT 5

class Field
{
public:
    
    /*
    constructs a field by building concreate walls in minecraft world at given basepoint
    with sides equal to xLength and zLength. Sets the treasure (Gold) at a random location within
    the field. 
    */
    //Contract:
    //  Expect the field to be on land 
    //  and to be larger than 4 blocks in width and height
    Field(mcpp::Coordinate basePoint, unsigned int xLength, unsigned int zLength);
    
    /*
    Delete the walls and the treasure from minecraft world.
    */
    ~Field();

    /*
    Delete the existing walls and treasure and rebuild
    */
    void resetField(void);

    /*
    Provide a random location withing the field
    */
    mcpp::Coordinate getStartLocation(void) const;
    

    /*
    create an osstream with the parameters of a given Field
    */
    friend std::ostream& operator<<(std::ostream& os, const Field& f);

private:

    void BuildFence(mcpp::MinecraftConnection& mc);
    void eraseField();
    void SetupField(void);

    // Data
    mcpp::Coordinate basePoint;
    unsigned int xLength;
    unsigned int zLength;
    mcpp::Coordinate treasureLoc;
};

#endif //FIELD_H