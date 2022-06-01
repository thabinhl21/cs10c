#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Token {

 private:
	string word;
	int numAppearances;
	int code;
 public:
	Token(const string &);
	void addNewAppearance();
	const string & getWord();
	int getNumAppearances();
	void changeNumAppearances(int);
	void setCode(int num);
	int getCode();
	Token& operator=(const Token &rhs);
};
#endif
