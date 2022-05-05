// https://www.geeksforgeeks.org/expression-tree/
// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
// https://nirav.com.np/2019/12/08/visualize-c-data-structures-using-graphviz-and-dot-language.html
#include "arithmeticExpression.h"
#include <stack>
#include <fstream>
#include <sstream>

arithmeticExpression::arithmeticExpression(const string &expr)
{
    infixExpression = expr;
    root = nullptr;
}

void arithmeticExpression::buildTree()
{
    stack<TreeNode*> tree; //needs to be stack of tree node POINTERS
    infixExpression = infix_to_postfix(); //converts infix to postfix ex. abc*+
    char key = 'a';

    TreeNode* current(nullptr), *top1(nullptr), *top2(nullptr);

    for (unsigned i = 0; i < infixExpression.size(); ++i) //loop through postfix
    {
        current = new TreeNode(infixExpression.at(i), key);
        
        if (priority(infixExpression.at(i)) > 0) //operators are always parent nodes
        {
            //pop top two operands and set them as children of operator
            top1 = tree.top();
            tree.pop();
            current->right = top1;
            
            top2 = tree.top();
            tree.pop();
            current->left = top2;

            tree.push(current);

            root = current; //root is last element of stack
        }
        else
        {
            tree.push(current);
        }

        ++key; //increment key
    }
}

void arithmeticExpression::infix()
{
    cout << "(";
    infix(root);
    cout << ")";
}

void arithmeticExpression::prefix()
{
    prefix(root);
}

void arithmeticExpression::postfix()
{
    postfix(root);
}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::infix(TreeNode *node)
{
    // if (node == nullptr)
    // {
    //     return;
    // }
    // else
    // {
    //     if (node->left != nullptr && (priority(node->data) > priority(node->left->data))) {
    //         cout << "(";
    //     }
    //     infix(node->left);
    //     cout << node->data;
    //     infix(node->right);
    //     if (node->right != nullptr && (priority(node->data) > priority(node->right->data))) {
    //         cout << ")";
    //     }
    // }


    // if (node) {
    //     cout << "(";
    //     infix(node->left);
    //     cout << node->data;
    //     infix(node->right);
    //     cout << ")";
    // }

    if (node != nullptr)
    {
        if (node->left != nullptr)
        {
            cout << '(';
        }

        infix(node->left);
        cout << node->data;
        infix(node->right);

        if (node->right != nullptr)
        {
            cout << ')';
        }
    }

}

void arithmeticExpression::prefix(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    else
    {
        cout << node->data;
        prefix(node->left);
        prefix(node->right);
    }
}

void arithmeticExpression::postfix(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    else
    {
        postfix(node->left);
        postfix(node->right);
        cout << node->data;
    }
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void arithmeticExpression::visualizeTree(ofstream &out, TreeNode *node)
{
    if (node != nullptr) {
        if (node->left != nullptr) {
            // visualizes parent node in light blue
            out << node->key << "[color = lightblue, style = filled, label= " << "\"" << node->data << "\"" << "];" << endl;
            //visualizes left child of parent node in light blue
            out << node->left->key << "[color = lightblue, style = filled, label= " << "\"" << node->left->data << "\"" << "];" << endl; 
            out << node->key << "->" << node->left->key << endl; // visualizes edge
            visualizeTree(out, node->left);
        }
        if (node->right != nullptr) {
            out << node->key << "[color = lightblue, style = filled, label= " << "\"" << node->data << "\"" << "];" << endl;
            out << node->right->key << "[color = lightblue, style = filled, label= " << "\"" << node->right->data << "\"" << "];" << endl;
            out << node->key << "->" << node->right->key << endl; // visualizes edge
            visualizeTree(out, node->right);
        }
    }
}