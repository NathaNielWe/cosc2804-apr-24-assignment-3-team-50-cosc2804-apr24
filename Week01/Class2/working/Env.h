#ifndef ENV
#define ENV

#include <mcpp/mcpp.h>

class Env
{
public:
    //constructors and deconstructors
    Env();
    Env(int height, int width);
    ~Env();

    //other methods
    int getHeight(void);
    int getWidth(void);

    void setHeight(int height);
    void setWidth(int width);

    void setStart(mcpp::Coordinate* start);
    mcpp::Coordinate* getStart(void);

    void setEnvStructure(char** envStructure);
    char** getEnvStructure(void);



private:
    /* data */
    int height;
    int width;

    mcpp::Coordinate* start;

    char** envStructure;

};

#endif //ENV