#ifndef ENV
#define ENV

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



private:
    /* data */
    int height;
    int width;
};

#endif //ENV