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

    if (root == nullptr) {
        root = newNode;
        root->count += 1;
    }

    else if (searchTree(root, newString)) {
        Node* sameNode = searchForNode(root, newString);
        sameNode->count += 1;
        return;
    }

    else {
        while (curr != nullptr) {
            if (newNode->data < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    curr->left->count += 1;
                    curr = nullptr;
                }
                else {
                    curr = curr->left;
                }
            }
            else {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    curr->right->count += 1;
                    curr = nullptr;
                }
                else {
                    curr = curr->right;
                }
            }
        }
    }  
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

Node* BSTree::searchForNode(Node* curr, const string &key) const {
    if (curr == nullptr) {
        return nullptr;
    }
    
    else if (key == curr->data) {
        return curr;
    }
    
    else if (key < curr->data) {
        return searchForNode(curr->left, key);
    }
    
    else {
        return searchForNode(curr->right, key);
    }
}

string BSTree::largest() const {

}

string BSTree::smallest() const {

}

int BSTree::height(const string&) const {

}

void BSTree::preOrder() const {

}

void BSTree::postOrder() const {

}

void BSTree::inOrder() const {

}



