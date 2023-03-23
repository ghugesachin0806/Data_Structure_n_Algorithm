// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // for checking max element and their childs
    bool solve(struct Node *root)
    {
        if (root == NULL)
            return true;

        bool b1 = solve(root->left);
        bool b2 = solve(root->right);
        bool b3 = true;

        if (root->left && root->data < root->left->data && b3)
            b3 = false;

        if (root->right && root->data < root->right->data && b3)
            b3 = false;

        if (b1 && b2 && b3)
            return true;
        else
            return false;
    }

    bool CBT(struct Node *tree)
    {
        queue<struct Node *> qt;

        struct Node *temp = tree;

        while (temp)
        {
            qt.push(temp->left);
            qt.push(temp->right);

            temp = qt.front();
            qt.pop();
        }

        int cnt = 0;
        while (!qt.empty())
        {
            if (qt.front() != NULL)
                cnt++;

            qt.pop();
        }

        if (cnt == 0)
            return true;
        else
            return false;
    }

    bool isHeap(struct Node *tree)
    {
        // code here
        bool b1 = solve(tree);
        bool b2 = CBT(tree);

        return b1 && b2;
    }
};