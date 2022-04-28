#include "WordLadder.h"

#include <stack>
#include <queue>
#include <fstream>
#include <iostream>


WordLadder::WordLadder(const string &filename) {
    ifstream inFS;
    string word;

    inFS.open(filename);

    if (!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        return;
    }

    while (inFS >> word) {
        if (word.size() != 5) {
            cout << "Error: Word is not exactly 5 letters long." << endl;
            return;
        }

        dict.push_back(word);

    }

    inFS.close();

}