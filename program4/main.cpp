//g++ Token.cpp main.cpp -Wall -Werror -o a.out
#include <iostream>
#include <string>
#include <fstream>
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

            if (len < 0 && line.size() > 0) //check if there is word/punctuation left but no more spaces
            {
                len = line.size(); //if so, set len to size of line
            }
        
            if (len > 0)
            {
                unsigned start = 0;
                sub = line.substr(0, len); //store first word in sub (up to whitespace)

                if (ispunct(sub.at(0))) //if there is punctuation first, store that, then start at 1 rather than 0
                {
                    punct = sub.at(0);
                    put (table, punct);
                    start = 1;
                }

                unsigned i = start;
                unsigned end = start;

                for ( ; i < sub.size(); ++i) //don't need to intialize i
                //iterate through sub, if there is punctuation, output whatever is before it, then output the punctuation
                {
                    if (ispunct(sub.at(i)))
                    {
                        if (start < i)
                        {
                            put(table, sub.substr(start, end - start)); //output everything before punctuation
                        }
                        put(table, sub.substr(i, 1)); //put in punctuation after that
                        start = i + 1; //move start to position after punctuation
                        ++end; //increment end
                    }
                    else
                    {
                        ++end; //increment end if punctuation not found
                    }
                }

                if (start < sub.size()) //if start < size of sub, then punctuation was not at end and need to output remaining word
                {

                    put(table, sub.substr(start, sub.size()));
                }
                
                if (len + 1 < line.size()) //check if there are more characters in string past sub
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

    inFS.close();

    InsertionSort(table);

    reverse(table.begin(), table.end());

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

    while (!inFS.eof())
    {
        getline(inFS, line);
        int len = line.size();

        while(len > 0)
        {
            string sub;
            string punct;

            while (isspace(line.at(0)) && (!line.empty()))
            {
                line.erase(0, 1);

                if (line.empty())
                {
                    break;
                }
            }
            
            len = line.find(" ");

            if (len < 0 && line.size() > 0)
            {
                len = line.size();
            }
        
            if (len > 0)
            {
                unsigned start = 0;
                sub = line.substr(0, len);

                if (ispunct(sub.at(0)))
                {
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
                            outFS << Encode (table, sub.substr(start, end - start)) << " ";
                        }
                        outFS << Encode (table, sub.substr(i, 1)) << " ";
                        start = i + 1;
                        ++end;
                    }
                    else
                    {
                        ++end;
                    }
                }

                if (start < sub.size())
                {
                    outFS << Encode (table, sub.substr(start, sub.size())) << " ";
                }
                
                if (len + 1 < line.size())
                {
                    line = line.substr(len + 1, line.size());
                    len = line.size();
                }
                else
                {
                    len = 0;
                }
            }
        }
        outFS << endl;
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