#include <iostream>
#include <mcpp/mcpp.h>



int main(void){
    
    mcpp::Coordinate testCoord(3, 2, 1);
    std::cout << testCoord.x << std::endl;

    return EXIT_SUCCESS;
}