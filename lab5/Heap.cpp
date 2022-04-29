#include "Heap.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Heap::Heap() {
    numItems = 0; //empty heap
}

void Heap::enqueue (PrintJob* newJob) {
//insertion in max-heap -- percolate up
    if (numItems == MAX_HEAP_SIZE) {
        cout << "Called enqueue on full stack." << endl;
        return;
    }

    else if (IsEmpty()) {
        arr[0] = newJob; //if first job in heap, make root
        ++numItems;
    }

    else {
        int nodeIndex = numItems;

        while (nodeIndex > 0) {
            int parentIndex = (nodeIndex - 1) / 2;
            if (newJob->getPriority() <= arr[parentIndex]->getPriority()) {
                arr[nodeIndex] = newJob; //if new job is less than or equal priority to parent, place it as child
                ++numItems;
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
        ++numItems;
    }
}

void Heap::dequeue ( ) {
    if (IsEmpty()) {
        cout << "Called dequeue on empty stack." << endl;
        return;
    }
    else if (numItems == 1) {
        --numItems;
    }
    else {
        arr[0] = arr[numItems - 1]; //set root to last leaf
        --numItems; //decrement num of items
        trickleDown(0); //trickle down
    }
}

PrintJob* Heap::highest () {
    if (IsEmpty()) {
        return nullptr;
    }
    else {
        return arr[0];
    }
}

void Heap::print () {
    if (IsEmpty()) {
        cout << "Called print on empty stack." << endl;
        return;
    }
    else {
    cout << "Priority: " << highest()->getPriority() << ", Job Number: " << highest()->getJobNumber() << ", Number of Pages: " << highest()->getPages() << endl;
    }
}


void Heap::trickleDown(int parentIndex) {

    int childIndex = 1;
    int maxIndex = 0;

    while (childIndex < numItems) {

        for (int i = 0; i < 2 && i + childIndex < numItems; ++i) {
            if (arr[i + childIndex]->getPriority() >  arr[maxIndex]->getPriority()) {
                maxIndex = i + childIndex;
            }
        }

        if (arr[maxIndex] == arr[parentIndex]) {
            return;
        }

        else {
            PrintJob* temp = arr[parentIndex];
            arr[parentIndex] = arr[maxIndex];
            arr[maxIndex] = temp;
            parentIndex = maxIndex;
            childIndex = 2 * maxIndex + 1;
        }
    }
}

bool Heap::IsEmpty() {
    if (numItems == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}