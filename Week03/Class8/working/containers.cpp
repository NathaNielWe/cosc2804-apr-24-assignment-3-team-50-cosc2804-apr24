#include <iostream>


#include <array>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <utility>

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


    std::cout << "Printing Vector" << std::endl;
    // for(int i =0; i != vector.size(); ++i){
    //     std::cout << "\t vector[" << i << "]: " << vector[i] 
    //         << std::endl;
    // }

    for(int& value : vector){
        std::cout << "\t vector[" << "?" << "]: " << value
            << std::endl;
    }

    std::cout << "Done Printing Vector" << std::endl;

   // List
    std::list<int> list;
    list.push_back(1);
    list.push_front(2);
    list.push_back(3);

    //list[0] = 100;
    std::cout << "list.front: " << list.front() 
            << ", list.back: " << list.back()
            << std::endl;

    for(int& value : list){
        // value = 100;
        std::cout << "\t list[" << "?" << "]: " << value
            << std::endl;
    }

   // Deque
   std::deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);

    deque[0] = 100;
    std::cout << "deque[0]: " << deque[0] 
            << ", deque[1]: " << deque[1]
            << std::endl;

    // Set
    std::set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    std::cout << "size: " << set.size() << std::endl;
    set.insert(2);
    std::cout << "size: " << set.size() << std::endl;
    
    //find if element in set
    // std::cout << "inSet(1): " << set.find(1) << std::endl; // does not work
    bool inSet = set.find(1) != set.end();
    std::cout << "inSet(1): " << inSet << std::endl; 

    inSet = set.find(100) != set.end();
    std::cout << "inSet(100): " << inSet << std::endl; 

    std::cout << "inSet(2): " << *(set.find(2)) << std::endl; 


    for(const int& value : set){
        std::cout << "\t set[" << "?" << "]: " << value
            << std::endl;
    }

   // Map
    std::map<int, std::string> map;
    map[5] = "hello";
    map[-1] = "world";
    map[0] = "!";
    map[5] = "cosc2804";
    std::cout << "map[-1]" << map[-1] << std::endl;
    std::cout << "map[5]" << map[5] << std::endl;

    bool inMap = map.find(5) != map.end();
    std::cout << "inMap(5): " << inMap << std::endl; 

    std::pair<const int, std::string>& resultFind = *(map.find(5)) ;
    std::cout << "Map(5): " << resultFind.second << std::endl; 

    std::cout << "Map(5): " << map.find(5)->second << std::endl; 


    for(const std::pair<const int, std::string>& value : map){
        std::cout << "\t set[" << value.first << "]: " << value.second
            << std::endl;
    }

    for(auto value : map){
        std::cout << "\t set[" << value.first << "]: " << value.second
            << std::endl;
    }

   // Tuple
   std::tuple<double, char> tuple;

   std::get<0>(tuple) = 7.1f; 
   std::get<1>(tuple) = 'a';

   std::get<0>(tuple) = 10.2f; 

   std::cout << "(" << std::get<0>(tuple) << ", " << std::get<1>(tuple)
                << ")" << std::endl;


    return EXIT_SUCCESS;
}