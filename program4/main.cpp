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
            
            len = line.find(" "); //returns index of space

            if (len < 0 && line.size() > 0) //check if there is word/punctuation left but no more spaces
            {
                len = line.size(); //if so, set len to size of line
            }

            cout << "len = " << len << endl;
        
            if (len > 0)
            {
                sub = line.substr(0, len); //0 to len characters
                cout << "sub = " << sub << endl;
                for (int i = 0; i < len; ++i)
                {
                    if (ispunct(sub.at(i)))
                    {
                        punct = sub.at(i);
                        cout << "punct " << sub.at(i) << endl;
                        sub.erase(i, 1);
                        --len;
                        put (table, punct);
                        cout << "i " << i << endl;
                    }
                }
                
                while (isspace(line.at(0)) && (!line.empty())) //get rid of any leading white spaces
                {
                    line.erase(0, 1);
                }

                if (sub.size() > 0) //check if sub is greater than 0 - can be 0 if punctuation was only char in sub (was deleted)
                {
                    put(table, sub); // insert string
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
            
            else
            {
                while (isspace(line.at(0)) && (!line.empty()))
                {
                    line.erase(0, 1);

                    if (line.empty()) //if erasing makes line empty, set len to -1 so larger while loop ends and break from this loop
                    {
                        len = -1;
                        break;
                    }
                }
                len = line.size(); //again -- essential!!
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

 /*    for (unsigned i = 0; i < table.size(); ++i)
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
            
            len = line.find(" "); //returns index of space

            if (len < 0 && line.size() > 0) //check if there is word/punctuation left but no more spaces
            {
                len = line.size(); //if so, set len to size of line
            }
        
            if (len > 0)
            {
                sub = line.substr(0, len); //0 to len characters
                for (int i = 0; i < sub.size(); ++i)
                {
                    if (ispunct(sub.at(i)))
                    {
                        punct = sub.at(i);
                        sub.erase(i, 1);
                        --len;
                        outFS << Encode(table, punct) << " ";
                    }
                }
                
                while (isspace(line.at(0)) && (!line.empty())) //get rid of any leading white spaces
                {
                    line.erase(0, 1);
                }

                if (sub.size() > 0) //check if sub is greater than 0 - can be 0 if punctuation was only char in sub (was deleted)
                {
                    outFS << Encode(table, sub) << " ";// insert string
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
            
            else
            {
                while (isspace(line.at(0)) && (!line.empty()))
                {
                    line.erase(0, 1);

                    if (line.empty()) //if erasing makes line empty, set len to -1 so larger while loop ends and break from this loop
                    {
                        len = -1;
                        break;
                    }
                }
                len = line.size(); //again -- essential!!
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