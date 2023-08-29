#include <iostream>
#include <string>

int factorial(int num);

int getFibonacci(int num);

int main(int argc, char** argv){

    if(argc < 3){
        std::cout << "Error: need to provide flag [-fact: Factorial, -fibo: Fibonacci] and an integer" << std::endl;
    }else{
        std::string flag = argv[1];
        std::string string_num = argv[2];

        if(flag == "-fact"){
            int num = std::stoi(string_num);
            if(num > 0){
                std::cout << "Factorial of " << num << " is : " << factorial(num) << std::endl;
            }

        }else if(flag == "-fibo"){
            int num = std::stoi(string_num);
            if(num > 0){
                std::cout << num << "th Fibonacci number is : " << getFibonacci(num) << std::endl;
            }
        }else{
            std::cout << "Error: Incorrect flag; enter [-fact: Factorial, -fibo: Fibonacci]" << std::endl;
        }

    }
    

    return EXIT_SUCCESS;
}

int factorial(int num){

    int retValue = 0;

    //base case
    if(num == 0){
        retValue = 1;
    }else{
        //recursive or inductive step
        retValue = num * factorial(num-1);
    }
    return retValue;
}

int getFibonacci(int num){
    int retValue = 0;

    if(num == 1){
        //base case 1
        retValue = 0;
    }else if (num ==2){
        //Base case 2
        retValue = 1;
    }else{
        // recursive or inductive step
        retValue = getFibonacci(num - 1) + getFibonacci(num - 2);
    }

    return retValue;

}