// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

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

class Solution
{
public:
    bool check(Node *r1, Node *r2)
    {
        if (r1 == NULL && r2 == NULL)
        {
            return true;
        }

        if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
        {
            return false;
        }

        bool b1 = check(r1->left, r2->left);
        bool b2 = check(r1->right, r2->right);

        if (b1 && b2 && (r1->data == r2->data))
        {
            return true;
        }
        else
            return false;
    }
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Your Code here

        bool b = check(r1, r2);

        return b;
    }
};

 // Time complexity ---> O(N)