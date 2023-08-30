#include <iostream>


#include <array>
#include <vector>
#include <list>
#include <deque>

int main(){

   // Array - special initialisation
   std::array<int, 3> array({1,2,3});
   std::cout << "array[0]: " << array[0] 
            << ", array[1]: " << array[1]
            << std::endl;
    array[0] = 100;
    std::cout << "array[0]: " << array[0] 
            << ", array[1]: " << array[1]
            << std::endl;

   // Vector
    std::vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);

    vector[0] = 100;
    std::cout << "vector[0]: " << vector[0] 
            << ", vector[1]: " << vector[1]
            << std::endl;

   // List
    std::list<int> list;
    list.push_back(1);
    list.push_front(2);
    list.push_back(3);

    //list[0] = 100;
    std::cout << "list.front: " << list.front() 
            << ", list.back: " << list.back()
            << std::endl;

   // Deque
   std::deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);

    deque[0] = 100;
    std::cout << "deque[0]: " << deque[0] 
            << ", deque[1]: " << deque[1]
            << std::endl;

   // Map

   // Tuple


    return EXIT_SUCCESS;
}