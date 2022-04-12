#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index);
template<typename T>
void selection_sort(vector<T> &vals);
template<typename T>
T getElement(vector<T> vals, int index);


template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {

    unsigned int min = index;

    for (unsigned i = index; i < vals.size(); ++i) {
        if (vals.at(i) < vals.at(min)) {
            min = i;
        }
    }
    return min;
}

int main() {

    return 0;
}