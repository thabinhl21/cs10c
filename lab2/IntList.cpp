#include "IntList.h"

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    dummyHead->prev = nullptr;
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
    dummyTail->next = nullptr;
}

IntList::~IntList() {
    
    while (dummyHead != nullptr) {
        IntNode* temp;
        temp = dummyHead;
        dummyHead = dummyHead->next;
        delete temp;
    }
}

void IntList::push_front(int value) {
    IntNode *n;
    n = new IntNode(value);

    // if list is empty
    if (dummyHead == nullptr) {
        dummyHead->next = n;
        dummyTail->prev = n;
        n->next = dummyTail;
        n->prev = dummyHead;
    }

    // if only 1 element in list
    else if (dummyHead == dummyTail) {
        dummyHead->prev = n; // insert new node n before head
        n->next = dummyHead; 
        dummyHead->next = dummyTail;
    }
    
    else {
        n->next = dummyHead;
        dummyHead = n;
    }
}
