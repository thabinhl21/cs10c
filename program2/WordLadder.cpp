// Got help with list iterator from https://www.codegrepper.com/code-examples/cpp/how+to+iterate+through+list+c%2B%2B
#include "WordLadder.h"

#include <stack>
#include <queue>
#include <fstream>
#include <iostream>
#include <vector>

WordLadder::WordLadder(const string &filename) {
    ifstream inFS;
    inFS.open(filename);

    if (!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        return;
    }
    string word;
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

bool WordLadder::offByOne(const string &s1, const string &s2) const {
	unsigned int numDiff = 0;
    string currWord = s1;
    string dictWord = s2;
    // comparing the top word from the stack to each word in dict
    for (unsigned int j = 0; j < currWord.size(); ++j) {
        // comparing letters of the word in the dict to the top word
        if (dictWord.at(j) != currWord.at(j)) {
            numDiff += 1;
        }
    }
    return numDiff == 1;
}

bool WordLadder::findLadder(stack<string> &s, const string &end) {
    
    //create a queue of stacks
    queue<stack<string> > q;
    
    //add stack to queue
    q.push(s);

    //loop for finding a word ladder
    while (!q.empty()) {
        //get the word on top of the front stack of the queue
        
        string currWord = q.front().top();
        stack<string> newStack;
        //iterate through dict
        for (list<string>::iterator i = dict.begin(); i != dict.end();) {
            if (offByOne(currWord, *i)) {
                //if that word is the end of the word ladder
                //output word ladder to file
                if (*i == end) {
                    s = q.front();
                    s.push(*i);
                    return true;
                }
                newStack = q.front();
                newStack.push(*i);
                i = dict.erase(i);
                q.push(newStack);
            }
            else {
                ++i;
            }
        }
        q.pop();
    }
    return false;
}

void WordLadder::output(stack<string> &s, ostream &sout) const {
	stack<string> newStack;
	while (!s.empty()) {
		newStack.push(s.top());
		s.pop();
	}
	if (!newStack.empty()) {
      sout << newStack.top();
      newStack.pop();
	}
	while (!newStack.empty()) {
		sout << " " << newStack.top();
		newStack.pop();
	}
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    ofstream outFS;
    outFS.open(outputFile);
    if (!outFS.is_open()) {
            cout << "Error opening " << outputFile << endl;
            return;
    }
    
     //if same word for start and end
    if (start == end) {
        
        outFS << start << endl;
        outFS.close();
        return;
    }
    
    bool startExist = false;
    bool endExist = false;

    //check to see if start and end words are in the dict
    for (list<string>::iterator i = dict.begin(); i != dict.end(); ++i) {
        if (start == *i) {
            startExist = true;
        }
        if (end == *i) {
            endExist = true;
        }
    }

    if (!startExist) {
        cout << "ERROR: The start word does not exist in the dictionary" << endl;
        return;
    }
    
    if (!endExist) {
        cout << "ERROR: The end word does not exist in the dictionary" << endl;
        return;
    }
    
    //create a stack
    stack<string> s;
    s.push(start);

    if(findLadder(s,end)){
        output(s,outFS);
    }
    else {
        outFS << "No Word Ladder Found." << endl;
    }
}
