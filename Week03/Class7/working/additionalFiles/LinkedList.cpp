#include "LinkedList.h"



LinkedList::LinkedList(){
    head = nullptr;
}

LinkedList::~LinkedList(){
    // while (head != nullptr)
    // {
    //     pop_back();
    // }
    
}

// P: LL[head, nullptr]
int LinkedList::size() const {
    // P: LL[head, nullptr]
    int length = 0;
    // P: LL[head, nullptr]
    // length = 0

    std::shared_ptr<Node> curNode = head;
    // length = nElements<LL[head, head)>
    // length = nElements<LL[head, curNode)>

    while (curNode != nullptr)
    {
        // length = nElements<LL[head, curNode)>
        ++length;
        // length = nElements<LL[head, curNode]>
        curNode = curNode->next;
        // length = nElements<LL[head, curNode)>
    }
    // length = nElements<LL[head, nullptr)>
    
    return length;
}
//Q: length = nElements<LL[head, nullptr)>

std::shared_ptr<Date> LinkedList::back(void) const {
    return head->date;
}

std::shared_ptr<Date> LinkedList::get(int index) const{
    std::shared_ptr<Date> retCoord = nullptr;
    index = size() - 1 - index;

    if(index >= 0 && index < size() ){
        int counter = 0;
        std::shared_ptr<Node> curNode = head;

        while (counter < index)
        {
            ++counter;
            curNode = curNode->next;
        }
        
        retCoord = curNode->date;

    }

    return retCoord;

}

void LinkedList::pop_back(){
    //Node* toDelete = head;
    head = head->next;
    //delete toDelete->date;
    //delete toDelete;
}

void LinkedList::push_back(std::shared_ptr<Date> date){
    std::shared_ptr<Node> node = std::make_shared<Node>();
    node->date = date;
    node->next = head;
    head = node;
}