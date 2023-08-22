#include <iostream>
#include <mcpp/mcpp.h>
#include <exception>

void ReadFieldParameters(mcpp::Coordinate& basePoint, unsigned int& xLength, unsigned int& zLength){

    
    std::cout << "Enter the Length and Width of the field: " << std::endl;
    std::cin >> xLength;
    std::cin >> zLength;

    if (xLength < 4 || zLength < 4){
        throw std::invalid_argument("Height and width arguments are not correct!");
    }

    int basePointX=0;
    int basePointY=0;
    int basePointZ=0;
    bool success = true;

    std::cout << "Enter the basePoint coordinate (X, Y, Z): " << std::endl;
    
    std::cin >> basePointX;
    if(std::cin.fail()){
        success = false;
    }

    std::cin >> basePointY;
    if(std::cin.fail()){
        success = false;
    }

    std::cin >> basePointZ;
    if(std::cin.fail()){
        success = false;
    }

    if(success){
         basePoint.x = basePointX;
         basePoint.y = basePointY;
         basePoint.z = basePointZ;
    }else{
        throw std::invalid_argument("Start coordinate incorrect!");
    }

}