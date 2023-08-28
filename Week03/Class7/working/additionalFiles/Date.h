#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
public:
    Date(int year, int month, int day);
    ~Date();

    int year;
    int month;
    int day;
};

#endif