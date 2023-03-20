// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode *solve(vector<int> &preorder, int max, int min, int &i)
    {
        if (i >= preorder.size() || preorder[i] > max || preorder[i] < min)
        {
            i--;
            return NULL;
        }

        TreeNode *temp = new TreeNode(preorder[i]);

        temp->left = solve(preorder, preorder[i], min, ++i);
        temp->right = solve(preorder, max, preorder[i], ++i);

        return temp;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return solve(preorder, INT_MAX, INT_MIN, i);
    }
};