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
    int countNodes(struct Node *root)
    {
        if (root == NULL)
            return 0;

        int ans = 1 + countNodes(root->left) + countNodes(root->right);

        return ans;
    }

    bool CBT(struct Node *tree, int index, int cnt)
    {
        if (tree == NULL)
            return true;

        if (index >= cnt)
            return false;

        bool b1 = CBT(tree->left, 2 * index + 1, cnt);
        bool b2 = CBT(tree->right, 2 * index + 2, cnt);

        return b1 && b2;
    }

    // This function only calles when it is complete binary tree
    bool solve(struct Node *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;

        if (root->right == NULL)
        {
            return (root->data > root->left->data);
        }

        bool b1 = solve(root->left);
        bool b2 = solve(root->right);
        bool b3 = (root->data > root->left->data && root->data > root->right->data);

        return b1 && b2 && b3;
    }

    // for checking max element and their childs
    bool isHeap(struct Node *tree)
    {
        // code here
        int cnt = countNodes(tree);
        int index = 0;

        return CBT(tree, index, cnt) && solve(tree);
    }
};