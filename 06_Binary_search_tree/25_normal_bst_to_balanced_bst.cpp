// https://leetcode.com/problems/balance-a-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void Inordered(TreeNode *root, vector<TreeNode *> &vect)
    {
        if (root == NULL)
            return;

        Inordered(root->left, vect);
        vect.push_back(root);
        Inordered(root->right, vect);
    }

    TreeNode *solve(TreeNode *root, vector<TreeNode *> &vect, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = (start + end) - (start + end) / 2;

        vect[mid]->left = solve(vect[mid]->left, vect, start, mid - 1);
        vect[mid]->right = solve(vect[mid]->right, vect, mid + 1, end);

        return vect[mid];
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<TreeNode *> vect;
        Inordered(root, vect);

        int start = 0;
        int end = vect.size() - 1;
        return solve(root, vect, start, end);
    }
};