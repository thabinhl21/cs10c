#include "HashTable.h"
#include "Token.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of Token
*/
HashTable::HashTable (int s) {
	size = s;
    hashTable = new list <Token> [size];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
    int stringHash = 0;

    for (unsigned i = 0; i < s.length(); ++i) //iterate through characters in string
    {
        stringHash = stringHash  + s[i]; //for hash value, add string hash value to character value
    }

    if (stringHash < size) //make sure index is not out of bounds
    {
        return stringHash;
    }
    else
    {
        stringHash = stringHash % size;
        while (stringHash > size)
        {
            stringHash = stringHash % size;
        }
        return stringHash;
    }
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the Token
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
	 if (contains(s)) //check if string is already in table
     {
         for (Token & entry : hashTable[computeHash(s)]) //range for loop of list at index where string is located - using compute hash to find index where string is
         {
             if (entry.getWord() == s)
             {
                 entry.addNewAppearance(score);
                 return;
             }
         }
         return;
     }
     else
     {
         Token newEntry (s, score);
         hashTable[computeHash(s)].push_back(newEntry); //push new entry at list based on index found by hash function of string
     }
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the Token
*  Must first find the Token in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
    if (contains(s)) //check if table has string
    {
        for (Token & entry : hashTable[computeHash(s)]) //range for loop - go to index where string is located and iterate through list to find string
             {
                if (entry.getWord() == s)
                {
                     return entry.getAverage();
                }
            }
            return 2.0;
     }
     else
     {
         return 2.0;
     }
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
   if (!hashTable[computeHash(s)].empty()) //check that table is not empty
   {
        for (Token & entry : hashTable[computeHash(s)]) //range for loop at list at index from hash value
        {
            if (entry.getWord() == s)
            {
                return true;
            }
        }
        return false;
    }

    else
   {
       return false;
   }
}