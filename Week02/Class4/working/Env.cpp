#include "Env.h"

Env::Env()
{
    this->height = 0;
    this->width = 0;

    envStructure = nullptr;
    start = nullptr;
}

Env::Env(unsigned int height, 
        unsigned int width, 
        char** envStructure, mcpp::Coordinate* start):
                        height(height),
                        width(width)
{
    this->envStructure = envStructure;
    this->start = start;
}

Env::Env(const Env& other):
                        height(other.height),
                        width(other.width)
{
    this->envStructure = new char*[height];
    for(unsigned int i =0; i < height; i++){
        envStructure[i] = new char[width];
    }

    for(unsigned int h =0; h < height; h++){
        for(unsigned int w = 0; w < height; w++){
            this->envStructure[h][w] = other.envStructure[h][w];
        }
    }

    this->start = new mcpp::Coordinate(*(other.start));
}

Env::~Env()
{
    if(envStructure != nullptr){
        for(unsigned int i =0; i < height; i++){
            delete[] envStructure[i];
            envStructure[i] = nullptr;
        }
        delete[] envStructure;
        envStructure = nullptr;
    }

    if(start != nullptr){
        delete start;
        start = nullptr;
    }
}


unsigned int Env::getHeight(void) const {
    return this->height;
}

unsigned int Env::getWidth(void) const {
    return this->width;
}

void Env::setHeight(unsigned int height){
    this->height = height;
}

void Env::setWidth(unsigned int width){
    this->width = width;
}

//Identify is there are any issues
void Env::setStart(mcpp::Coordinate* start){
    if(this->start != nullptr){
        delete this->start;
    }
    this->start = start;
}

const mcpp::Coordinate* Env::getStart(void) const{
    return (const mcpp::Coordinate*)this->start;
}

//Identify is there are any issues
void Env::setEnvStructure(char** envStructure){
    if(this->envStructure != nullptr){
        for(unsigned int i =0; i < height; i++){
            delete[] this->envStructure[i];
        }
        delete[] this->envStructure;
    }
    this->envStructure = envStructure;
}

const char** Env::getEnvStructure(void) const{
    return (const char**)this->envStructure;
}

