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
    // Function to check whether a binary tree is balanced or not.
    pair<int, bool> check(Node *root)
    {
        if (root == NULL)
        {
            pair<int, bool> p = make_pair(0, true);
            return p;
        }

        pair<int, bool> p1 = check(root->left);
        pair<int, bool> p2 = check(root->right);

        pair<int, bool> curr = make_pair(0, false);

        if (!p1.second || !p2.second)
        {
            return curr;
        }

        if (abs(p1.first - p2.first) <= 1)
        {
            pair<int, bool> temp = make_pair(max(p1.first, p2.first) + 1, true);
            return temp;
        }
        else
            return curr;
    }

    bool isBalanced(Node *root)
    {
        pair<int,bool> temp = check(root);

        return temp.second;
        //  Your Code here
    }
};