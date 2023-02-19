// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *solve(Node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == n1 || root->data == n2)
        {
            return root;
        }

        Node *temp1 = solve(root->left, n1, n2);
        Node *temp2 = solve(root->right, n1, n2);

        if (temp1 == NULL && temp2 == NULL)
        {
            return NULL;
        }
        else if (temp1 != NULL && temp2 != NULL)
        {
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

    Node *lca(Node *root, int n1, int n2)
    {
        Node *temp = NULL;
        temp = solve(root, n1, n2);

        return temp;
    }
};