#include <iostream>
#include "IntList.h"

using namespace std;

int main () {
    
    IntList testList;
    
    cout << "Testing printing empy list (<<)" << endl;
    cout << "testList: " << testList << endl;
    cout << endl;
    
    cout << "Testing push_front(5) on empty list" << endl;
    testList.push_front(5);
    cout << testList << endl;

    cout << "Adding push_front(4)" << endl;
    testList.push_front(4);
    cout << testList << endl;

    cout << "Adding push_front(3)" << endl;
    testList.push_front(3);
    cout << testList << endl;

    return 0;
}