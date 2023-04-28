
// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

// Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};

// your task is to complete this function
Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
    {
        return root;
    }

    Node *temp1 = solve(root->left, k, node);
    Node *temp2 = solve(root->right, k, node);

    if (k > 0 && (temp1 != NULL || temp2 != NULL))
    {
        k--;
        return root;
    }
    else
    {
        if (temp1)
            return temp1;
        else
            return temp2;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *temp = NULL;
    temp = solve(root, k, node);

    if (temp && k==0)
        return temp->data;
    else
        return -1;
}

int main()
{
    return 0;
}