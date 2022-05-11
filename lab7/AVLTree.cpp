#include "AVLTREE.h"
#include <fstream>
#include <string>

AVLTree::AVLTree()
{
    root = nullptr;
}

void AVLTree::insert(const string &item)
{
    Node* newNode = new Node(item);

    if (root == nullptr)
    {
        root = newNode; //set root to newly inserted node if tree is empty
        return;
    }

    Node* cur = root;
    while (cur != nullptr)
    {
        if (newNode->data < cur->data)
        {
            if (cur->left == nullptr)
            {
                cur->left = newNode;
                newNode->parent = cur;
                cur = nullptr;
            }
        }
        else
        {
            if (cur->right == nullptr)
            {
                cur->right = newNode;
                newNode->parent = cur;
                cur = nullptr;
            }
            else
            {
                cur = cur->right;
            }
        }
        newNode = newNode->parent;

        while (newNode != nullptr)
        {
            // FIXME:rebalance(newNode);
            newNode = newNode->parent;
        }
    }
}

int AVLTree::balanceFactor(Node* node)
{
    int leftHeight = -1;
    if (node->left != nullptr)
    {
        leftHeight = node->left->height;
    }
    
    int rightHeight = -1;
    if (node->right != nullptr)
    {
        rightHeight = node->right->height;
    }
    return leftHeight - rightHeight; //subtract right subtree height from left subtree height to get node's balance factor
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


Node* AVLTree::findUnbalancedNode(Node* node)
{

}

void AVLTree::rotate()
{

}

Node* AVLTree::rotateLeft(Node* node)
{

}

Node* AVLTree::rotateRight(Node* node)
{
    Node* leftRightChild = node->left->right;
    if (node->parent != nullptr)
    {
        //replace child node
        if (node->parent->left == node)
        {
            //set child
        }
        else if (node->parent->right == node)
        {
            //set child
        }
        else
        {
            return;
        }
    }
    else //tree is root
    {
        root = node->left;
        root->parent = nullptr;
    }
        //set child node
        //set child node
}

void AVLTree::printBalanceFactors(Node*)
{

}

void AVLTree::updateHeight(Node*)
{

}

void AVLTree::SetChild(Node*, Node*, Node*)
{

}

void AVLTree::ReplaceChild(Node*, Node*, Node*)
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