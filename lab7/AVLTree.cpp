#include "AVLTREE.h"
#include <iostream>
#include <fstream>
#include <string>

void AVLTree::insert(const string &item)
{

}

int AVLTree::balanceFactor(Node* node)
{
    
}

void AVLTree::printBalanceFactors()
{

}

void AVLTree::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS, root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}


Node* AVLTree::findUnbalancedNode()
{

}

void AVLTree::rotate()
{

}

Node* AVLTree::rotateLeft()
{

}

Node* AVLTree::rotateRight()
{

}

void AVLTree::printBalanceFactors(Node*)
{

}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}