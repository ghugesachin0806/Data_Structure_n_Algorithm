// using recursion

// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

// A binary tree node

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void recursive(Node *root, vector<int> &vect, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (vect.size() == level)
    {
        vect.push_back(root->data);
    }

    recursive(root->right, vect, level + 1);
    recursive(root->left, vect, level + 1);
}
// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> vect;
    int level = 0;

    recursive(root, vect, level);

    return vect;
}