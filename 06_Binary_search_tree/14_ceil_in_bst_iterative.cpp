// https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int solve(Node *root, int input)
{
    int temp = -1;

    while (root)
    {
        if (root->data == input)
        {
            return root->data;
        }

        if (input > root->data)
        {
            root = root->right;
        }

        else
        {
            temp = root->data;
            root = root->left;
        }
    }

    return temp;
}
// Function to return the ceil of given number in BST.
int findCeil(Node *root, int input)
{
    // Your code here
    return solve(root, input);
}