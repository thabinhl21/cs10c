
#include "WordLadder.h"

#include <stack>
#include <queue>
#include <fstream>
#include <iostream>
#include <vector>

WordLadder::WordLadder(const string &filename) {
    ifstream inFS;
    string word;

    inFS.open(filename);

    if (!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        return;
    }

    //extract words from the file
    while (inFS >> word) {
        //check to see if word has exactly 5 letters
        if (word.size() != 5) {
            cout << "Error: Word is not exactly 5 letters long." << endl;
            return;
        }
        // fill the list with the 5-letter words from the file
        dict.push_back(word);
    }
    inFS.close();
}

// THIS FUNCTION IS NOT FINISHED AND THEREFORE HAS NOT BEEN TESTED
void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    string currWord;
    //create a stack
    stack<string> s;
    //create a queue of stacks
    queue<stack<string> > q;

    s.push(start);

    //add stack to queue
    q.push(s);

    while (!q.empty()) {

        //get the word on top of the front stack of the queue
        currWord = q.front().top();
        //iterate through dict
        for (i = 0; i < dict.size(); ++i) {
            int numDiff = 0;
            // comparing the top word from the stack to each word in dict
            for (j = 0; j < currWord.size(); ++j) {
                // comparing letters of the word in the dict to the top word
                if (i.at(j) != currWord.at(j)) {
                    numDiff += 1;
                }
            }
            if (numDiff == 1) {
                // if dict word is off by just 1 letter from top word
                // create a copy of the front stack
                stack<string> newStack;
                newStack = q.front();
                newStack.push(currWord);

                //if that word is the end of the word ladder
                //output word ladder to file
                if (currWord == end) {
                    ofstream outFS;
                    string word;
                    vector<string> wordVec;

                    outFS.open(outputFile);

                    if (!outFS.is_open()) {
                        cout << "Error opening " << outputFile << endl;
                        return;
                    }

                    // add words from the stack into a vector to print in reverse
                    while (!newStack.empty()) {
                        word = newStack.top();
                        wordVec.push_back(word);
                        newStack.pop();
                    }

                    // iterating through vector and outputting to file the words in reverse
                    for (unsigned int i = wordVec.size() - 1; i >= 0; ++i) {
                        outFS << wordVec.at(i) << endl;
                    }
                    outFS.close();

                }
            }
        }

    }

}
