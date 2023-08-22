#include <iostream>
#include <mcpp/mcpp.h>
#include "Utils.h"
#include <exception>
#include "Field.h"

/*
The code below has some issues.
We will be fixing along the way. Do not assume correctness.
*/

int main(void){

    

    try{
        //Read the length and width
        unsigned int xLength = 0;
        unsigned int zLength = 0;

        mcpp::Coordinate basePoint(0,0,0);

        //Read env size
        ReadFieldParameters(basePoint, xLength, zLength);

        std::cout << basePoint << ", " << xLength <<", " << zLength << std::endl;

        Field field(basePoint, xLength, zLength);
        std::cout << field << std::endl;

        field.SetupField();
        


    }catch(std::invalid_argument& e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
