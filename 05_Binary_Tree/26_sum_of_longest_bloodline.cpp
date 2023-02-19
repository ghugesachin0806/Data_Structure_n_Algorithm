// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include <bits/stdc++.h>
using namespace std;

// structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void solve(Node *root, int sum, int level, int &max_sum, int &max_level)
    {
        if (root == NULL)
        {
            if (level > max_level)
            {
                max_level = level;
                max_sum = sum;
            }

            else if (level == max_level)
            {
                max_sum = max(sum, max_sum);
            }
            return;
        }

        sum = sum + root->data;

        solve(root->left, sum, level + 1, max_sum, max_level);
        solve(root->right, sum, level + 1, max_sum, max_level);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        // code here
        int sum = 0;
        int max_sum = INT_MIN;
        int level = 0;
        int max_level = 0;

        solve(root, sum, level, max_sum, max_level);

        return max_sum;
    }
};

// Time complexity-----------> O(N)
// Space complexity ---------->O(Height of the tree)