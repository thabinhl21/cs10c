// https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
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

bool BSTree::search(const string &key) const {
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
    Node* curr = root;

    if (root == nullptr) {
        return "";
    }

    while (curr->right != nullptr) {
        curr = curr->right;
    }

    return curr->data;
}

string BSTree::smallest() const {
    Node* curr = root;

    if (root == nullptr)
    {
        return "";
    }

    while (curr->left != nullptr)
    {
        curr = curr->left;
    }

    return curr->data;
}

int BSTree::height(const string& key) const {
    
    if (root == nullptr) {
        return -1;
    }
    
    return findDepth(searchForNode(root, key));
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

void BSTree::remove(const string &key) {
	removeNode(root, key);
}

//currently not working for removing internal nodes
Node* BSTree::removeNode(Node* curr, const string &key) const {
   
    if (curr == nullptr) {
        return curr;
    }

    if (key < curr->data) {
        curr->left = removeNode(curr->left, key);
    }

    else if (key > curr->data) {
        curr->right = removeNode(curr->right, key);
    }

    else {
        if (curr->count > 1) {
            curr->count -= 1;
        }

        //leaf node
        else if (curr->left == nullptr && curr->right == nullptr) {
        
            //cout << "testing1" << endl;
            curr = nullptr;
            return curr;
            //cout << "testing2" << endl;
        }
        //remove node with only right child
        else if (curr->left == nullptr) {
            //cout << "testing3" << endl;
            //Node* temp = searchForNode(curr->right, smallest()); smallest value in the right subtree of the node to remove
            Node* temp = findMinNode(curr->right);
            curr->data = temp->data;
            curr->count = temp->count;
            temp->count = 0;

            //cout << "testing4" << endl;
            curr->right = removeNode(curr->right, temp->data);
            return curr;
        }

        //remove node with only left child
        else if (curr->right == nullptr) {
            //cout << "testing5" << endl;
            //Node* temp = searchForNode(curr->left, largest()); // largest value in the left subtree of the node to remove
            Node* temp = findMaxNode(curr->left);
            curr->data = temp->data;
            curr->count = temp->count;
            temp->count = 0;

            //cout << "testing6" << endl;
            curr->left = removeNode(curr->left, temp->data);
            return curr;
        }

        //node with 2 children
        else {
            //cout << "testing7" << endl;
            //Node* temp = searchForNode(curr->left, largest());
            Node* temp = findMaxNode(curr->left);
            curr->data = temp->data;
            curr->count = temp->count;
            temp->count = 0;
            //cout << "testing8" << endl;
            curr->left = removeNode(curr->left, temp->data);
            //cout << "testing9" << endl;
        }
    
        
    }
    //cout << "testing10" << endl;
    return curr;
}

Node* BSTree::findMinNode(Node* curr) const {

    if (root == nullptr)
    {
        return nullptr;
    }

    while (curr->left != nullptr)
    {
        curr = curr->left;
    }

    return curr;
}

Node* BSTree::findMaxNode(Node* curr) const {

    if (root == nullptr) {
        return nullptr;
    }

    while (curr->right != nullptr) {
        curr = curr->right;
    }

    return curr;
}




