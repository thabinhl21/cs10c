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
	int totalScore;
 public:
	Token(const string &, int);
	void addNewAppearance(int);
	const string & getWord();
	double getAverage();
};
#endif
