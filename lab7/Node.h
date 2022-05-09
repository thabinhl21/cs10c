#ifndef __NODE_H
#define __NODE_H

#include <iostream>

using namespace std;

class Node {
public:
int height;

string data;

Node* left;

Node* right;

Node* parent;

Node(string data): data(data), height(0), left(nullptr), right(nullptr), parent(nullptr) {}
};

#endif