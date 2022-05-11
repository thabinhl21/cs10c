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
    printBalanceFactors(root);
    cout << endl;
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
    Node* rightLeftChild = node->right->left;
    if (node->parent != nullptr)
    {
        ReplaceChild(node->parent, node, node->right);
    }
    else //tree is root
    {
        root = node->right;
        root->parent = nullptr;
    }
    SetChild(node->right, "left", node);
    SetChild(node, "right", rightLeftChild);

}

Node* AVLTree::rotateRight(Node* node)
{
    Node* leftRightChild = node->left->right;
    if (node->parent != nullptr)
    {
        ReplaceChild(node->parent, node, node->left);
    }
    else //tree is root
    {
        root = node->left;
        root->parent = nullptr;
    }
    SetChild(node->left, "right", node);
    SetChild(node, "left", leftRightChild);
}

void AVLTree::printBalanceFactors(Node* node)
{
    if (node != nullptr) {
        printBalanceFactors(node->left);
        cout << node->data << "(" << balanceFactor(node) << "), ";
        printBalanceFactors(node->right);
    }
}

void AVLTree::updateHeight(Node* node)
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
    node->height = max(leftHeight, rightHeight) + 1; //returns larger value + 1
}

void AVLTree::SetChild(Node* parent, string whichChild, Node* child)
{
    if (whichChild != "left" && whichChild != "right")
    {
        return;
    }
    if (whichChild == "left")
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }
    if (child != nullptr)
    {
        child->parent = parent;
    }
    updateHeight(parent);
}

void AVLTree::ReplaceChild(Node* parent, Node* currentChild, Node* newChild)
{
    if (parent->left == currentChild)
    {
        SetChild(parent, "left", newChild);
    }  
    else if (parent->right == currentChild)
    {
        SetChild(parent, "right", newChild);
    }
    else
    {
        return;
    }
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