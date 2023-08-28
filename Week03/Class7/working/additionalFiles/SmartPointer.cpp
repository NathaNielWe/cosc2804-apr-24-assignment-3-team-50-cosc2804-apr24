#include <iostream>
#include "Date.h"

#include <memory>

int main(void){
    { 
        //identify the error in this block
        Date* x = new Date(2023, 5, 10);
        Date* y = new Date(2022, 7, 11);

        //x = y;

        std::cout << "Address of x: " << x << std::endl;
        std::cout << "Address of y: " << y << std::endl;

        std::cout << "x: " << x->day << "/" 
                            << x->month << "/" 
                            << x->year << std::endl;

        std::cout << "y: " << y->day << "/" 
                            << y->month << "/" 
                            << y->year << std::endl;

        delete x;
        delete y;

    }


    return EXIT_SUCCESS;
}