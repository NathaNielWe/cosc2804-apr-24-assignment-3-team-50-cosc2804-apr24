#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <mcpp/mcpp.h>

class Node{
public:
    mcpp::Coordinate *coord;
    Node* next;
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    /*
    Return the number of nodes in the linked list
    */
    int size() const ;

    /*
    return a pointer to the last added coordinate
    Does not transfer the ownership
    */
    mcpp::Coordinate* back(void) const;

    /*
    Return a pointer to the index coordinate
    Does not transfer ownership
    */
    mcpp::Coordinate* get(int index) const;

    /*
    Removes the last added coordinate. clears the memory
    Assumes there are coordinates to delete
    */
    void pop_back();

    /*
    Adds a coordinate to the list
    */
    void push_back(mcpp::Coordinate* coord);

private:
    Node* head;
};

#endif //LINKEDLIST_H