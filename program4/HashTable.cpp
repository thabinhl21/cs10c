#include "HashTable.h"
#include "Token.h"


/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of Token
*/
HashTable::HashTable () {
    vector<Token> hashTable;
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
// int HashTable::computeHash(const string &s) {
//     int stringHash = 0;

//     for (unsigned i = 0; i < s.length(); ++i) //iterate through characters in string
//     {
//         stringHash = stringHash  + s[i]; //for hash value, add string hash value to character value
//     }

//     if (stringHash < size) //make sure index is not out of bounds
//     {
//         return stringHash;
//     }
//     else
//     {
//         stringHash = stringHash % size;
//         while (stringHash > size)
//         {
//             stringHash = stringHash % size;
//         }
//         return stringHash;
//     }
// }


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the Token
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s) {
     if (!hashTable.empty()) //if table is not empty, check for string
     {
         for (unsigned int i = 0; i < hashTable.size(); ++i)
         {
             if (hashTable.at(i).getWord() == s)
             {
                 hashTable.at(i).addNewAppearance(); //add to numAppearances if string found
                 return;
             }
         }
     }
    Token newEntry (s); //if table not empty or string not found, add new entry to list
    hashTable.push_back(newEntry);
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the Token
*  Must first find the Token in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

// double HashTable::getAverage(const string &s) {
//     if (contains(s)) //check if table has string
//     {
//         for (unsigned int i = 0; i < hashTable.size(); ++i) //range for loop - go to index where string is located and iterate through list to find string
//              {
//                 if (hashTable.at(i).getWord() == s)
//                 {
//                      return entry.getAverage();
//                 }
//             }
//             return 2.0;
//      }
//      else
//      {
//          return 2.0;
//      }
// }

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
/* bool HashTable::contains(const string &s) {
   if (!hashTable.empty()) //check that table is not empty
   {
        for (unsigned int i = 0; i < hashTable.size(); ++i)
        {
            if (hashTable.at(i).getWord() == s)
            {
                return true;
            }
        }
        return false;
    }
} */

Token HashTable::access (int num)
{
    return hashTable.at(num);
}

const int HashTable::vecSize()
{
    return hashTable.size();
}
