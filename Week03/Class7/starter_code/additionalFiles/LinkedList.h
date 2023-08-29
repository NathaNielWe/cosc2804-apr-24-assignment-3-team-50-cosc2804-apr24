#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <mcpp/mcpp.h>
#include "Date.h"

class Node{
public:
    Date* date;
    Node* next;
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    /*
    Return the number of dates in the linked list
    */
    int size() const ;

    /*
    return the last added date
    */
    Date* back(void) const;

    /*
    Return  the index date
    */
    Date* get(int index) const;

    /*
    Removes the last added date. clears the memory
    Assumes there are dates to delete
    */
    void pop_back();

    /*
    Adds a date to the list
    */
    void push_back(Date* num);

private:
    Node* head;
};

#endif //LINKEDLIST_H