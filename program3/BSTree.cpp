#include "BSTree.h"

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    delete root;
}

void BSTree:insert(const string &newString) {

}

void BSTree::remove(const string &key) {

}

bool BSTree::search(const string &key) const {
    Node* curr = root;
    bool found = false;

    while (curr != nullptr) {
        if (key == curr->data) {
            found = true;
        }
        else if (key < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }

    return found;
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



