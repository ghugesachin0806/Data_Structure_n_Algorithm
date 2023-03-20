// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    bool target(vector<int> vect, int target)
    {
        int start = 0;
        int end = vect.size() - 1;

        while (start < end)
        {
            if (vect[start] + vect[end] == target)
                return true;

            if (vect[start] + vect[end] < target)
                start++;
            else
                end--;
        }

        return false;
    }
    void Inordered(TreeNode *root, vector<int> &vect)
    {
        if (root == NULL)
            return;

        Inordered(root->left, vect);
        vect.push_back(root->val);
        Inordered(root->right, vect);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> vect;

        Inordered(root, vect);

        return target(vect, k);
    }
};