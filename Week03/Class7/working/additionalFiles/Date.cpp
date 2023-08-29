#include "Date.h"

Date::Date(int year, int month, int day):
                        year(year), month(month), day(day)
{
}

Date::~Date(){
    std::cout << "Deleting Date " << day << "/" << month << "/" << year<< std::endl;
}

std::ostream& operator<<(std::ostream& os, const Date& d){
    os << " " << d.day << "/" << d.month << "/" << d.year << " ";
    return os;
}