#include "Env.h"

Env::Env(/* args */)
{
    this->height = 0;
    this->width = 0;
}

Env::Env(int height, int width):
                        height(height),
                        width(width)
{
}

Env::~Env()
{
}


int Env::getHeight(void){
    return this->height;
}

int Env::getWidth(void){
    return this->width;
}
