// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->val > p->val && root->val > q->val)
        {
            return solve(root->left, p, q);
        }

        else if (root->val < p->val && root->val < q->val)
        {
            return solve(root->right, p, q);
        }

        else
            return root;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return solve(root, p, q);
    }
};