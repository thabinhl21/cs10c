#include <iostream>
#include "IntList.h"

using namespace std;

int main () {
    
    IntList testList;
    cout << "Testing printing empy list (<<)" << endl;
    cout << "testList: " << testList << endl;
    cout << "Testing push_front(5) on empty list" << endl;
    testList.push_back(5);
    testList.push_back(5);
    cout << testList;    

    return 0;
}