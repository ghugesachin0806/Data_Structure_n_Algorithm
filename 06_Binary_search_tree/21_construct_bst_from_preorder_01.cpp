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
    int index(int m, vector<int> &Inor, int start, int end)
    {
        int mid = (start + end) - (start + end) / 2;

        if (Inor[mid] == m)
            return mid;

        if (Inor[mid] > m)
            return index(m, Inor, start, mid - 1);

        else
            return index(m, Inor, mid + 1, end);
    }

    TreeNode *solve(vector<int> &preor, vector<int> &Inor, int start, int end, int &i)
    {
        if (start > end || i >= preor.size())
        {
            i--;
            return NULL;
        }

        int mid = index(preor[i], Inor, start, end);

        TreeNode *temp = new TreeNode(preor[i]);

        temp->left = solve(preor, Inor, start, mid - 1, ++i);
        temp->right = solve(preor, Inor, mid + 1, end, ++i);

        return temp;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> Inordered = preorder;
        sort(Inordered.begin(), Inordered.end());

        int i = 0;
        int start = 0;
        int end = preorder.size()-1;
        return solve(preorder, Inordered, start, end, i);
    }
};