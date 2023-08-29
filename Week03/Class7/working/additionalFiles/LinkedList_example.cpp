#include <iostream>
#include <random>

#include "LinkedList.h"

int main(void){

    LinkedList DateList;

    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> year_dist(2020, 2023);
    std::uniform_int_distribution<int> month_dist(1, 12);
    std::uniform_int_distribution<int> day_dist(1, 28);

    for(int i=0; i<5; i++){
        std::shared_ptr<Date> temp = std::make_shared<Date>(year_dist(e), month_dist(e), day_dist(e));
        DateList.push_back(temp);
    }

    std::cout << "Size of Date List: " << DateList.size() << std::endl;

    std::cout << "All Dates in LL:" << std::endl;
    for(int i=0; i<5; i++){
        std::cout << "\t: "<< *(DateList.get(i)) << std::endl;
    }

    std::cout << "Last date added: " << *(DateList.back()) << std::endl;

    std::cout << "Removing Last date added: " << std::endl;
    DateList.pop_back();
    std::cout << "Last date Removed: " << std::endl;


    return EXIT_SUCCESS;
}