#include <iostream>
#include "IntList.h"

using namespace std;

int main () {
    
    IntList testList;
    
    //printing empty list
    cout << endl;
    cout << "Testing printing empy list (<<)" << endl;
    cout << "testList: " << testList << endl;
    cout << endl;
    
    //push_front()
    cout << "Testing push_front(5) on empty list" << endl;
    testList.push_front(5);
    cout << testList << endl;
    cout << endl;

    cout << "Adding push_front(4)" << endl;
    testList.push_front(4);
    cout << testList << endl;
    cout << endl;

    cout << "Adding push_front(3)" << endl;
    testList.push_front(3);
    cout << testList << endl;
    cout << endl;

    //pop_front()
    cout << "testing pop_front()" << endl;
    testList.pop_front();
    cout << testList << endl;
    cout << endl;

    cout << "pop_front()" << endl;
    testList.pop_front();
    cout << testList << endl;
    cout << endl;

    cout << "pop_front()" << endl;
    testList.pop_front();
    cout << testList << endl;
    cout << endl;

    cout << "pop_front() on empty list" << endl;
    testList.pop_front();
    cout << testList << endl;
    cout << endl;

    //push_back()
    cout << "Testing push_back(3) on empty list" << endl;
    testList.push_back(3);
    cout << testList << endl;
    cout << endl;

    cout << "push_back(2)" << endl;
    testList.push_back(2);
    cout << testList << endl;
    cout << endl;

    cout << "push_back(1)" << endl;
    testList.push_back(1);
    cout << testList << endl;
    cout << endl;

    //printReverse
    cout << "testing printReverse" << endl;
    testList.printReverse();
    cout << endl;

    //pop_back()
    cout << "testing pop_back()" << endl;
    testList.pop_back();
    cout << testList << endl;
    cout << endl;

    cout << "pop_back()" << endl;
    testList.pop_back();
    cout << testList << endl;
    cout << endl;

    cout << "pop_back()" << endl;
    testList.pop_back();
    cout << testList << endl;
    cout << endl;

    return 0;
}