//https://www.geeksforgeeks.org/expression-tree/
//https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
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
    stack<TreeNode> tree;
    infixExpression = infix_to_postfix(); //converts infix to postfix
    char key = 'a';
    bool rootCheck = true;
    
    TreeNode* current(nullptr), *top1(nullptr), *top2(nullptr);

    for (unsigned i = 0; i < infixExpression.size(); ++i) //loop through postfix
    {
        current = new TreeNode(infixExpression.at(i), key);
        
        if (priority(infixExpression.at(i)) > 0)
        {
            top1 = &tree.top();
            tree.pop();
            top2 = &tree.top();
            tree.pop();
            current->left = top2;
            current->right = top1;
            if (rootCheck)
            {
                root = current;
            }
            rootCheck = false;
        }

        tree.push(*current);

        ++key; //increment key
    }
}

void arithmeticExpression::infix()
{
    infix(root);
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

void arithmeticExpression::infix(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    else
    {
        cout << "(";
        infix(node->left);
        cout << node->data;
        infix(node->right);
        //if (Node->right != nullptr)
        //{
          //  cout << ")";
        //}
    }
}

void arithmeticExpression::prefix(TreeNode *Node)
{
    return;
}

void arithmeticExpression::postfix(TreeNode *Node)
{
    return;
}

void arithmeticExpression::visualizeTree(ofstream &file, TreeNode *root)
{
    return;
}