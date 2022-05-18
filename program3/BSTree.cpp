#include "BSTree.h"

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    delete root;
}

void BSTree::insert(const string &newString) {
    Node* newNode = new Node(newString);
    Node* curr = root;
    Node* parent = nullptr;


}

void BSTree::remove(const string &key) {

}

bool BSTree::search(const string &key) const {
    // Node* curr = root;
    // bool found = false;

    // while (curr != nullptr) {
    //     if (key == curr->data) {
    //         found = true;
    //     }
    //     else if (key < curr->data) {
    //         curr = curr->left;
    //     }
    //     else {
    //         curr = curr->right;
    //     }
    // }

    // return found;
    Node* curr = root;
    return searchTree(curr, key);
}

bool BSTree::searchTree(Node* curr, const string &key) const {

    if (curr == nullptr) {
        return false;
    }
    
    else if (key == curr->data) {
        return true;
    }
    
    else if (key < curr->data) {
        return searchTree(curr->left, key);
    }
    
    else {
        return searchTree(curr->right, key);
    }
}

string BSTree::largest() const {

}

string BSTree::smallest() const {

}

int BSTree::height(const string& key) const {
    Node* curr = root;
    int height = -1;
    int depth = findDepth(root);
    
    if (curr == nullptr) {
        return -1;
    }
    
    else if (key == curr->data) {
        return depth;
    }
    
    else if (key < curr->data) {
        return searchTree(curr->left, key);
    }
    
    else {
        return searchTree(curr->right, key);
    }
}

int BSTree::findDepth(Node* node) const
{
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        int lDepth = findDepth(node->left);
        int rDepth = findDepth(node->right);
        if (lDepth > rDepth)
        {
            return (lDepth + 1);
        }
        else
        {
            return (rDepth + 1);
        }
    }
}

void BSTree::preOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << "(" << node->count << "), ";
    preOrder(node->left);
    preOrder(node->right);

}

void BSTree::postOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << "(" << node->count << "), ";
}

void BSTree::inOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }
    inOrder(node->left);
    cout << node->data << "(" << node->count << "), ";
    inOrder(node->right);
}

void BSTree::preOrder() const {
    preOrder(root);
}

void BSTree::postOrder() const {
    postOrder(root);
}

void BSTree::inOrder() const {
    inOrder(root);
}



