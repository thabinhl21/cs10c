#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <string>

class Node {
public:
int height;

string data;

Node* left;

Node* right;

Node(string data): data(data), height(0), left(nullptr), right(nullptr) {}
};

#endif