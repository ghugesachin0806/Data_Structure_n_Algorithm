// https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


void solve(Node * root,int k ,int & temp)
{
    if(root==NULL)
    return ;

    if(k>root->data)
    {
        solve(root->right,k,temp);
    }

    else
    {
        temp = root->data;
        solve(root->left,k,temp);
    }
}

// Function to return the ceil of given number in BST.
int findCeil(Node *root, int input)
{
    // Your code here
    int temp=-1;

    solve(root,input,temp);

    return temp;

}