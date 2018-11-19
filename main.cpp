/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
using namespace std; 
  
// Binary Tree node 
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
  
// function to print the zigzag traversal 
void zizagtraversal(struct Node* root) 
{ 
    
    if (!root) 
        return; 
    // declare two stacks 
    stack<struct Node*> currentlevel; 
    stack<struct Node*> nextlevel; 
  
    // push the root 
    currentlevel.push(root); 
  
    // check if stack is empty   
    bool lefttoright = true; 
    while (!currentlevel.empty()) { 
  
        // pop out of stack 
        struct Node* temp = currentlevel.top(); 
        currentlevel.pop(); 
  
        if (temp) { 
  
            cout << temp->data << " "; 
  
            // store data according to current 
            // order. 
            if (lefttoright) { 
                if (temp->left) 
                    nextlevel.push(temp->left); 
                if (temp->right) 
                    nextlevel.push(temp->right); 
            } 
            else { 
                if (temp->right) 
                    nextlevel.push(temp->right); 
                if (temp->left) 
                    nextlevel.push(temp->left); 
            } 
        } 
  
        if (currentlevel.empty()) { 
            lefttoright = !lefttoright; 
            swap(currentlevel, nextlevel); 
        } 
    } 
} 
  
// Adding a new node 
struct Node* newNode(int data) 
{ 
    struct Node* node = new struct Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
//Main Program
int main() 
{ 
    // create tree 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "ZigZag Order traversal of binary tree is \n"; 
  
    zizagtraversal(root); 
  
    return 0; 
}
