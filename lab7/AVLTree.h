#ifndef __AVLTREE_H
#define __AVLTREE_H

#include "Node.h"

class AVLTree {
public:
//Insert an item to the binary search tree and perform rotation if necessary.
void insert(const string &);

//Return the balance factor of a given node.
int balanceFactor(Node*);

//Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space.
void printBalanceFactors();

//Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.
void visualizeTree(const string &);

private:
//Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
Node* findUnbalancedNode(Node*);

//Implement four possible imbalance cases and update the parent of the given node.
void rotate();

//Rotate the subtree to left at the given node and returns the new subroot.
Node* rotateLeft(Node*);

//Rotate the subtree to right at the given node and returns the new subroot.
Node* rotateRight(Node*);

void printBalanceFactors(Node*);

void visualizeTree(ofstream &, Node *);

Node* root;

};


#endif