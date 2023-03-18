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
    while (root)
    {
        if (root->data == x)
        {
            temp = x;
            return;
        }

        if (x > root->data)
        {
            temp = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}

int floor(Node *root, int x)
{
    // Code here
    int temp = -1;

    solve(root, x, temp);

    return temp;
}