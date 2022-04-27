#include "Heap.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Heap::Heap() {
    numItems = 0; //empty heap
}

void Heap::enqueue (PrintJob* newJob) {
//insertion in max-heap -- percolate up

if (numItems == 0) {
    arr[0] = newJob; //if first job in heap, make root
}

else {
    int nodeIndex = numItems;

    while (nodeIndex > 0) {
        int parentIndex = (nodeIndex - 1) / 2;
        if (newJob->getPriority() <= arr[parentIndex]->getPriority()) {
            arr[nodeIndex] = newJob; //if new job is less than or equal priority to parent, place it as child
            return;
            }

        else {
            //swap parent and child
            PrintJob* temp = newJob;
            arr[nodeIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            nodeIndex = parentIndex; //on next loop, node will be compared to new parent
        }
    }
}
    ++numItems;
}

//FIXME:
void Heap::dequeue ( ) {
    if (numItems < 1)
    {
        return;
    }
    if (numItems == 1)
    {
        delete highest();
        --numItems;
    }
    else
    {
        delete highest();
        arr[0] = arr[numItems - 1];
        delete arr[numItems - 1];
        trickleDown(0);
        --numItems;
    }
}

//FIXME: 
PrintJob* Heap::highest ( ) {

if (numItems > 0) {
    int maxIndex = 0;

    for (int i = 0; i < numItems; ++i) {
        if (arr[i]->getPriority() > arr[maxIndex]->getPriority())
        {
            maxIndex = i;
        }
    }
    return arr[maxIndex];
}
else {
    throw underflow_error("Called highest on empty heap.");
}
}

void Heap::print () {
if (numItems > 0) {
    cout << "Priority: " << highest()->getPriority() << ", Job Number: " << highest()->getJobNumber() << ", Number of Pages: " << highest()->getPages() << endl;
    }
}

//FIXME: 
void Heap::trickleDown(int newRoot) {

int childIndex = 2 * newRoot + 1;

while (childIndex < numItems) {
    int maxIndex = 0;
    for (int i = 0; i < 2 && i + childIndex < numItems; ++i) {
        if (arr[i + childIndex]->getPriority() >  arr[newRoot]->getPriority()) {
            maxIndex = i + childIndex;
        }
    }

    if (arr[maxIndex]->getPriority() == arr[newRoot]->getPriority()) {
        return;
    }

    else {
        PrintJob* temp = arr[newRoot];
        arr[newRoot] = arr[maxIndex];
        arr[maxIndex] = temp;
        childIndex = 2 * newRoot + 1;
    }
}
    
}