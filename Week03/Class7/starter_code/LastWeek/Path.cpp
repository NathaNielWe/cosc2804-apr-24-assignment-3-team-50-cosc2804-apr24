#include "Path.h"

Path::Path()
{
}

Path::~Path()
{
    // for(int i = 0; i<savePath.size(); i++){
    //     delete savePath[i];
    // }
}


void Path::pushCoordinate(mcpp::Coordinate loc){
    mcpp::Coordinate* temp = new mcpp::Coordinate(loc.x, loc.y, loc.z);
    savePath.push_back(temp);
}

mcpp::Coordinate Path::popCoordinate(void){
    mcpp::Coordinate retCoord(0,0,0);
    if(savePath.size() != 0){
        retCoord.x = savePath.back()->x;
        retCoord.y = savePath.back()->y;
        retCoord.z = savePath.back()->z;

        //delete savePath.back();
        savePath.pop_back();
    }

    return retCoord;
}

int Path::getLength(void){
    return (int)savePath.size();
}


std::ostream& operator<<(std::ostream& os, const Path& p){
    os << "Path has " << p.savePath.size() << " nodes." << std::endl;
    for(int i = 0; i < p.savePath.size(); i++){
        os << "[" << i << "] \t :" << *(p.savePath.get(i)) << std::endl; 
    }

    return os;
}