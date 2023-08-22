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

    void SetupField(void);

    friend std::ostream& operator<<(std::ostream&, const Field& f);

private:
    void BuildFence(mcpp::MinecraftConnection& mc);


    mcpp::Coordinate basePoint;
    unsigned int xLength;
    unsigned int zLength;
    mcpp::Coordinate treasureLoc;
};