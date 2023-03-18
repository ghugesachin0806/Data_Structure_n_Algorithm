// https://practice.geeksforgeeks.org/problems/floor-in-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

void solve(Node *root, int x, int &temp)
{
    if (root == NULL)
        return;

    if (x >= root->data)
    {
        temp = root->data;
        root = root->right;
        solve(root, x, temp);
    }
    else
    {
        root = root->left;
        solve(root, x, temp);
    }
}

int floor(Node *root, int x)
{
    // Code here
    int temp = -1;

    solve(root, x, temp);

    return temp;
}