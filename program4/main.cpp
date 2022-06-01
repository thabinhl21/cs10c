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
    string filename = "example.txt"; //TODO: remove hardcoded filename
    ifstream inFS;
    string word;
    vector <Token> table;
    ofstream outFS;
    string line = "empty";

    cout << "Enter the name of the your file: " << endl;
    //cin >> filename; //TODO: remove hardcoded filename

    inFS.open(filename);

    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    /* while (inFS >> word) {
    //store words in hash table (vector) as WordEntry objects (HashTable::put - do not need to compute hash!)
        put(table, word);
    } */

    while (!inFS.eof())
    {
        getline(inFS, line);
        int len = line.size();

        while(len > 0)
        {
            string sub;
            string punct;

            while (isspace(line.at(0)) && (!line.empty())) //get rid of leading white spaces
            {
                line.erase(0, 1);

                if (line.empty()) //if erasing makes line empty, break from loop
                {
                    break;
                }
            }
            
            len = line.find(" "); //returns index of space
            //cout << "len: " << len << endl;

            if (len < 0 && line.size() > 0) //check if there is word/punctuation left but no more spaces
            {
                len = line.size(); //if so, set len to size of line
            }

            //cout << "len = " << len << endl;
        
            if (len > 0)
            {
                unsigned start = 0;
                sub = line.substr(0, len); //0 to len characters
                //cout << "sub = " << sub << endl;

                if (ispunct(sub.at(0)))
                {
                    //cout << "d: " << sub.at(0) << endl;
                    punct = sub.at(0);
                    put (table, punct);
                    start = 1;
                }

                unsigned i = start;
                unsigned end = start;

                for ( ; i < sub.size(); ++i)
                {
                    if (ispunct(sub.at(i)))
                    {
                        if (start < i)
                        {
                            //cout << "a: " << sub.substr(start, end - start) << endl;
                            put(table, sub.substr(start, end - start));
                        }
                        //cout << "b: " << sub.substr(i, 1) << endl;
                        put(table, sub.substr(i, 1));
                        start = i + 1;
                        ++end;
                    }
                    else
                    {
                        ++end;
                    }
                }

                if (start < sub.size()) //punctuation not at end
                {
                    if (sub.size() == 1)
                    {
                        put(table, sub.substr(start, 1));
                    }
                    else
                    {
                        put(table, sub.substr(start, sub.size()));
                    }
                }
                
                if (len + 1 < line.size())
                {
                    line = line.substr(len + 1, line.size()); //now line is set to everything past what was just put into table
                    len = line.size(); //not quite sure why this goes here, but it is essential!!
                }
                else //if len + 1 is larger than size of line, done reading all words
                {
                    len = 0;
                }
            }
        }
    }

	 /*        else
            {
                if (!line.empty())
                {
                    while (isspace(line.at(0)) && (!line.empty()))
                {
                    cout << "erase start" << endl;
                    line.erase(0, 1);
                    if (line.empty())
                    {
                        break;
                    }
                    cout << "erase end" << endl;
                } */
            //}

    inFS.close();

    InsertionSort(table);

    reverse(table.begin(), table.end());

  /*  for (unsigned i = 0; i < table.size(); ++i)
    {
        cout << table.at(i).getWord() << " " << table.at(i).getNumAppearances();
        cout << endl;
    } */

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

    /* while (inFS >> word) {
        outFS << Encode(table, word) << " ";
    } */

    while (!inFS.eof())
    {
        getline(inFS, line);
        int len = line.size();

        while(len > 0)
        {
            string sub;
            string punct;

            while (isspace(line.at(0)) && (!line.empty())) //get rid of leading white spaces
            {
                line.erase(0, 1);

                if (line.empty()) //if erasing makes line empty, break from loop
                {
                    break;
                }
            }
            
            len = line.find(" "); //returns index of space
            //cout << "len: " << len << endl;

            if (len < 0 && line.size() > 0) //check if there is word/punctuation left but no more spaces
            {
                len = line.size(); //if so, set len to size of line
            }

            //cout << "len = " << len << endl;
        
            if (len > 0)
            {
                unsigned start = 0;
                sub = line.substr(0, len); //0 to len characters
                //cout << "sub = " << sub << endl;

                if (ispunct(sub.at(0)))
                {
                    //cout << "d: " << sub.at(0) << endl;
                    punct = sub.at(0);
                    outFS << Encode (table, punct) << " ";
                    start = 1;
                }

                unsigned i = start;
                unsigned end = start;

                for ( ; i < sub.size(); ++i)
                {
                    if (ispunct(sub.at(i)))
                    {
                        if (start < i)
                        {
                            //cout << "a: " << sub.substr(start, end - start) << endl;
                            outFS << Encode (table, sub.substr(start, end - start)) << " ";
                        }
                        //cout << "b: " << sub.substr(i, 1) << endl;
                        outFS << Encode (table, sub.substr(i, 1)) << " ";
                        start = i + 1;
                        ++end;
                    }
                    else
                    {
                        ++end;
                    }
                }

                if (start < sub.size()) //punctuation not at end
                {
                    if (sub.size() == 1)
                    {
                        outFS << Encode (table, sub.substr(start, 1)) << " ";
                    }
                    else
                    {
                        outFS << Encode (table, sub.substr(start, sub.size())) << " ";
                    }
                }
                
                if (len + 1 < line.size())
                {
                    line = line.substr(len + 1, line.size()); //now line is set to everything past what was just put into table
                    len = line.size(); //not quite sure why this goes here, but it is essential!!
                }
                else //if len + 1 is larger than size of line, done reading all words
                {
                    len = 0;
                }
            }
        }
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
    
    return 0;
}