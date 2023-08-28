#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <mcpp/mcpp.h>

class Node{
public:
    int *coord;
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
    return the last added int
    */
    int* back(void) const;

    /*
    Return  the index int
    */
    int* get(int index) const;

    /*
    Removes the last added int. clears the memory
    Assumes there are coordinates to delete
    */
    void pop_back();

    /*
    Adds a int to the list
    */
    void push_back(int* num);

private:
    Node* head;
};

#endif //LINKEDLIST_H