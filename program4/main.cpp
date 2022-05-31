#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "Token.h"
using namespace std;

int main() {    
    // get input from file
    string filename;
    ifstream inFS;
    string word;
    HashTable table;
    cout << "Enter the name of the your file: " << endl;
    cin >> filename;

    inFS.open(filename);

    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    while (inFS >> word) {
    //store words in hash table (vector) as WordEntry objects (HashTable::put - do not need to compute hash!)
        table.put(word, 1);
    }

    //WordEntry class
    //string word
    //int code
    //int frequency

    //sort vector based on frequency
    //assign code based on index

    //only using 1 hash table (vector)
    
    //encode function - input token (string), return associated code (int)
    //decode function - input code (int), return associated token (string)

    //overwrite file with encoded words
    //also output decoder (token & code)


    return 0;
}