#include "Token.h"

/* Token contructor
* input: the string text (word) and the intial score the
*         word should be assigned to
*  note that numAppearances should be set to 1 here
*/

Token::Token(const string &text)
 : word(text), numAppearances(1), code(0) {
	 
}

/* addNewAppearance
* input integer that is a new score for a word that is
* already in the hash table
* function should increase total score by s
* also should increase numAppearances
*/
void Token::addNewAppearance() {
	++numAppearances;
}

/*getWord
* this accessor function is needed
* particularly in the HashTable code to get the word to be
* used for the hash value
* simple accessor function  
*/
const string & Token::getWord() {
    return word;
}

/* getAverage
*  returns the average score of the word
*  based on totalScore and numAppearances
*  note that typecasting -- turning one of the integers
*  to a double will be necessary to avoid integer division
*/
int Token::getNumAppearances() {
	return numAppearances;
}

void Token::changeNumAppearances(int num)
{
	numAppearances = num;
}

void Token::setCode(int num)
{
	code = num;
}

int Token::getCode()
{
	return code;
}

Token& Token::operator=(const Token &rhs)
{
	word = rhs.word;
	numAppearances = rhs.numAppearances;
	code = rhs.code;
	return *this;
}