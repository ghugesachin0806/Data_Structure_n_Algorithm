// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

#include <bits/stdc++.h>
using namespace std;

// A binary tree node structure

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
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int cnt1 = height(root->left);
        int cnt2 = height(root->right);

        return max(cnt1, cnt2) + 1;
    }

    bool check(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        bool b1 = check(root->left);
        bool b2 = check(root->right);

        if (b1 == false || b2 == false)
        {
            return false;
        }

        int cnt1 = height(root->left);
        int cnt2 = height(root->right);

        if (abs(cnt1 - cnt2) <= 1)
            return true;
        else
            return false;
    }

    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        bool t = check(root);
        return t;
    }
};

// Here due to height function call each time we get total time complexity ---> O(N2)
