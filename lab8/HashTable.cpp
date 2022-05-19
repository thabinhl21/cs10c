#include "HashTable.h"
#include "WordEntry.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
	size = s;
    hashTable = new list <WordEntry> [size];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
    int stringHash = 0;

    for (unsigned i = 0; i < s.length(); ++i)
    {
        stringHash = (stringHash * 1) + s[i];
        cout << stringHash << endl;
    }

    if ((stringHash % size) < size)
    {
        return stringHash % size;
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
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
	 if (contains(s))
     {
         for (WordEntry & entry : hashTable[computeHash(s)])
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
         WordEntry newEntry (s, score);
         hashTable[computeHash(s)].push_back(newEntry);
         cout << hashTable[computeHash(s)].front().getWord() << endl;
     }
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
    if (contains(s))
    {
        for (WordEntry & entry : hashTable[computeHash(s)])
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
   if (!hashTable[computeHash(s)].empty())
   {
        for (WordEntry & entry : hashTable[computeHash(s)])
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