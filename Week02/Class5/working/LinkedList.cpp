#include "LinkedList.h"



LinkedList::LinkedList(){
    head = nullptr;
}

LinkedList::~LinkedList(){
    while (head != nullptr)
    {
        pop_back();
    }
    
}

int LinkedList::size() const {
    int length = 0;

    Node* curNode = head;

    while (curNode != nullptr)
    {
        ++length;
        curNode = curNode->next;
    }
    
    return length;
}

mcpp::Coordinate* LinkedList::back(void) const {
    return head->coord;
}

mcpp::Coordinate* LinkedList::get(int index) const{
    mcpp::Coordinate* retCoord = nullptr;
    index = size() - 1 - index;

    if(index >= 0 && index < size() ){
        int counter = 0;
        Node* curNode = head;

        while (counter < index)
        {
            ++counter;
            curNode = curNode->next;
        }
        
        retCoord = curNode->coord;

    }

    return retCoord;

}

void LinkedList::pop_back(){
    Node* toDelete = head;
    head = head->next;
    delete toDelete->coord;
    delete toDelete;
}

void LinkedList::push_back(mcpp::Coordinate* coord){
    Node* node = new Node();
    node->coord = coord;
    node->next = head;
    head = node;
}