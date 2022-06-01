//g++ Token.cpp HashTable.cpp main.cpp -Wall -Werror -o a.out 
#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"
#include "Token.h"
#include <algorithm>
#include <cctype>
using namespace std;

void InsertionSort(vector <Token> &table) {
    int i = 0;
    int j = 0;
    Token temp("dummy");

    for (i = 1; i < table.size(); ++i)
    {
        temp = table.at(i);
        j = i - 1;
        while (j >= 0 && table.at(j).getNumAppearances() > temp.getNumAppearances())
        {
            table.at(j+1) = table.at(j);
            --j;
        }
        table.at(j+1) = temp;
    }
}

void put(vector <Token> &table, const string &s) {
     if (!table.empty()) //if table is not empty, check for string
     {
         for (unsigned int i = 0; i < table.size(); ++i)
         {
             if (table.at(i).getWord() == s)
             {
                 table.at(i).addNewAppearance(); //add to numAppearances if string found
                 return;
             }
         }
        Token newEntry (s); //if table not empty or string not found, add new entry to list
        table.push_back(newEntry);
     }
     else
     {
        Token newEntry (s); //if table not empty or string not found, add new entry to list
        table.push_back(newEntry);
     }
}


int Encode(vector <Token> table, string s) {
    for (unsigned i = 0; i < table.size(); ++i)
    {
        if (table.at(i).getWord() == s)
        {
            //cout << table.access(i).getWord();
            //cout << table.access(i).getCode();
            return table.at(i).getCode();
        }
    }
    return -1;
}

string Decode(vector <Token> table, int num)
{
    return table.at(num).getWord();
}

int main() {    
    // get input from file
    string filename;
    ifstream inFS;
    string word;
    vector <Token> table;
    ofstream outFS;
    string line = "empty";

    cout << "Enter the name of the your file: " << endl;
    cin >> filename;

    inFS.open(filename);

    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    /* while (inFS >> word) {
    //store words in hash table (vector) as WordEntry objects (HashTable::put - do not need to compute hash!)
        put(table, word);
    } */

    	while (!inFS.eof()) {
	    getline(inFS, line);
	    int len = line.size();

	    while(len > 0) {     // identify all individual strings
	        string sub;
            string punct;
	        len = line.find(" "); //returns index of space

            cout << "len = " << len << endl;
            cout << "line = " << line << endl;
            
	        if (len > 0) {
	            sub = line.substr(0, len); //0 to len characters
                for (int i = 0; i < sub.size(); ++i)
                {
                    if (ispunct(sub.at(i)))
                    {
                        punct = sub.at(i);
                        cout << "sub before " << sub << endl;
                        sub.erase(i, 1);
                        cout << "sub after: " << sub << endl;
                        --len;
                        put (table, punct);
                    }
                }
                cout << "length " << len << endl;
                cout << endl;
	            line = line.substr(len + 1, line.size());
                put(table, sub); // insert string
	        }

	        else {
                if (isspace(line.at(0)))
                {
                    line.erase(0, 1);
                }
	        }
	    }
	}

    inFS.close();

    InsertionSort(table);

    reverse(table.begin(), table.end());

    for (unsigned i = 0; i < table.size(); ++i)
    {
        cout << table.at(i).getWord() << " " << table.at(i).getNumAppearances();
        cout << endl;
    }

    for (unsigned i = 0; i < table.size(); ++i)
    {
        table.at(i).setCode(i);
    }

    inFS.open(filename);

    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    outFS.open("encoded.txt");

     while (inFS >> word) {
        
        outFS << Encode(table, word) << " ";
    }

    outFS.close();

    inFS.close();

    outFS.open("decoder.txt");

    for (unsigned i = 0; i < table.size(); ++i)
    {
        outFS << table.at(i).getCode() << '\t' << table.at(i).getWord();
        outFS << endl;
    }

    outFS.close();



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