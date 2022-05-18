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

int BSTree::height(const string&) const {

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

}

void BSTree::inOrder() const {

}



