#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap() {
    numItems = 0; //empty heap
}

void Heap::enqueue (PrintJob* newJob) {
//insertion in max-heap -- percolate up

if (numItems == 0) {
    arr[0] = newJob;
}

else {
    int nodeIndex = numItems;

    while (nodeIndex > 0) {
        int parentIndex = (nodeIndex - 1) / 2;
        if (newJob->getPriority() <= arr[parentIndex]->getPriority()) {
            arr[nodeIndex] = newJob;
            return;
            }

        else {
            PrintJob* temp = newJob;
            arr[nodeIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            nodeIndex = parentIndex; //on next loop, node will be compared to new parent
        }
    }
}
    ++numItems;
}


void Heap::dequeue ( ) {


}

PrintJob* Heap::highest ( ) {
    return arr[0];
}

void Heap::print ( ) {

if (numItems > 0) {
    cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
    }


}

void Heap::trickleDown(int newRoot) {
    
}