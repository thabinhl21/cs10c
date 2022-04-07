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
    
    IntNode* currNode = dummyHead->next;
    IntNode* sucNode = dummyHead->next->next;

    while (currNode != dummyTail) {
        delete currNode;
        currNode = sucNode;
        sucNode = sucNode->next;
    }
}

void IntList::push_front(int value) {
    IntNode *n = new IntNode(value);
    dummyHead->next->prev = n;
    n->next = dummyHead->next;
    n->prev = dummyHead;
    dummyHead->next = n;
}

void IntList::pop_front()
{
    if (!empty())
    {
        IntNode* currNode = dummyHead->next;
        IntNode* sucNode = currNode->next;
        dummyHead->next = sucNode;
        sucNode->prev = dummyHead;
        delete currNode;
    }
}

void IntList::push_back(int value)
{
    IntNode* pushBack = new IntNode(value);

    //push back in empty list
    if (dummyHead == nullptr)
    {
        dummyHead->next = pushBack;
        pushBack->prev = dummyHead;
        pushBack->next = dummyTail;
        dummyTail->prev = pushBack;
    }
    else
    {
        IntNode* oldTail = dummyTail->prev;
        oldTail->next = pushBack;
        pushBack->next = dummyTail;
        pushBack->prev = oldTail;
        dummyTail->prev = pushBack;
    }
}

void IntList::pop_back() {
    
    if (!empty()) {
        IntNode* temp = dummyTail->prev;
        temp->prev->next = dummyTail;
        dummyTail->prev = temp->prev;
        delete temp;
    }
}
    
bool IntList::empty() const
{
    if (dummyHead->next == dummyTail)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    
ostream & operator<<(ostream &out, const IntList &rhs)
{
    if (!rhs.empty())
    {
        IntNode* curr = rhs.dummyHead->next;

        while (curr != rhs.dummyTail)
        {
            if (curr->next != rhs.dummyTail)
            {  
                out << curr->data << " ";
            }
            else
            {
                out << curr->data;
            }
            curr = curr->next;
        }
        return out;
    }
    else
    {
        out << "";
        return out;
    }
}
    
void IntList::printReverse() const
{
    if (!empty())
    {
        IntNode* curr = dummyTail->prev;
        while (curr != dummyHead)
        {
            if (curr->prev != dummyHead) {
                cout << curr->data << " ";
            }
            else {
            cout << curr->data;
            }
            curr = curr->prev;
        }
    }
}