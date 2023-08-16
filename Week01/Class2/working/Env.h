#ifndef ENV
#define ENV

#include <mcpp/mcpp.h>

/*
The implimentation of the class below has some issues. 
We will be fixing along the way. Do not assume correctness.
*/


class Env
{
public:
    //constructors and deconstructors
    Env();

    //Contract: expects an integer grater than 0
    Env(unsigned int height, unsigned int width);
    ~Env();

    //other methods
    unsigned int getHeight(void);
    unsigned int getWidth(void);

    void setHeight(unsigned int height);
    void setWidth(unsigned int width);

    void setStart(mcpp::Coordinate* start);

    //Contract: the caller should not change the coordinate
    mcpp::Coordinate* getStart(void) const;

    void setEnvStructure(char** envStructure);
    char** getEnvStructure(void);



private:
    /* data */
    unsigned int height;
    unsigned int width;

    mcpp::Coordinate* start;

    char** envStructure;

};

#endif //ENV