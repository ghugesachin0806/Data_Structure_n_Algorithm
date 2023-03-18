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
    void Inordered(vector<int> &vect, TreeNode *root)
    {
        if (root == NULL)
            return;

        Inordered(vect, root->left);
        vect.push_back(root->val);
        Inordered(vect, root->right);
    }

    bool solve(TreeNode *root)
    {
        vector<int> vect;

        Inordered(vect, root);

        for (int i = 1; i < vect.size(); i++)
        {
            if (vect[i - 1] >= vect[i])
                return false;
        }

        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        // code here
        return solve(root);
    }
};