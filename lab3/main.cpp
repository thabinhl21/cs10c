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

template<typename T>
void selection_sort(vector<T> &vals) {
    unsigned int indexMin;
    T temp;

    for (unsigned int i = 0; i < vals.size(); ++i) {
        indexMin = min_index(vals,i);
        temp = vals.at(i);
        vals.at(i) = vals.at(indexMin);
        vals.at(indexMin) = temp;
    }
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T>
T getElement(vector<T> vals, int index) {
    if (index < 0 || index >= vals.size())
    {
        throw out_of_range;
    }
    return vals.at(index);
}

int main() {
    
    //testing selection_sort
    cout << "Testing selection_sort on integers:" << endl;
    vector<int> testVec;

    for (unsigned int i = 0; i < 20; ++i) {
        testVec.push_back(rand() % 20 + 1);
    }

    selection_sort(testVec);

    for (unsigned int i = 0; i < testVec.size(); ++i) {
        cout << testVec.at(i) << " ";
    }

    cout << endl;

    cout << "Testing selection_sort on strings:" << endl;

    vector<string> testVecString{"University", "Of", "California", "Riverside", "Cs10c", "Class", "Section", "Two"};
    selection_sort(testVecString);

    for (unsigned int i = 0; i < testVecString.size(); ++i) {
        cout << testVecString.at(i) << " ";
    }

    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        curChar = getElement(vals,index);
        cout << "Element located at " << index << ": is " << curChar << endl;
    }


    
        try {
            cout << "Enter a number: " << endl;
            cin >> index;
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch (out_of_range &excpt)
        {
            cout << excpt.what() << endl;
            cout << "out of range exception occured" << endl;
        }
    return 0;
}