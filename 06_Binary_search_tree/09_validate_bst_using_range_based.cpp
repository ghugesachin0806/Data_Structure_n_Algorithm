// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool range_based(TreeNode *root, long long int max, long long int min)
    {
        if (root == NULL)
            return true;

        if (root->val > min && root->val < max)
        {

            bool b1 = range_based(root->left, root->val, min);
            bool b2 = range_based(root->right, max, root->val);

            return b1 && b2;
        }
        else
            return false;
    }

    bool isValidBST(TreeNode *root)
    {
        return range_based(root, LONG_LONG_MAX, LONG_LONG_MIN);
    }
};
