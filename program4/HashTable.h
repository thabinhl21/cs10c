#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include "Token.h"

using namespace std;

class HashTable {

 private:
	vector<Token> hashTable;
	// int size;

 public:
	HashTable();
	//bool contains(const string &);
	//double getAverage(const string &);
	void put(const string &);
	Token access (int);
	const int vecSize();

 
 private:
	//int computeHash(const string &);
};

#endif


