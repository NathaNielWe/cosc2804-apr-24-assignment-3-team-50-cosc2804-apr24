#include <iostream>
#include <mcpp/mcpp.h>

class Field
{
public:
    //Contract:
    //  Expect the field to be on land 
    //  and to be larger than 4 blocks in width and height
    Field(mcpp::Coordinate basePoint, unsigned int xLength, unsigned int zLength);
    ~Field();

    void resetField(void);

    /*
    Provide a random start location for a player
    */
    mcpp::Coordinate getStartLocation(void) const;
    

    /*
    create an osstream with the parameters of a given Field
    */
    friend std::ostream& operator<<(std::ostream&, const Field& f);

private:
    void BuildFence(mcpp::MinecraftConnection& mc);
    void eraseField();
    /*
    Build the fence around the field and place the treasure at a random place
    Contract: Assumes the function is called only once on the for a given field. 
    */
    void SetupField(void);


    mcpp::Coordinate basePoint;
    unsigned int xLength;
    unsigned int zLength;
    mcpp::Coordinate treasureLoc;
};